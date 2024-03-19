#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

string board[30];
bool vis[30][30];
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
		cin >> board[i];
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			board[i][j] = board[i][j] - '0';
		}
	}
	int num = 0;
	vector<int> vec;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (vis[i][j] == 1 || board[i][j] == 0) //0 은 못감
				continue;
			num++;

			queue<pair<int, int>> Q;
			vis[i][j] = 1;
			Q.push({ i,j });

			int area = 0;
			while (!Q.empty())
			{
				area++;

				pair<int, int> cur = Q.front();
				Q.pop();

				for (int dir = 0; dir < 4; ++dir)
				{
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];

					if (nx < 0 || nx >= N || ny < 0 || ny >= N)
						continue;
					if (board[nx][ny] == 0 || vis[nx][ny])
						continue;

					vis[nx][ny] = 1;
					Q.push({ nx,ny });
				}
			}
			vec.push_back(area);
		}
	}
	cout << num << "\n";
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << "\n";
	}
}