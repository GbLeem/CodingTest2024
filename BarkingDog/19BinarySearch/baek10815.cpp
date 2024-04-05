#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a[500005];
int b[500005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	cin >> m;
	for (int i = 0; i < m ; ++i)
		cin >> b[i];

	sort(a, a + n);

	for (int i = 0; i < m; ++i)
	{
		if (binary_search(a, a + n, b[i]))
			cout << 1 << " ";
		else
			cout << 0 << " ";		
	}
}