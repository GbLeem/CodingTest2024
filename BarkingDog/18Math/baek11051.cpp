//nCk = (n-1)C(k-1) + (n-1)Ck

#include <iostream>
using namespace std;

int ans[1002][1002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
		
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= 1000; ++i)
	{
		ans[i][0] = ans[i][i] = 1;
		for (int j = 1; j < i; ++j)
			ans[i][j] = (ans[i - 1][j - 1] + ans[i - 1][j]) % 10007;
	}
	cout << ans[n][k];
}