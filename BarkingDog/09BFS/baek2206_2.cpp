#include <iostream>
#include <queue>
using namespace std;

int n, m;
string board[1005];
int vis[1005][1005];
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
		fill(vis[i], vis[i] + m, -1);

	queue<pair<int, int>> Q;
	Q.push({ 0,0 });
	vis[0][0] = 1;

	while (!Q.empty())
	{
		auto cur = Q.front();
		bool crash = true;
	
		if (cur.first == n - 1 && cur.second == m - 1)
		{
			cout << vis[n - 1][m - 1];
			return 0;
		}
		Q.pop();		

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;

			if (board[nx][ny] == '0' && vis[nx][ny] == -1)
			{
				Q.push({ nx,ny });
				vis[nx][ny] = vis[cur.first][cur.second] + 1;
			}

			if (crash && vis[nx][ny] == -1 && board[nx][ny] == '1') //벽일 때
			{
				Q.push({ nx, ny });
				vis[nx][ny] = vis[cur.first][cur.second] + 1;
				crash = false;
			}
		}
	}
	cout << -1;
	return 0;
}