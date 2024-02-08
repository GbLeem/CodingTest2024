#include <iostream>
#include <queue>
#include <string>
using namespace std;

int T;
int w, h;//width, height 
string board[1002];
int dist[1002][1002];
int dist_fire[1002][1002];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	while (T--)
	{
		cin >> w >> h; // 가 ??
		
		for (int i = 0; i < h; ++i)
		{
			cin >> board[i];
			fill(dist[i], dist[i] + w, -1);
			fill(dist_fire[i], dist_fire[i] + w, -1);
		}
		queue<pair<int, int>> Q_fire;
		queue<pair<int, int>> Q;
		bool end = false;

		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				if (board[i][j] == '@') //sang
				{
					dist[i][j] = 0;
					Q.push({ i,j });
				}
				if (board[i][j] == '*') //fire
				{
					dist_fire[i][j] = 0;
					Q_fire.push({ i,j });			
				}
			}
		}
		while (!Q_fire.empty())
		{
			auto cur = Q_fire.front();
			Q_fire.pop();

			for (int dir = 0; dir < 4; ++dir)
			{
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];

				if (nx < 0 || nx >= h || ny < 0 || ny >= w)
					continue;
				if (board[nx][ny] == '#' || dist_fire[nx][ny] >= 0)
					continue;

				Q_fire.push({ nx, ny });
				dist_fire[nx][ny] = dist_fire[cur.first][cur.second] + 1;
			}
		}

		while (!(Q.empty()) && !(end))
		{
			auto cur = Q.front();
			Q.pop();

			for (int dir = 0; dir < 4; ++dir)
			{
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];

				if (nx < 0 || nx >= h || ny < 0 || ny >= w)
				{
					cout << dist[cur.first][cur.second] + 1 << "\n";
					end = true;
					break;
				}
				if (board[nx][ny] == '#' || dist[nx][ny] >= 0)
					continue;			
				//no fire && fire spreads time <= sang gun's escape time + 1
				if (dist_fire[nx][ny] != -1 && dist_fire[nx][ny] <= dist[cur.first][cur.second] + 1)
					continue;

				Q.push({ nx, ny });
				dist[nx][ny] = dist[cur.first][cur.second] + 1;
			}
		}
		if(!end)
			cout << "IMPOSSIBLE" << "\n";
	}
}