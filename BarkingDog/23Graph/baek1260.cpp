#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

vector<int> adj[1002];
int vis[1002];
int n, m, v;

void bfs()
{
	queue<int> q;
	q.push(v);
	vis[v] = true;

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		cout << cur << " ";
		for (const auto nxt : adj[cur])
		{
			if (vis[nxt])
				continue;
			q.push(nxt);
			vis[nxt] = true;
		}
	}
}

void dfs2()
{
	stack<int> s;
	s.push(v);
	vis[v] = true;
	while (!s.empty())
	{
		int cur = s.top();
		s.pop();
		if (vis[cur])
			continue;
		vis[cur] = true;
		cout << cur << " ";
		for (const auto nxt : adj[cur])
		{
			if (vis[nxt])
				continue;
			s.push(nxt);
		}
	}
}

void dfs(int cur)
{
	vis[cur] = true;
	cout << cur << " ";
	for (const auto nxt : adj[cur])
	{
		if (vis[nxt])
			continue;
		dfs(nxt);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> v;

	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; ++i)
		sort(adj[i].begin(), adj[i].end());

	dfs(v);
	cout << "\n";
	fill(vis, vis + 1002, 0);
	bfs();
}