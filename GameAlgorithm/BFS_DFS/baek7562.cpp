// measure distance
#include <iostream>
#include <queue>
using namespace std;

int T, I; // test case, size
int board[301][301];
int dx[8] = { 2, 2, 1, -1, -2, -2, -1, 1};
int dy[8] = { 1, -1, -2, -2, -1, 1, 2, 2 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	while (T--)
	{
		int x1, y1, x2, y2; //start, end
		cin >> I;
		cin >> x1 >> y1;
		cin >> x2 >> y2;
		
		for (int i = 0; i < I; ++i)
			fill(board[i], board[i] + I, -1);
		board[x1][y1] = 0; //start
		
		queue<pair<int, int>> Q;
		Q.push({ x1, y1 });

		while (!Q.empty())
		{
			auto cur = Q.front();
			Q.pop();

			for (int dir = 0; dir < 8; ++dir)
			{
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];
				
				if (nx < 0 || nx >= I || ny < 0 || ny >= I) //out of range
					continue;				
				if (board[nx][ny] >= 0) //visited
					continue;

				board[nx][ny] = board[cur.first][cur.second] + 1;
				Q.push({ nx,ny });
			}
		}
		cout << board[x2][y2] << "\n";			
	}
	return 0;
}
