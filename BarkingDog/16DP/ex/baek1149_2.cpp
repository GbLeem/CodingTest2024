#include <iostream>
#include <algorithm>
using namespace std;

int n;
int board[1005][3];
int d[1005][3];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < 3; ++j)
			cin >> board[i][j]; //0 1 2 : r g b
	}
	d[1][0] = board[1][0];
	d[1][1] = board[1][1];
	d[1][2] = board[1][2];


	for (int i = 2; i <= n; ++i)
	{
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + board[i][0];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + board[i][1];
		d[i][2] = min(d[i - 1][1], d[i - 1][0]) + board[i][2];
	}

	cout << *min_element(d[n], d[n] + 3);
}