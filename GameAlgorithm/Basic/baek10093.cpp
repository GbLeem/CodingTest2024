#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long a, b;
	cin >> a >> b;

	cout << b - a - 1 << "\n";

	for (long long i = a + 1; i < b; ++i)
	{
		cout << i << " ";
	}
}