// x미터로 자르면 n미터가 되는가
#include <iostream>
#include <algorithm>
using namespace std;

int m, n;
int a[1000005];

bool solve(long long x)
{
	long long cur = 0;

	for (int i = 0; i < n; ++i)
	{
		if (a[i] <= x) //음수
			continue;
		cur += (a[i] - x);
	}
	return cur >= m;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m; //갯수 길이
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	long long st = 0;
	long long en = *max_element(a, a + n);

	while (st < en)
	{
		long long mid = (st + en + 1) / 2;

		if (solve(mid))
			st = mid;
		else
			en = mid - 1;
	}
	cout << st;
}