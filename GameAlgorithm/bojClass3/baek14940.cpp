#include <iostream>
#include <queue>
using namespace std;

int board[1002][1002];
int dist[1002][1002];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; ++i)
		fill(dist[i], dist[i] + m, -1);

	queue<pair<int, int>> Q;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (board[i][j] == 2)
			{
				dist[i][j] = 0;
				Q.push({ i,j });
			}
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

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (board[nx][ny] == 2)
				continue;
			if (board[nx][ny] == 0 || dist[nx][ny] > 0)
				continue;

			Q.push({ nx,ny });
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (board[i][j] == 0) //땅
				cout << 0 << " ";
			else
				cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
}