#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[20005];
int depth[20005];
int n, m;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	queue<int> q;
	q.push(1);
	depth[1] = 0;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (auto nxt : adj[cur])
		{
			if (depth[nxt] > 0)
				continue;
			q.push(nxt);
			depth[nxt] = depth[cur] + 1;
		}
	}
	int maxDepth = 0;
	for (int i = 2; i <= n; ++i)
	{
		if (maxDepth < depth[i])
			maxDepth = depth[i];
	}
	int cnt = 0;
	int idx = 0;
	bool first = true;
	for (int i = 2; i <= n; ++i)
	{
		if (maxDepth == depth[i])
		{
			if (first)
			{
				idx = i;
				first = false;
			}
			cnt++;
		}
	}

	cout << idx << " " << maxDepth << " " << cnt;
}