#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int board[102][102][102];
int date[102][102][102] = { 0, };
int M, N, H; //가로 세로 높이
int dx[6] = { 1, 0, -1, 0, 0, 0 };
int dy[6] = { 0, 1, 0, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0 , -1, 1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N >> H;

	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			for (int k = 0; k < M; ++k)
			{
				cin >> board[i][j][k];
			}
		}
	}
	queue<tuple<int, int, int>>Q;
	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			for (int k = 0; k < M; ++k)
			{
				if (board[i][j][k] == 1)
					Q.push({ i,j,k });
				if (board[i][j][k] == 0)
					date[i][j][k] = -1;
			}
		}
	}
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();

		for (int dir = 0; dir < 6; ++dir)
		{
			int nz = get<0>(cur) + dz[dir];
			int nx = get<1>(cur) + dx[dir];
			int ny = get<2>(cur) + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H)
				continue;
			if (board[nz][nx][ny] == -1 || date[nz][nx][ny] >= 0)
				continue;

			Q.push({ nz, nx, ny });
			date[nz][nx][ny] = date[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
		}
	}
	int answer = 0;
	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			for (int k = 0; k < M; ++k)
			{
				if (date[i][j][k] == -1)
				{
					cout << -1;
					return 0;
				}
				else
					answer = max(answer, date[i][j][k]);

			}
		}
	}
	cout << answer;
}