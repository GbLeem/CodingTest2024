#include <iostream>
using namespace std;

int s[305];
int d[305];
int n;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int total = 0;

	for (int i = 1; i <= n; ++i)
	{
		cin >> s[i];
		total += s[i];
	}
	
	if (n == 1)
	{
		cout << s[n];
		return 0;
	}
	d[1] = s[1];
	d[2] = s[2];
	d[3] = s[3];

	for (int i = 4; i <= n - 1; ++i)
	{
		d[i] = min(d[i - 2], d[i - 3]) + s[i];
	}
	cout << total - min(d[n - 1], d[n - 2]);
} 