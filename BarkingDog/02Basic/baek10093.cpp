#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long int a, b;
	long long int temp;
	cin >> a >> b;

	if (a > b)
	{
		temp = b;
		b = a;
		a = temp;
	}
	if (a == b)
	{
		cout << 0 << "\n";
		return 0;
	}

	int ans = b - a - 1; //차이

	cout << ans << "\n";

	for (int i = 1; i <= ans; ++i)
	{
		cout << a + i << " ";
	}
}