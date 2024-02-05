#include <iostream>
#include <vector>
#include <queue>

using namespace std;

string board[102];
int dist[102][102];
int N, M;// 세로 가로
int dx[4] = { 1,0,-1,0 }; //하 우 상 좌
int dy[4] = { 0,1,0,-1 }; 


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; ++i) //세로
	{
		cin >> board[i];
	}
	for (int i = 0; i < N; ++i)
		fill(dist[i], dist[i] + M, -1);
	queue<pair<int, int>> Q;

	Q.push({ 0,0 }); //시작점 0,0
	dist[0][0] = 0; //거리 0으로 시작

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
			if (dist[nx][ny] >= 0 || board[nx][ny] != '1')
				continue;
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
			Q.push({ nx,ny });
		}
	}
	cout << dist[N - 1][M - 1] + 1;
}
