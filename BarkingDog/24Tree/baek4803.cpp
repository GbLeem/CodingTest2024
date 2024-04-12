#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> adj[502];
bool vis[502];

int cnt = 0;
int idx = 1;
int tree;

void dfs(int cur, int par)
{
	for (int nxt : adj[cur])
	{
		if (par == nxt)
			continue;
		if (vis[nxt]) //방문한곳 또오면 트리아님
		{
			tree = false;
			continue;
		}
		vis[nxt] = true;
		dfs(nxt, cur);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
		
	while (1)
	{
		cin >> n >> m;
		if (n == 0 && m == 0)
			return 0;
		fill(vis, vis + 502, 0);

		for (int i = 1; i <= n; ++i)
			adj[i].clear();		
		
		for (int i = 0; i < m; ++i)
		{
			int u, v;
			cin >> u >> v;
			
			adj[u].push_back(v);
			adj[v].push_back(u);		
		}

		cnt = 0;

		for (int i = 1; i <= n; ++i)
		{
			if (vis[i]) //방문한곳 제외
				continue;
			vis[i] = true;
			tree = true;
			dfs(i, 0);
			cnt += tree;
		}

		cout << "Case " << idx << ": ";				
		if (!tree)
			cout << "No trees.\n";
		else if (cnt == 1)
			cout << "There is one tree.\n";
		else
			cout << "A forest of " << cnt << " trees.\n";
		idx++;
	}
}