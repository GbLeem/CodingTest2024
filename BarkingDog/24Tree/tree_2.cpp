#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int lc[9] = { 0,2,3,6,0,0,0,0,0 };
int rc[9] = { 0,3,5,7,0,8,0,0,0 };

//레벨 순회
void bfs()
{
	queue<int> q;
	q.push(1); //root : 1
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		cout << cur << " ";
		if (lc[cur])
			q.push(lc[cur]);
		if (rc[cur])
			q.push(rc[cur]);
	}
}

//전위 순회 -> 현재, 왼쪽, 오른쪽
//DFS와 순서 같음
void preorder(int cur)
{
	cout << cur << " ";
	if (lc[cur] != 0)
		preorder(lc[cur]);
	if (rc[cur] != 0)
		preorder(rc[cur]);
}

//중위 순회 -> 왼쪽, 현재,  오른쪽 
void inorder(int cur)
{
	if (lc[cur] != 0)
		inorder(lc[cur]);
	cout << cur << " ";
	if (rc[cur] != 0)
		inorder(rc[cur]);
}

//후위 순회 ->왼쪽, 오른쪽, 현재
//리프 노드를 왼쪽부터 하나씩 없애는 느낌쓰
void postorder(int cur)
{
	if (lc[cur] != 0)
		postorder(lc[cur]);
	if (rc[cur] != 0)
		postorder(rc[cur]);
	cout << cur << " ";
}