#include <iostream>
using namespace std;

int t, h, w, n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;

	while (t--)
	{
		cin >> h >> w >> n;

		int mod = n % h;
		int div = n / h;
		if (mod == 0)	
			cout << h * 100 + div << "\n";	
		else
			cout << mod * 100 + div + 1 << "\n";
	}
}