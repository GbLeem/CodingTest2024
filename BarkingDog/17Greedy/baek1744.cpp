#include <iostream>
#include <algorithm>
using namespace std;

int arr[52];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int minus = 0;
	int zero = 0;

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		if (arr[i] < 0)
			minus++;
		if (arr[i] == 0)
			zero++;
	}

	sort(arr, arr + n);

	int ans = 0;

	//음수 처리
	int temp = 0;
	for (int i = 0; i < minus; i += 2)
	{
		if (i == minus - 1)
		{
			temp = arr[i];
			break;
		}
		else
			ans += arr[i] * arr[i + 1];
	}
	if (zero == 0)
		ans += temp;
	
	//양수
	int temp2 = 0;
	for (int i = n - 1; i >= minus; i -= 2)
	{
		if (i == minus)
		{
			temp2 = arr[i];
			break;
		}
		if (arr[i] * arr[i - 1] > arr[i] + arr[i - 1])
			ans += arr[i] * arr[i - 1];
		else
			ans += (arr[i] + arr[i - 1]);
	}
	ans += temp2;

	cout << ans;
}