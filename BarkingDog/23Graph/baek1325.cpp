#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> adj[10005];
int depth[10005];
bool vis[10005];
int n, m;

void dfs(int cur)
{
	vis[cur] = 1;
	depth[cur]++;
	for (int nxt : adj[cur])
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

	cin >> n >> m; //n개 노드, 입력 m번
	
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
	}

	for (int i = 1; i <= n; ++i)
	{
		fill(vis, vis + 10005, 0);
		dfs(i);
	}
	
	int maxV = *max_element(depth, depth + n + 1);

	for (int i = 1; i <= n; ++i)
	{
		if (maxV == depth[i])
			cout << i << " ";
	}
}