//무방향이면서 사이클이 없는 연결그래프

//v개의 정점을 가지고 v-1개의 간선을 가지는 연결 그래프
//임의의 두 점을 연결하는 simple path 가 유일한 그래프


//트리에서 BFS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[10];
int p[10]; //부모를 저장
int depth[10];

void bfs(int root)
{
	queue<int> q;
	q.push(root);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		cout << cur << " ";
		for (int nxt : adj[cur])
		{
			if (p[cur] == nxt) //부모를 빼고 나머지 queue에 넣기
				continue;
			q.push(nxt);
			p[nxt] = cur;
			depth[nxt] = depth[cur] + 1;  //depth 계산
		}
	}
}

//stack 메모리 제한있을때조심
void dfs(int cur)
{
	cout << cur << " ";
	for (int nxt : adj[cur])
	{
		if (p[cur] == nxt) 
			continue;
		p[nxt] = cur;
		depth[nxt] = depth[cur] + 1;
		dfs(nxt);
	}
}

//only 순회
// call dfs(1,0)
void dfs(int cur, int par)
{
	cout << cur << " ";
	for (int nxt : adj[cur])
	{
		if (par == nxt) continue;
		dfs(nxt, cur);
	}
}