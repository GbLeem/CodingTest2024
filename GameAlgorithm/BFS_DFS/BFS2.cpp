#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int board[502][502] =
{ {1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} };

bool vis[502][502];
int n = 7, m = 10;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<pair<int, int>> Q;
	vis[0][0] = 1;
	Q.push({ 0,0 });

	while (!Q.empty())
	{
		pair<int, int> cur = Q.front();
		Q.pop();
		cout << '(' << cur.first << ", " << cur.second << ") -> ";
		
		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) //외부로 나감
				continue;
			if (vis[nx][ny] || board[nx][ny] != 1) //방문 했거나 벽인 경우
				continue;
			vis[nx][ny] = 1;
			Q.push({ nx, ny });
		}
	}
}