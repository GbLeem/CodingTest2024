#include <iostream>
using namespace std;

int n;
int d[1000002]; //횟수
int temp[1000002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	d[1] = 0;
	
	for (int i = 2; i <= n; ++i)
	{
		d[i] = d[i - 1] + 1;
		temp[i] = i - 1;

		if (i % 2 == 0 && d[i] > d[i / 2] + 1)
		{
			d[i] = d[i / 2] + 1;
			temp[i] = i / 2;
		}
		if (i % 3 == 0 && d[i] > d[i / 3] + 1)
		{
			d[i] = d[i / 3] + 1;
			temp[i] = i / 3;
		}
	}
	cout << d[n] << "\n";
	int cur = n;
	while (1)
	{
		cout << cur << " ";
		if (cur == 1)
			break;
		cur = temp[cur];
	}
}