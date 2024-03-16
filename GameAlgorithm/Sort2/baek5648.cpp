#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

long long arr[1000001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		string num;
		cin >> num;
		reverse(num.begin(), num.end());
		arr[i] = stoll(num);
	}

	sort(arr, arr + n);

	for (int i = 0; i < n; ++i)
		cout << arr[i] << "\n";
}