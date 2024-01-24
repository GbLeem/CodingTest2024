//토마토 - 시작점이 여러개일 때

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int board[1002][1002];
int dist[1002][1002];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int N, M;
int date = 0;

//1 익은
//0 안익은
//-1 빈

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N;
	queue<pair<int, int>> Q;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> board[i][j];

			if (board[i][j] == 1) //익은 토마토 - 시작점으로 가능			
				Q.push({ i, j });
			
			if (board[i][j] == 0) //안익은 토마토 
				dist[i][j] = -1;			
		}
	}
	
	while (!Q.empty())
	{
		pair<int, int> cur = Q.front();
		Q.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (board[nx][ny] == -1 || dist[nx][ny] >= 0)
				continue;

			dist[nx][ny] = dist[cur.first][cur.second] + 1;
			Q.push({ nx, ny });
		}
	}
	int ans = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (dist[i][j] == -1)
			{
				cout << -1;
				return 0;
			}
			ans = max(ans, dist[i][j]);
		}
	}
	cout << ans;
}