#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

vector<int> adj[502];
int vis[502];
int n, m;
int cnt = 0;

void dfs()
{
	stack<int> s;
	s.push(1);
	vis[1] = true;

	while (!s.empty())
	{
		int cur = s.top();
		s.pop();

		for (auto nxt : adj[cur])
		{
			if (vis[nxt])
				continue;
			cnt++;
			vis[nxt] = true;
			if(cur == 1)
				s.push(nxt);			
		}
	}
}
void bfs()
{
	queue<int> q;
	q.push(1);
	vis[1] = true;

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		for (const auto nxt : adj[cur])
		{
			if (vis[nxt])
				continue;
			cnt++;
			vis[nxt] = true;
			if(cur == 1)
				q.push(nxt);
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	cin >> m;

	while (m--)
	{
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	bfs();
	
	cout << cnt;	
}