//가장 긴 막대 찾기
//막대가 x일때 m명한테 나눠줄 수 있는가

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
		cur += a[i] / x;
	}
	return cur >= m;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n; //조카, 과자

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	int st = 0;
	int en = 1'000'000'000;

	while (st < en)
	{
		long long mid = (st + en + 1) / 2;

		if (solve(mid))
		{
			st = mid;
		}
		else
			en = mid - 1;		
	}
	cout << st;
}