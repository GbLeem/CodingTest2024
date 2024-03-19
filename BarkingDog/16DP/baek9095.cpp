#include <iostream>
using namespace std;

int d[20];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		fill(d, d + n, 0);

		d[1] = 1;
		d[2] = 2;
		d[3] = 4;

		for (int i = 4; i <= n; ++i)
		{
			d[i] = d[i - 1] + d[i - 2] + d[i - 3];
 		}
		cout << d[n] << "\n";
	}
}