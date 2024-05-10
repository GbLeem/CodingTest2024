#include <iostream>
#include <queue>

using namespace std;

int n, m; //세로 가로
string board[105];
int vis[105][105];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m; //세로 가로
	
	for (int i = 0; i < n; ++i)
		cin >> board[i];
	
	for (int i = 0; i < n; ++i)
		fill(vis[i], vis[i] + m, -1);

	vis[0][0] = 1;
	queue<pair<int, int>> Q;
	Q.push({ 0,0 }); //시작점

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
			if (vis[nx][ny] >= 0 || board[nx][ny] == '0') //이미 간곳이거나 못가는 곳이면
				continue;			

			Q.push({ nx,ny });
			vis[nx][ny] = vis[cur.first][cur.second] + 1;
		}
	}
	cout << vis[n - 1][m - 1];
}