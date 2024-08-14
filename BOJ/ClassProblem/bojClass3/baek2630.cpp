//쿼드 트리
#include <iostream>
using namespace std;

int board[128][128];
int blue = 0;
int white = 0;
bool check(int x, int y, int size)
{
	int temp = board[x][y];

	for (int i = x; i < x + size; ++i)
	{
		for (int j = y; j < y + size; ++j)
		{
			if (board[i][j] != temp)
				return false;
		}
	}
	if (temp == 1)
		blue++;
	if (temp == 0)
		white++;
	return true;
}

void compress(int x, int y, int size)
{
	if (!check(x, y, size))
	{
		compress(x, y, size / 2);
		compress(x, y + size / 2, size / 2);
		compress(x + size / 2, y, size / 2);
		compress(x + size / 2, y + size / 2, size / 2);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cin >> board[i][j];
	}
	compress(0, 0, n);
	
	cout << white << "\n" << blue;
}