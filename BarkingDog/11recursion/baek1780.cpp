#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int table[2002][2002];
int cnt[3];

bool check(int x, int y, int n)
{
	for (int i = x; i < x + n; ++i)
	{
		for (int j = y; j < y + n; ++j)
		{
			if (table[i][j] != table[x][y])
				return false;
		}
	}
	return true;
}

void func(int x, int y, int z)
{
	if (check(x, y, z))
	{
		cnt[table[x][y] + 1] += 1;
		return;
	}

	int n = z / 3;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			func(x + i * n, y + j * n, n);
		}
	}
}

//int 범위 : 2^63 -1
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j <N; ++j)
		{
			cin >> table[i][j];
		}
	}
	func(0, 0, N);

	for (int i = 0; i < 3; ++i)
		cout << cnt[i] << "\n";

	return 0;
}