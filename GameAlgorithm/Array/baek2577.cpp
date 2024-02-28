#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	//10^9
	int A, B, C;
	int arr[10] = { 0, };
	cin >> A >> B >> C;

	long long res = A * B * C;

	while (res > 0)
	{
		arr[res % 10]++;
		res /= 10;
	}
	for (const auto a : arr)
		cout << a << "\n";
}