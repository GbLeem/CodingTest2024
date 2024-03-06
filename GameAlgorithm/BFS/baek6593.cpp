#include <iostream>
#include <string>
#include <tuple>
#include <queue>
using namespace std;

int dx[6] = { 1, 0, -1, 0, 0, 0 };
int dy[6] = { 0, 1, 0, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0 , -1, 1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int L, R, C;

	while (1)
	{
		cin >> L >> R >> C; //층 행 열

		if (L == 0 && R == 0 && C == 0)
			break;

		string board[32][32];
		int vis[32][32][32];

		for (int i = 0; i < L; ++i)
			for (int j = 0; j < R; ++j)
				fill(vis[i][j], vis[i][j] + C, 0);

		for (int i = 0; i < L; ++i)
			for (int j = 0; j < R; ++j)
				cin >> board[i][j];

		queue<tuple<int, int, int>> Q;

		for (int i = 0; i < L; ++i)
		{
			for (int j = 0; j < R; ++j)
			{
				for (int k = 0; k < C; ++k)
				{
					if (board[i][j][k] == 'S') // 시작점
					{
						Q.push({ i,j,k });
						vis[i][j][k] = 0;
					}
					else if (board[i][j][k] == '.') //갈 수 있는 곳
						vis[i][j][k] = -1;
				}
			}
		}

		bool find = false;

		while (!Q.empty())
		{
			auto cur = Q.front();
			Q.pop();

			for (int dir = 0; dir < 6; ++dir)
			{
				int nz = get<0>(cur) + dz[dir];
				int nx = get<1>(cur) + dx[dir];
				int ny = get<2>(cur) + dy[dir];

				if (nx < 0 || nx >= R || ny < 0 || ny >= C || nz < 0 || nz >= L)
					continue;
				if (board[nz][nx][ny] == '#' || vis[nz][nx][ny] > 0)
					continue;
				
				vis[nz][nx][ny] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;

				if (board[nz][nx][ny] == 'E')
				{
					cout << "Escaped in " << vis[nz][nx][ny] << " minute(s).\n";
					find = true;
					break;
				}
				Q.push({ nz,nx,ny });
			}
		}
		if (!find)
			cout << "Trapped!\n";
	}
}