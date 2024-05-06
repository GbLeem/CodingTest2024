//이중 for문 O(N^2)에 처리되는 작업을 두개의 포인터로 O(N)에 해결하기

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m;
int ans = 0x7fffffff;
int a[100002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	sort(a, a + n);

	int en = 0;
	for (int st = 0; st < n; ++st)
	{
		while (en < n && a[en] - a[st] < m)
			en++;
		if (en == n)
			break;
		ans = min(ans, a[en] - a[st]);
	}
	cout << ans;
}