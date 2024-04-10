#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
vector<int> adj[1002];
int vis[1002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	//���� ��� ����
	while (m--)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int cnt = 0;

	queue<int> Q;
	for (int i = 1; i <= n; ++i)
	{
		if (vis[i])
			continue;
		cnt++;
		queue<int> q;
		q.push(i);

		while (!q.empty())
		{
			int cur = q.front();
			q.pop();

			for (auto nxt : adj[cur])
			{
				if (vis[nxt])
					continue;
				vis[nxt] = true;
				q.push(nxt);
			}
		}
	}
	cout << cnt;
}