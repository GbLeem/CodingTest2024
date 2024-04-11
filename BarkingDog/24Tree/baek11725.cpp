#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<int> adj[100002];
int p[100002];

void bfs(int root)
{
	queue<int> q;
	q.push(root);
	
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int nxt : adj[cur])
		{
			if (p[cur] == nxt)
				continue;
			q.push(nxt);
			p[nxt] = cur;
		}
	}
}


void dfs(int cur)
{
	for (auto nxt : adj[cur])
	{
		if (p[cur] == nxt)
			continue;
		p[nxt] = cur;
		dfs(nxt);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n - 1; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	bfs(1);
	for (int i = 2; i <= n; ++i)
		cout << p[i] << "\n";
}