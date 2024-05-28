#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, r, q; //정점, 루트, 쿼리
const int MAX_INT = 10e5 + 10;
vector<int> adj[100005];
bool vis[100005];
int cnt[MAX_INT];

void bfs()
{
	queue<int> q;
	q.push(r);
	vis[r] = true;

	int temp = 0;
	while (!q.empty())
	{
		temp++;
		int cur = q.front();
		q.pop();
		for (int nxt : adj[cur])
		{
			if (vis[nxt])
				continue;
			q.push(nxt);
			vis[nxt] = true;
			cnt[nxt] = cnt[cur] + 1;
		}
	}
}
int dfs(int cur)
{
	vis[cur] = 1;

	for (auto nxt : adj[cur])
	{
		if (vis[nxt])
			continue;
		cnt[cur] += dfs(nxt);
	}
	cnt[cur]++;
	return cnt[cur];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> r >> q;	

	for (int i = 0; i < n - 1; ++i)
	{
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}	

	dfs(r);
	//bfs();
	for (int i = 0; i < q; ++i)
	{
		int query;
		cin >> query;
		
		cout << cnt[query] << "\n";
	}
}

