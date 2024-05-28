#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<pair<int, int>> adj[1005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;

	for (int i = 0; i < n - 1; ++i)
	{
		int u, v, l;
		cin >> u >> v >> l;

		adj[u].push_back({ v, l }); 
		adj[v].push_back({ u, l });
	}
	 
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;

		queue<pair<int, int>> q;
		vector<bool> vis(n + 2);

		q.push({ u, 0 });
		vis[u] = true;

		while (!q.empty())
		{
			auto cur = q.front();
			q.pop();
			if (cur.first == v)
			{
				cout << cur.second << "\n";
				break;
			}
			for (auto nxt : adj[cur.first])
			{
				if (vis[nxt.first])
					continue;
				vis[nxt.first] = true;
				q.push({ nxt.first, cur.second + nxt.second });
			}
		}
	}

}