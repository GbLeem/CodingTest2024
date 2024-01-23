//BFS
//너비 우선 탐색
//큐 사용

//1. 방문처리
//2. 
//큐에서 하나의 노드 꺼내고
//해당 노드에 연결된 노드 중 방문하지 않은 노드 방문 & 삽입

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int number = 7; //총 노드 갯수
int visit[7]; //방문처리용
vector<int> a[8]; //index 처리용

void bfs(int start)
{
	queue < int> q;
	q.push(start);
	visit[start] = true;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		cout << x << " ";
		for (int i = 0; i < a[x].size(); ++i) //인접한 노드 방문
		{
			int y = a[x][i]; 
			if (!visit[y]) //방문 안한 경우에!
			{
				q.push(y);
				visit[y] = true;
			}
		}
	}
}

int main()
{
	a[1].push_back(2);
	a[2].push_back(1);

	a[1].push_back(3);
	a[3].push_back(1);

	a[2].push_back(3);
	a[3].push_back(2);

	a[2].push_back(4);
	a[4].push_back(2);

	a[2].push_back(5);
	a[5].push_back(2);

	a[4].push_back(5);
	a[5].push_back(4);

	a[3].push_back(6);
	a[6].push_back(3);

	a[3].push_back(7);
	a[7].push_back(3);

	a[6].push_back(7);
	a[7].push_back(6);

	bfs(1);

	return 0;
}