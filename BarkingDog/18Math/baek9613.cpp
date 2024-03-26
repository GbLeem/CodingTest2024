#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> vec(n);

		for (int i = 0; i < n; ++i)
		{
			cin >> vec[i];
		}

	}
}