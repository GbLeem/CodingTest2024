#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int a[1000005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	int en = 0;
	int ans = 0;
	int odd = 0;
	if (a[0] % 2 != 0)
		odd++;
	for (int st = 0; st < n; ++st)
	{
		while (en < n - 1 && odd + a[en + 1]%2 <=k)
		{
			en++;
			odd += a[en] % 2;
		}
		ans = max(ans, en - st + 1 - odd);
		odd -= a[st] % 2;
	}
	cout << ans;
}