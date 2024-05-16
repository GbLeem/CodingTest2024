#include <iostream>
using namespace std;

int n;
int board[305];
int d[305][305];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> board[i];

	d[1][1] = board[1];
	d[1][2] = 0;
	d[2][1] = board[2];
	d[2][2] = board[1] + board[2];

	for (int i = 3; i <= n; ++i)
	{
		d[i][1] = max(d[i - 2][2], d[i - 2][1]) + board[i];
		d[i][2] = d[i - 1][1] + board[i];
	}
	cout << max(d[n][1], d[n][2]);
}