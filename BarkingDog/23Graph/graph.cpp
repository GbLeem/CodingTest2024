//인접 행렬 -> 찾기: O(1), 크기: O(V^2)
// 두점의 연결 여부를 자주 확인할 때

//인접 리스트 -> 크기: O(V+E) 
// 정점을 자주 확인할 때


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

vector<int> adj[10];
bool vis[10];

void bfs()
{
	queue<int> q;
	q.push(1);
	vis[1] = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		cout << cur << " ";
		for (auto nxt : adj[cur])
		{
			if (vis[nxt])
				continue;
			q.push(nxt);
			vis[nxt] = true;
		}
	}
}

//DFS와 재귀
//진짜 DFS 순서와 맞다
void dfs(int cur)
{
	vis[cur] = true;
	cout << cur << " ";
	for (auto nxt : adj[cur])
	{
		if (vis[nxt])
			continue;
		dfs(nxt);
	}
}

//순서 맞는 비재귀 DFS
void dfs()
{
	stack<int> s;
	s.push(1);
	vis[1] = true;

	while (!s.empty())
	{
		int cur = s.top();
		s.pop();
		if (vis[cur])
			continue;
		vis[cur] = true;
		cout << cur << " ";
		for (auto nxt : adj[cur])
		{
			if (vis[nxt])
				continue;
			s.push(nxt);
		}
	}
}

int main()
{

}