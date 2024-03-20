#include <iostream>
#include <algorithm>
using namespace std;

int n;
int d[100002];
int a[100002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
	d[0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		d[i] = max(0, d[i - 1]) + a[i];
	}
	cout << *max_element(d + 1, d + n + 1);
}