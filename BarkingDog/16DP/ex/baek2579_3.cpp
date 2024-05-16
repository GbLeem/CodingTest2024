#include <iostream>
using namespace std;

int n;
int board[305];
int d[305];
int sum = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> board[i];
		sum += board[i];
	}
	if (n <= 2)
	{
		cout << sum;
		return 0;
	}

	d[1] = board[1];
	d[2] = board[2];
	d[3] = board[3];	
	
	for (int i = 4; i <= n; ++i)
	{
		d[i] = min(d[i - 2], d[i - 3]) + board[i];
	}

	cout << sum - min(d[n - 1], d[n - 2]);
}