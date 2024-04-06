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
	int sum = 0;

	for (int st = 0; st < n; ++st)
	{
		while (st < en)
		{
			en++;

			sum += a[en];
		}
	}
}