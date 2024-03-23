#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

int lcm(int a, int b)
{
	return a / gcd(a, b) * b;
}

//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int t;
//	cin >> t;
//
//	while (t--)
//	{
//		int m, n, x, y;
//		cin >> m >> n >> x >> y; // 10 12 3 9
//		bool find = false;
//		
//		int size = lcm(m, n);
//		for (int i = x; i <= size; i+=m) //3 13 23 33 ... 
//		{
//			if (i % n == y)
//			{
//				cout << i << "\n";
//				find = true;
//				break;
//			}
//		}
//		if (!find)
//			cout << -1 << "\n";
//	}
//}


int solve(int m, int n, int x, int y)
{
	if (x == m)
		x = 0;
	if (y == n)
		y = 0;
	int l = lcm(m, n);

	for (int i = x; i <= l; i+=m)
	{
		if (i == 0)
			continue;
		if (i % n == y)
			return i;
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		cout << solve(m, n, x, y) << "\n";
	}
}