#include <iostream>
using namespace std;

int t;
int d[100000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;			

		d[1] = 1;
		d[2] = 2; //d[1] +1
		d[3] = 4;

		for (int i = 4; i <= n; ++i)
		{
			d[i] = d[i - 1] + d[i - 2] + d[i - 3];
		}

		cout << d[n] << "\n";
	}
}