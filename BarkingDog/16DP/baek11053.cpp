#include <iostream>
#include <algorithm>
using namespace std;

int n;
int d[1002];
int a[1002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i]; // 10 20 10 30 20 50	
		d[i] = 1;
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			if (a[j] < a[i])
			{
				d[i] = max(d[j]+1, d[i]);
			}
		}
	}
	cout << *max_element(d + 1, d + n + 1);
}