#include <iostream>
using namespace std;

int arr[50][2];
int t;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	arr[0][0] = 1;
	arr[1][1] = 1;

	for (int i = 2; i <= 40; ++i)
	{
		arr[i][0] = arr[i - 1][0] + arr[i - 2][0];
		arr[i][1] = arr[i - 1][1] + arr[i - 2][1];
	}

	for (int i = 0; i < t; ++i)
	{
		int n;
		cin >> n;

		cout << arr[n][0] << " " << arr[n][1] << "\n";
	}
}