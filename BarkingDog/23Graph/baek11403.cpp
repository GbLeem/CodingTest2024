#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int adj[102][102];
int vis[102]; //각 정점
int n;

bool bfs(int st, int en)
{	
	fill(vis, vis + 102, 0);

	queue<int> q;

	q.push(st);
	//vis[st] = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int nxt = 0; nxt < n; ++nxt)
		{
			if (vis[nxt])
				continue;

			if (adj[cur][nxt]) //갈수있다면
			{
				q.push(nxt);
				vis[nxt] = true;
				if (nxt == en)
				{
					return true;
				}
			}
		}
	}
	return false;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> adj[i][j];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << bfs(i, j) << " ";
		}
		cout << "\n";
	}
}
