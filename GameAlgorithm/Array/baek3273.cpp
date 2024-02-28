#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int x;
	int answer = 0;
	cin >> n;

	int* arr = new int[n];
	
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	cin >> x;
	
	sort(arr, arr + n); // 1 2 3 5 7 9 10 11 12

	for (int i = 0; i < n; ++i)
	{
		if (arr[i] > x)
			break;
		
		int temp = x - arr[i];

		if (find(arr + i + 1, arr + n, temp) != arr+n)
			answer++;
	}
	cout << answer;
}