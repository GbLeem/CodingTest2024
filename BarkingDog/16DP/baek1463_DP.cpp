#include <iostream>
using namespace std;

int d[1000002];
int n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	d[1] = 0;

	for (int i = 2; i <= n; ++i)
	{
		d[i] = d[i - 1] + 1;
		if (i % 2 == 0)
			d[i] = min(d[i], d[i / 2] + 1);
		if (i % 3 == 0)
			d[i] = min(d[i], d[i / 3] + 1);
	}
	cout << d[n];
}

//점화식
//D[k] = D[k/3] + 1
//D[k] = D[k/2] + 1
//D[k] = D[k - 1] - 1

//초기값
//D[1] = 0