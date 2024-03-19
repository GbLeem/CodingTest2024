#include <iostream>
#include <queue>
using namespace std;

int arr[100002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	fill(arr, arr + 100001, -1);
	arr[N] = 0;

	queue<int> Q;
	Q.push(N);

	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();

		for (auto nxt : { cur - 1, cur + 1 , cur * 2 })
		{
			if (nxt < 0 || nxt > 100000)
				continue;
			if (arr[nxt] != -1)
				continue;
			arr[nxt] = arr[cur] + 1;
			Q.push(nxt);			
		}

		if (arr[K] != -1)
		{
			cout << arr[K];
			return 0;
		}
	}
}
