#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> adj[100];
int scores[100];
int n;

int bfs(int root)
{
	queue<int> q;
	int dist[100];
	fill(dist + 1, dist + n + 1, -1);

	dist[root] = 0;
	q.push(root);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int nxt : adj[cur])
		{
			if (dist[nxt] != -1)
				continue;
			dist[nxt] = dist[cur] + 1;
			q.push(nxt);
		}
	}
	int max_length = *max_element(dist + 1, dist + n + 1); //현재 위치에서 가장 먼 곳까지의 거리
	//1 -> 5 가려면 3의 거리 필요함
	if (max_length == 0)
		return 100;
	return max_length;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	while(1)
	{
		int u, v;
		cin >> u >> v;
		if (u == -1 && v == -1)
			break;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	for (int i = 1; i <= n; ++i)
		scores[i] = bfs(i);
	
	int minScores = *min_element(scores + 1, scores + n + 1); //가장 긴 거리들 중 가장 짧은 것
	vector<int> temp;
	for (int i = 1; i <= n; ++i)
	{
		if (scores[i] == minScores)
			temp.push_back(i);
	}
	cout << minScores << " " << temp.size() << "\n";
	for (auto ti : temp)
		cout << ti << " ";
}