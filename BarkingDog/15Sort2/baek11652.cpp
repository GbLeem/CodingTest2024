//cnt : 현재 보고있는 수가 몇번 등장했는지
//mxval : 현재까지 가장 많이 등장한 수의 값
//mxcnt : 현재까지 가장 많이 등장한 수의 등장 횟수

#include <iostream>
#include <algorithm>
using namespace std;

long long arr[100002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	sort(arr, arr + N);

	int cnt = 0;
	long long maxVal = -(111 << 62) - 1;
	int maxCnt = 0;

	for (int i = 0; i < N; ++i)
	{
		if (i == 0 || arr[i - 1] == arr[i])
			cnt++;
		else
		{
			if (cnt > maxCnt)
			{
				maxCnt = cnt;
				maxVal = arr[i - 1];
			}
			cnt = 1;
		}
	}
	if (cnt > maxCnt)
		maxVal = arr[N - 1];
	cout << maxVal;
}