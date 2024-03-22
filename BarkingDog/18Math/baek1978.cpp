#include <iostream>
using namespace std;

bool isprime(int n)
{
	if (n == 1)
		return false;
	for (int i = 2; i * i <= n; ++i) //i가 루트n 이하까지
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
	int n;
	cin >> n;

	int cnt = 0;
	while (n--)
	{
		int num;
		cin >> num;
		cnt += isprime(num);
	}
	cout << cnt << "\n";
}