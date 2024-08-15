#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, k;//세로 가로 사각형 수
int board[102][102];
int vis[102][102];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 0; i < k; ++i)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int y = y1; y < y2; ++y)
		{
			for (int x = x1; x < x2; ++x)
			{
				board[y][x] = 1;
			}
		}		
	}
	
	queue<pair<int, int>>Q;
	vector<int> size;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			//시작점 하나 선택
			if (board[i][j] == 0 && vis[i][j] == 0)
			{
				Q.push({ i,j });
				vis[i][j] = 1;

				int temp = 1;
				while (!Q.empty())
				{
					auto cur = Q.front();
					Q.pop();

					for (auto dir = 0; dir < 4; ++dir)
					{
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];

						if (nx < 0 || nx >= n || ny < 0 || ny >= m)
							continue;
						if (board[nx][ny] == 1)
							continue;
						if (vis[nx][ny] == 1)
							continue;

						Q.push({ nx,ny });
						vis[nx][ny] = 1;
						temp++;
					}
				}
				size.push_back(temp);
			}
		}
	}

	cout << size.size() << "\n";
	sort(size.begin(), size.end());
	for (const auto& s : size)
		cout << s << " ";
}