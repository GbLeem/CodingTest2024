//시작점이 여러개인 BFS

//이중 for문으로 BFS돌리면 복잡도증가 -> 모든 시작점을 처음에 다 큐에 넣어버리고 BFS 돌리기

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M; //세로 가로
int board[1002][1002];
int dist[1002][1002];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

// i = 1, 0, -1 

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

			if (board[i][j] == 1)
				Q.push({ i,j }); //익었으면
			if (board[i][j] == 0)
				dist[i][j] = -1; //안익었으면
		}
	}	
	
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (dist[nx][ny] >= 0)
				continue;

			dist[nx][ny] = dist[cur.first][cur.second] + 1;
			Q.push({ nx,ny });
		}
	}
		
	int ans = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (dist[i][j] == -1) //안익음
			{
				cout << -1;
				return 0;
			}
			ans = max(ans, dist[i][j]);
		}
	}
	cout << ans;
}