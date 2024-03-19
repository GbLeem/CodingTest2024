//BFS 풀이
#include <iostream>
#include <queue>
using namespace std;

int dist[1000002];
int x;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> x;

	fill(dist, dist + 1000002, -1);
	queue<int> Q;
	dist[1] = 0;
	Q.push(1);
	
	while (!Q.empty())
	{
		int cur = Q.front();
		Q.pop();

		for (int next : {cur * 3, cur * 2, cur + 1})
		{
			if (next < 0 || next > 1000000)
				continue;
			if (dist[next] != -1)
				continue;
			dist[next] = dist[cur] + 1;
			Q.push(next);
		}
	}

	cout << dist[x];
}