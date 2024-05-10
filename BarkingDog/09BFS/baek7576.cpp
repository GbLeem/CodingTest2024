#include <iostream>
#include <queue>
using namespace std;

int n, m;
int board[1005][1005];
int vis[1005][1005];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int ans = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;

	queue<pair<int, int>> Q;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> board[i][j];
			
			if (board[i][j] == 1)			
				Q.push({ i,j });
			if (board[i][j] == 0)
				vis[i][j] = -1;
			
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
			if (vis[nx][ny] >= 0)
				continue;			
			Q.push({ nx,ny });
			vis[nx][ny] = vis[cur.first][cur.second] + 1;			
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (vis[i][j] == -1) //다 못 익음
			{
				cout << -1;
				return 0;
			}
			ans = max(ans, vis[i][j]);
		}
	}


	cout << ans;
}