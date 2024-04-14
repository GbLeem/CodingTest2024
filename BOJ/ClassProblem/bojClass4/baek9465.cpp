#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int t;
int n;
bool top = false;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--)
	{
		cin >> n;

		vector<vector<int>> a(n, vector<int>(2));
		vector<vector<int>> d(n, vector<int>(2));
		
		for (int i = 0; i < n; ++i)
			cin >> a[i][0];
		for (int i = 0; i < n; ++i)
			cin >> a[i][1];

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < 2; ++j)
			{
				int temp = 0;
				if (i > 1)
					temp = max(d[i - 2][0], d[i - 2][1]);
				if (i > 0)
					temp = max(temp, d[i - 1][1 - j]);
				d[i][j] = temp + a[i][j];
			}
		}
		cout << max(d[n - 1][0], d[n - 1][1]) << "\n";
	}
}