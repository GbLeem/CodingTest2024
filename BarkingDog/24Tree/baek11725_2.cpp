#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[100005];
int p[100005];
int n;

void bfs(int cur)
{
	queue<int> q;
	q.push(cur); //root 는 1
	p[0] = cur;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int nxt : adj[cur]) 
		{
			if (p[cur] == nxt) //nxt가 cur의 부모인 경우 패스
				continue;
			q.push(nxt);
			p[nxt] = cur;
		}
	}
}

void dfs(int cur)
{
	for (int nxt : adj[cur])
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
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	//bfs(1);
	dfs(1);
	for (int i = 2; i <= n; ++i)
		cout << p[i] << "\n";
}
