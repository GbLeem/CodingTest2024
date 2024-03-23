//이항계수

#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	int ans = 1;
	for (int i = 1; i <= n; ++i)
		ans *= i; //1 2 3 4 5 
	for (int i = 1; i <= k; ++i)
		ans /= i; // 1 2
	for (int i = 1; i <= n - k; ++i)
		ans /= i; // 1 2 3
	cout << ans;
}