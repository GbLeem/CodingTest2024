//최적화 문제 : n개를 만들 수 있는 랜선의 최대 길이
//결정 문제 : 랜선의 길이가 x일때 랜선이 n개 이상인가 아닌가


//Parametric search!
//최대, 최소 키워드 & 범위가 클때
#include <iostream>
#include <algorithm>
using namespace std;

int k, n;
int a[10005];

bool solve(long long x)
{
	long long cur = 0;

	for (int i = 0; i < k; ++i)
		cur += a[i] / x;

	return cur >= n;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> n;

	for (int i = 0; i < k; ++i)
		cin >> a[i];

	long long st = 1;
	long long en = 0x7fffffff;

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