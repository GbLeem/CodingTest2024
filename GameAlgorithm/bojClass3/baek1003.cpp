#include <iostream>
using namespace std;

int fibonacci(int n, int arr[])
{
	if (n == 0) 
	{
		arr[0]++;
		return 0;
	}
	else if (n == 1) 
	{
		arr[1]++;
		return 1;
	}
	else 
	{
		return fibonacci(n - 1, arr) + fibonacci(n - 2, arr);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;
		int arr[2] = { 0,0 };

		fibonacci(n, arr);

		cout << arr[0] << " " << arr[1] << "\n";
	}
}