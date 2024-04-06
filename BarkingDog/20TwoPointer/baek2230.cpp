//<이분탐색 풀이>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a[100002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	sort(a, a + n);
	
	long long minVal = 2e9;

	for (int i = 0; i < n; ++i)
	{
		if (lower_bound(a, a + n, a[i] + m) - a != n) //없는 경우 아니면
		{
			if (minVal > a[lower_bound(a, a + n, a[i] + m) - a] - a[i])
				minVal = a[lower_bound(a, a + n, a[i] + m) - a] - a[i];
		}
	}
	cout << minVal;
}