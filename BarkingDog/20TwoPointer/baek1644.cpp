#include <iostream>
using namespace std;

int n;

bool isprime(int n)
{
	if (n == 1)
		return false;
	for (int i = 2; i * i <= n; ++i)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 2; i * i <= n; ++i)
	{
		if (isprime(i))
		{

		}
	}
}