//¹Ì·Î Å½»ö - °Å¸® Ã£±â ¹®Á¦

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

string board[102];
<<<<<<< HEAD
int dist[102][102];
int N, M;// ì„¸ë¡œ ê°€ë¡œ
int dx[4] = { 1,0,-1,0 }; //í•˜ ìš° ìƒ ì¢Œ
int dy[4] = { 0,1,0,-1 }; 


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; ++i) //ì„¸ë¡œ
	{
		cin >> board[i];
	}
	for (int i = 0; i < N; ++i)
		fill(dist[i], dist[i] + M, -1);
	queue<pair<int, int>> Q;

	Q.push({ 0,0 }); //ì‹œì‘ì  0,0
	dist[0][0] = 0; //ê±°ë¦¬ 0ìœ¼ë¡œ ì‹œì‘

	while (!Q.empty())
	{
		pair<int, int> cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (dist[nx][ny] >= 0 || board[nx][ny] != '1')
				continue;
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
			Q.push({ nx,ny });
		}
	}
	cout << dist[N - 1][M - 1] + 1;
=======
int dist[502][502] = { -1, };
int dx[4] = { 1, 0 ,-1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, M;// ¼¼·Î °¡·Î

//1ÀÌ ÀÌµ¿ÇÒ ¼ö ÀÖ´Â Ä­, (1,1) ¿¡¼­ ½ÃÀÛ

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M; //4 6

	for (int i = 0; i < N; ++i)
	{
		cin >> board[i];
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			dist[i][j] = -1;
		}
	}
	queue<pair<int, int>> Q;
	
	dist[0][0] = 0; //¹æ¹®ÇÏ¸é °Å¸® 0À¸·Î ¿Ã·ÁÁÖ±â
	Q.push({ 0, 0 });

	while (!Q.empty())
	{
		pair<int, int> cur = Q.front();
		Q.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (board[nx][ny] != '1' || dist[nx][ny] >= 0)
				continue;

			dist[nx][ny] = dist[cur.first][cur.second] + 1;
			Q.push({ nx, ny });
		}
	}
	cout << dist[N-1][M-1] + 1;
>>>>>>> 6f34ef2bbf800d67aca61e05bb1784918f1d5ff9
}
