#include <iostream>
#include <algorithm>
using namespace std;

int n;
int d[502][502];
int table[502][502];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			cin >> table[i][j];
		}
	}

	d[1][1] = table[1][1];
	int index = 1;

	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + table[i][j];
		}
	}

	cout << *max_element(d[n] + 1, d[n] + n + 1);
}