#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int board[502][502];
int vis[502][502];
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m; //세로 가로
	int x, y;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> board[i][j];
		}
	}
	int maxArea = 0;
	int num = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (vis[i][j] || board[i][j] == 0)
				continue;
			num++; // ?�작??지??찾음

			queue<pair<int, int>> Q;
			vis[i][j] = 1;
			Q.push({ i,j });

			int area = 0;
			while (!Q.empty())
			{
				area++; //?�이 측정 ?�작

				pair<int, int> cur = Q.front();
				Q.pop();
				
				for (int dir = 0; dir < 4; ++dir)
				{
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						continue;
					if (board[nx][ny] != 1 || vis[nx][ny]) //방문 ?�거??벽일??
						continue;

					vis[nx][ny] = 1;
					Q.push({ nx,ny });					
				}
			}
			maxArea = max(maxArea, area);
		}
	}
		
	cout << num << "\n" << maxArea;
}