#include <iostream>
using namespace std;

int n, m;
int a[10002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	int cnt = 0;
	int en = 0;
	int sum = a[0];
	bool ok = false;
	for (int st = 0; st < n; ++st)
	{
		while (en < n && sum < m)
		{
			en++;
			if (en == n)
				break;
			sum += a[en];
			if (sum == m)
			{
				ok = true;
				break;
			}
		}
		if (sum == m || ok)
		{
			cnt++;
			ok = false;
		}
		sum -= a[st];		
	}
	cout << cnt;
}