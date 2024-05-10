#include <iostream>
#include <queue>
using namespace std;

int n, m;
int board[505][505];
int vis[505][505];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m; //세로 가로

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			cin >> board[i][j];
	}

	int num = 0;
	int size = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (board[i][j] == 1 && vis[i][j] == 0) //시작점 될 수 있음
			{
				num++;
				queue<pair<int, int>> Q;
				vis[i][j] = 1;
				Q.push({ i,j });
				
				int temp = 0;
				while (!Q.empty())
				{
					temp++;
					pair<int, int> cur = Q.front();
					Q.pop();

					for (int dir = 0; dir < 4; ++dir)
					{
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];

						if (nx < 0 || nx >= n || ny < 0 || ny >= m)
							continue;
						if (vis[nx][ny] == 1 || board[nx][ny] != 1)
							continue;

						Q.push({ nx, ny });
						vis[nx][ny] = 1;
					}
				}

				size = max(size, temp);
			}
		}
	}

	cout << num << "\n" << size << "\n";
}
