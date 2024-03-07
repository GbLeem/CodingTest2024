#include <iostream>
#include <queue>
using namespace std;

int board[102][102];
int dist[102][102];
int N;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> board[i][j];
		}
	}
	queue<pair<int, int>> Q;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (board[i][j] == 0)
				Q.push({ i,j });
		}
	}
}