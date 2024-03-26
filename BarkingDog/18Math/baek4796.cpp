#include <iostream>
using namespace std;

int l, p, v;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int index = 1;

	while (1)
	{
		cin >> l >> p >> v;
		if (l == 0 && p == 0 && v == 0)
			break;

		int ans = 0;
		int temp = v / p;
		if (v % p <= l)
			ans = temp * l + v % p;
		else
			ans = temp * l + l;
		cout << "Case " << index << ": " << ans << "\n";
		index++;
	}
}