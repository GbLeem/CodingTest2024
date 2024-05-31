#include <iostream>
using namespace std;

int n;
long long d[105][10];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for (int i = 1; i <= 9; ++i)
		d[1][i] = 1;

	//0으로 끝나거나 9로 끝나는 수 갯수 빼야함
	for (int i = 2; i <= n; ++i)
	{
		for (int k = 0; k <= 9; ++k) //뒷자릿수
		{
			if (k != 0)
				d[i][k] += d[i - 1][k - 1];
			if (k != 9)
				d[i][k] += d[i - 1][k + 1];
			d[i][k] %= 1'000'000'000;
		}
	}
	long long ans = 0;
	for (int i = 0; i <= 9; ++i)
		ans += d[n][i];
	ans %= 1'000'000'000;
	cout << ans;
}