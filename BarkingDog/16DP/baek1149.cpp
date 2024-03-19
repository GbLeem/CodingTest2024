#include <iostream>
using namespace std;

int n;
int cost[1002][3];
int d[1002][3];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int r, g, b;
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}

	//i가 빨강일 때 - 하나 전이 초 파, 하나 후가 초 파
	d[1][0] = cost[1][0];
	d[1][1] = cost[1][1];
	d[1][2] = cost[1][2];

	for (int i = 2; i <= n; ++i)
	{
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + min(d[i + 1][1], d[i + 1][2]) + cost[i][0];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + min(d[i + 1][0], d[i + 1][2]) + cost[i][1];
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + min(d[i + 1][0], d[i + 1][1]) + cost[i][2];
	}

	cout << min(min(d[n][0], d[n][1]), d[n][2]);
}