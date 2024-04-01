#include <iostream>
#include <algorithm>
using namespace std;

int arr[100002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	sort(arr, arr + N); //10 12 20
	
	int ans = 0;
	int num = N;

	for (int i = 0; i < N; ++i)
	{		
		if (ans < num * arr[i])
		{
			ans = num * arr[i];
		}
		num--;
	}
	cout << ans;
}