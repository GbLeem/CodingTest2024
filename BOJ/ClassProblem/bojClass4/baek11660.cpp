#include <iostream>
using namespace std;

int n, m;
int board[2000][2000];
int d[2000][2000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> board[i][j];
		}
	}

	d[1][1] = board[0][0];

	for (int i = 2; i <= n; ++i)
	{
		d[1][i] = d[1][i - 1] + board[0][i - 1];
	}
	for (int i = 2; i <= n; ++i)
	{
		d[i][1] = d[i - 1][1] + board[i - 1][0];
	}
	//d[1][2] = board[0][0] + board[0][1]; //d[1][1] + board[0][1]; 
	//d[1][3] = board[0][0] + board[0][1] + board[0][2]; // d[1][2] + board[0][2];

	//d[2][1] = board[0][0] + board[1][0];
	//d[2][2] = board[0][0] + board[1][0] + board[0][1] + board[1][1]; //d[1][2] + d[2][1] - d[1][1] + board[1][1];
	//d[2][3] = board[0][0] + board[0][1] + board[0][2] + board[1][0] + board[1][1] + board[1][2];
	//		= d[1][3] + d[2][2] - d[1][2] + board[1][2];

	for (int i = 2; i <= n; ++i)
	{
		for (int j = 2; j <= n; ++j)
		{
			d[i][j] = d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1] + board[i - 1][j - 1];
		}
	}

	for (int i = 0; i < m; ++i)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int tempX = x2 - x1 + 1;
		int tempY = y2 - y1 + 1;
		cout << d[x2][y2] - d[x2 - tempX][y2] - d[x2][y2 - tempY] + d[x2 - tempX][y2 - tempY] << "\n";
	}
}