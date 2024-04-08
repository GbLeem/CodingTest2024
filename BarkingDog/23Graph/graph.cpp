//���� ��� -> ã��: O(1), ũ��: O(V^2)
// ������ ���� ���θ� ���� Ȯ���� ��

//���� ����Ʈ -> ũ��: O(V+E) 
// ������ ���� Ȯ���� ��


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

//DFS�� ���
//��¥ DFS ������ �´�
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

//���� �´� ����� DFS
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