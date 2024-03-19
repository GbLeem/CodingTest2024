#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int board[102][102];
bool vis[102][102];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> board[i][j];
		}
	}
	
	vector<int> vec;
	for (int rain = 0; rain <= 100; ++rain)
	{		
		int num = 0;
		for (int i = 0; i < N; ++i)
		{
			fill(vis[i], vis[i] + N, 0);
		}
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (vis[i][j] == 1 || board[i][j] <= rain) //못가는 곳
					continue;
				num++;

				queue<pair<int, int>> Q;

				vis[i][j] = 1;
				Q.push({ i, j });

				while (!Q.empty())
				{
					auto cur = Q.front();
					Q.pop();

					for (int dir = 0; dir < 4; ++dir)
					{
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];

						if (nx < 0 || nx >= N || ny < 0 || ny >= N)
							continue;
						if (vis[nx][ny] == 1 || board[nx][ny] <= rain)
							continue;

						vis[nx][ny] = 1;
						Q.push({ nx, ny });
					}
				}
			}
		}
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());
	cout << vec.back();
}