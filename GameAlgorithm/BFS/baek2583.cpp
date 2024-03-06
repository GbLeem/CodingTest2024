#include <iostream>
#include <vector>
#include <queue>
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

	int M, N, K;
	cin >> M >> N >> K; //세로 가로

	for (int i = 0; i < K; ++ i)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int i = y1; i < y2; ++i)
		{
			for (int j = x1; j < x2; ++j)
			{
				board[i][j] = 1; //벽
			}
		}
	}
	int num = 0;
	vector<int> vec;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (vis[i][j] == 1 || board[i][j] == 1) //방문 했거나 벽일때 못감
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

					if (nx < 0 || nx >= M || ny < 0 || ny >= N)
						continue;
					if (board[nx][ny] == 1 || vis[nx][ny])
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
		cout << vec[i] << " ";
}