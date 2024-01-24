//미로 탐색 - 거리 찾기 문제

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

string board[102];
int dist[502][502] = { -1, };
int dx[4] = { 1, 0 ,-1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, M;// 세로 가로

//1이 이동할 수 있는 칸, (1,1) 에서 시작

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M; //4 6

	for (int i = 0; i < N; ++i)
	{
		cin >> board[i];
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			dist[i][j] = -1;
		}
	}
	queue<pair<int, int>> Q;
	
	dist[0][0] = 0; //방문하면 거리 0으로 올려주기
	Q.push({ 0, 0 });

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
			if (board[nx][ny] != '1' || dist[nx][ny] >= 0)
				continue;

			dist[nx][ny] = dist[cur.first][cur.second] + 1;
			Q.push({ nx, ny });
		}
	}
	cout << dist[N-1][M-1] + 1;
}
