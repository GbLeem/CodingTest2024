#include <iostream>
using namespace std;

int n, m;
int board[100'002];
int d[100'002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	d[0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		cin >> board[i];
		d[i] = d[i - 1] + board[i];
	}
	while (m--)
	{
		int i, j;
		cin >> i >> j;
		cout << d[j] - d[i - 1] << "\n";
	}
}