#include <iostream>
#include <queue>
using namespace std;

int r, c; //행 열
string board[1005];

int dist1[1005][1005];
int dist2[1005][1005];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;

	for (int i = 0; i < r; ++i)
	{		
		cin >> board[i];
	}
	for (int i = 0; i < r; ++i)
	{
		fill(dist1[i], dist1[i] + c, -1);
		fill(dist2[i], dist2[i] + c, -1);
	}
	queue<pair<int, int>> Q1; //지훈
	queue<pair<int, int>> Q2; //블

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (board[i][j] == 'J')
			{
				Q1.push({ i,j });
				dist1[i][j] = 0;
			}				
			if (board[i][j] == 'F')
			{
				Q2.push({ i,j });
				dist2[i][j] = 0;
			}
		}
	}

	//불 먼저
	while (!Q2.empty())
	{
		auto cur = Q2.front();
		Q2.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= r || ny < 0 || ny >= c)
				continue;
			if (board[nx][ny] == '#' || dist2[nx][ny] >= 0)
				continue;
			dist2[nx][ny] = dist2[cur.first][cur.second] + 1;
			Q2.push({ nx,ny });
		}
	}
	//지훈
	while (!Q1.empty())
	{
		auto cur = Q1.front();
		Q1.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= r || ny < 0 || ny >= c)
			{
				cout << dist1[cur.first][cur.second] + 1;
				return 0;
			}
			if (board[nx][ny] == '#' || dist1[nx][ny] >= 0)
				continue;
			if (dist2[nx][ny] != -1 && dist2[nx][ny] <= dist1[cur.first][cur.second] + 1)
				continue;
			dist1[nx][ny] = dist1[cur.first][cur.second] + 1;
			Q1.push({ nx,ny });
		}
	}
	cout << "IMPOSSIBLE";
}