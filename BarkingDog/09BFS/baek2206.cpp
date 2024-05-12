#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n, m;
string board[1005];
int vis[1005][1005][2];
int dx[4] = { 0,1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m; //세로 가로

	for (int i = 0; i < n; ++i)
		cin >> board[i];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			vis[i][j][0] = -1;
			vis[i][j][1] = -1;
		}
	}

	queue<tuple<int, int, int>> Q;
	Q.push({ 0, 0, 0 });
	vis[0][0][0] = 1;
	vis[0][0][1] = 1;

	while (!Q.empty())
	{
		int x, y, broken;
		tie(x, y, broken) = Q.front();
		if (x == n - 1 && y == m - 1)
		{
			cout << vis[n - 1][m - 1][broken];
			return 0;
		}
		Q.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;

			if (board[nx][ny] == '0' && vis[nx][ny][broken] == -1)
			{
				Q.push({ nx,ny,broken });
				vis[nx][ny][broken] = vis[x][y][broken] + 1;
			}

			if (!broken && vis[nx][ny][broken] == -1 && board[nx][ny] == '1') //벽일 때
			{
				Q.push({ nx, ny, 1 });
				vis[nx][ny][1] = vis[x][y][broken] + 1;
			}
		}
	}
	cout << -1;
}