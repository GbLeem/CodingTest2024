#include <iostream>
using namespace std;

string board[100];
int n;

bool check(int x, int y, int size)
{
	char tempValue = board[x][y];

	for (int i = x; i < x + size; ++i)
	{
		for (int j = y; j < y + size; ++j)
		{
			if (board[i][j] != tempValue)
				return false;
		}
	}
	cout << tempValue;
	return true;
}

void compress(int x, int y, int size)
{
	if (!check(x, y, size))
	{
		cout << '(';
		compress(x, y, size / 2);
		compress(x, y + size / 2, size / 2);
		compress(x + size / 2, y, size / 2);
		compress(x + size / 2, y + size / 2, size / 2);
		cout << ')';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> board[i];
	}

	compress(0, 0, n);
}
