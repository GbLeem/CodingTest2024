//bfs x 2?
#include <iostream>
#include <queue>
using namespace std;

int N;
string board[102];
int vis_normal[102][102];
int vis[102][102];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> board[i];
	}
	queue<pair<int, int>> Q;
	queue<pair<int, int>> Q2;
	queue<pair<int, int>> Q_normal;
	queue<pair<int, int>> Q2_normal;

	int num = 0;
	int num_b = 0, num_r = 0, num_g = 0;
	//normal -> bfs * 2
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (board[i][j] == 'R' && vis_normal[i][j] == 0)
			{
				Q_normal.push({ i,j });
				vis_normal[i][j] = 1;
				num_r++;

				while (!Q_normal.empty())
				{
					auto cur = Q_normal.front();
					Q_normal.pop();

					for (int dir = 0; dir < 4; ++dir)
					{
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];

						if (nx < 0 || nx >= N || ny < 0 || ny >= N)
							continue;
						if (board[nx][ny] == 'B' || board[nx][ny] == 'G' || vis_normal[nx][ny])
							continue;

						Q_normal.push({ nx, ny });
						vis_normal[nx][ny] = 1;

					}
				}
			}

			if (board[i][j] == 'G' && vis_normal[i][j] == 0)
			{
				Q2_normal.push({ i,j });
				vis_normal[i][j] = 1;
				num_g++;

				while (!Q2_normal.empty())
				{
					auto cur = Q2_normal.front();
					Q2_normal.pop();

					for (int dir = 0; dir < 4; ++dir)
					{
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];

						if (nx < 0 || nx >= N || ny < 0 || ny >= N)
							continue;
						if (board[nx][ny] == 'B' || board[nx][ny] == 'R' || vis_normal[nx][ny])
							continue;

						Q2_normal.push({ nx, ny });
						vis_normal[nx][ny] = 1;

					}
				}
			}


			if ((board[i][j] == 'R' || board[i][j] == 'G') && vis[i][j] == 0) //빨,초 and 방문 안함
			{				
				Q.push({ i, j });
				vis[i][j] = 1;	
				num++;

				//bfs 돌리기
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
						if (board[nx][ny] == 'B' || vis[nx][ny])
							continue;

						Q.push({ nx, ny });
						vis[nx][ny] = 1;
					}
				}				
			}	
			if (board[i][j] == 'B' && vis[i][j] == 0)
			{
				Q2.push({ i,j });
				vis[i][j] = 1;
				num_b++;
				while (!Q2.empty())
				{
					auto cur = Q2.front();
					Q2.pop();

					for (int dir = 0; dir < 4; ++dir)
					{
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];

						if (nx < 0 || nx >= N || ny < 0 || ny >= N)
							continue;
						if (board[nx][ny] == 'R' || board[nx][ny] == 'G' || vis[nx][ny])
							continue;

						Q2.push({ nx, ny });
						vis[nx][ny] = 1;
					}
				}
			}
		}
	}	

	cout << num_b + num_g + num_r << ' ' << num + num_b;
}