//bfs x 2?
#include <iostream>
#include <queue>
using namespace std;

int N;
string board[102];
int vis_normal[102][102];
int vis[102][102];

int main()
{
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> board[i];
	}
	queue<pair<int, int>> Q;
	queue<pair<int, int>> Q_normal;
	int num = 0, num_normal = 0;

	//normal -> bfs * 3?
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (board[i][j] == 'R')
			{
				Q_normal.push({ i,j });
				vis_normal[i][j] = 1;
			}
		}
	}
}