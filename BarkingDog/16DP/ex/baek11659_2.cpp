#include <iostream>
using namespace std;

int n, m;
int board[100005];
int d[100005];

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
		int a, b;
		cin >> a >> b;

		cout << d[b] - d[a - 1] << "\n";
	}
}