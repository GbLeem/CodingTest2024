#include <iostream>
#include <queue>
using namespace std;

int dist1[100002];
int dist2[100002];
int dist3[100002];
int N, K;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	fill(dist1, dist1 + 100001, -1);
	fill(dist2, dist2 + 100001, -1);
	fill(dist3, dist3 + 100001, -1);

	dist1[N] = 0;
	dist2[N] = 0;
	dist3[N] = 0;

	queue<int> Q1;
	queue<int> Q2;
	queue<int> Q3;

	Q1.push(N);
	Q2.push(N);
	Q3.push(N);

	while (!Q1.empty())
	{
		auto cur = Q1.front();
		Q1.pop();

		if (dist1[K] != -1)
			break;
 		for (auto nxt : { cur + 1, cur - 1, 2 * cur})
		{
			if (nxt < 0 || nxt > 100000)
				continue;
			if (dist1[nxt] != -1)
				continue;

			if (nxt != 2 * cur)
				dist1[nxt] = dist1[cur] + 1;
			else if (nxt == 2 * cur)
				dist1[nxt] = dist1[cur];

			Q1.push(nxt);
		}
	}

	while (!Q2.empty())
	{
		auto cur = Q2.front();
		Q2.pop();

		if (dist2[K] != -1)
			break;
		for (auto nxt : { 2 * cur, cur + 1, cur - 1 })
		{
			if (nxt < 0 || nxt > 100000)
				continue;
			if (dist2[nxt] != -1)
				continue;

			if (nxt != 2 * cur)
				dist2[nxt] = dist2[cur] + 1;
			else if (nxt == 2 * cur)
				dist2[nxt] = dist2[cur];

			Q2.push(nxt);
		}
	}

	while (!Q3.empty())
	{
		auto cur = Q3.front();
		Q3.pop();

		if (dist3[K] != -1)
			break;
		for (auto nxt : { 2 * cur, cur + 1, cur - 1 })
		{
			if (nxt < 0 || nxt > 100000)
				continue;
			if (dist3[nxt] != -1)
				continue;

			if (nxt != 2 * cur)
				dist3[nxt] = dist3[cur] + 1;
			else if (nxt == 2 * cur)
				dist3[nxt] = dist3[cur];

			Q3.push(nxt);
		}
	}

	int answer = min(dist1[K], dist2[K]);
	answer = min(answer, dist3[K]);
	cout << answer;
}