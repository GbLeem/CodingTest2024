//여러개의 시작점

#include <iostream>
#include <queue>
using namespace std;

int T, M, N, K; //테케, 가로, 세로, 갯수
int board[51][51];
int vis[51][51];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	
	while (T--)
	{
		cin >> M >> N >> K;
		
		int x, y;
		while (K--)
		{
			cin >> x >> y; //가로 세로
			board[y][x] = 1;		
		}

		queue<pair<int, int>> Q;
		int worm = 0;

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (board[i][j] == 1 && vis[i][j] == 0) //양배추이지만 안 본곳
				{
					worm++;

					vis[i][j] = 1;
					Q.push({ i,j });

					while (!Q.empty())
					{
						auto cur = Q.front();
						Q.pop();

						for (int dir = 0; dir < 4; ++dir)
						{
							int nx = cur.first + dx[dir];
							int ny = cur.second + dy[dir];

							if (nx < 0 || nx >= N || ny < 0 || ny >= M)
								continue;
							if (vis[nx][ny] == 1 || board[nx][ny] == 0)
								continue;

							vis[nx][ny] = 1;
							Q.push({ nx,ny });
						}
					}
				}
			}
		}	
		cout << worm << "\n";

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				board[i][j] = 0;
				vis[i][j] = 0;
			}
		}
	}
	return 0;
}