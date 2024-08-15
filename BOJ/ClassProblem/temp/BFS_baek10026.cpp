#include <iostream>
#include <queue>
using namespace std;

int n;
string board[102];
int vis[102][102];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void bfs(int i, int j)
{
	queue<pair<int, int>> Q;
	Q.push({ i,j });

	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;
			//이미 방문하거나 옆이랑 색 다를때
			if (vis[nx][ny] == 1 || board[i][j] != board[nx][ny])
				continue;
			Q.push({ nx,ny });
			vis[nx][ny] = 1;
		}
	}
}

int area()
{
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (!vis[i][j])
			{
				cnt++;
				bfs(i, j);
			}
		}
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> board[i];

	int normal = area();

	for (int i = 0; i < n; ++i)
		fill(vis[i], vis[i] + n, 0);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (board[i][j] == 'G')
				board[i][j] = 'R';
		}
	}
	int color = area();

	cout << normal << " " << color << "\n";
}