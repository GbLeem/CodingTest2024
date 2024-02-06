#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int arr[100001];
int n, k; //수빈 동생

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	fill(arr, arr + 100001, -1);
	arr[n] = 0;

	queue<int> Q;
	Q.push(n);

	while (arr[k] == -1)
	{
		int cur = Q.front();
		Q.pop();

		for (int i : {cur + 1, cur - 1, cur * 2})
		{
			if (i < 0 || i>100000)
				continue;
			if (arr[i] != -1)
				continue;
			arr[i] = arr[cur] + 1;
			Q.push(i);
		}
	}
	cout << arr[k];
}