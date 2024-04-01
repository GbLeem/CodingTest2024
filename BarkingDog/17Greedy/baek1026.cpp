#include<iostream>
#include <algorithm>
using namespace std;

int a[102];
int b[102];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
		cin >> b[i];

	sort(a, a + n); //0 1 1 1 6
	sort(b, b + n, greater<int>()); //8 7 3 2 1

	int ans = 0;
	for (int i = 0; i < n; ++i)
		ans += a[i] * b[i];
	cout << ans;
}