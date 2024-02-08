#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int arr[100002];
int N, K; //

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;	

	fill(arr, arr + 100001, -1);
	arr[N] = 0;

	queue<int> Q;
	Q.push(N);

	while (arr[K] == -1)
	{
		int cur = Q.front();
		Q.pop();

		for (int i : {cur - 1, cur + 1, 2 * cur})
		{
			if (i < 0 || i> 100000)
				continue;
			if (arr[i] != -1)
				continue;
			arr[i] = arr[cur] + 1;
			Q.push(i);
		}
	}
	cout << arr[K];
}