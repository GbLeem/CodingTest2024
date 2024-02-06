//BFS에서 큐 대신 스택 쓰기

//<DFS vs BFS>
//BFS는 거리순으로 방문 -> 동심원 느낌
//DFS는 한방향의 끝까지 먼저 방문하기
//-> 거리계산에서는 DFS 사용 못한다. only BFS
//-> DFS는 graph와 tree에서 사용한다.


#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int board[502][502] = 
{ {1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} };;

int vis[502][502];

int n = 7, m = 10;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<pair<int, int>>S;
	S.push({ 0,0 });
	vis[0][0] = 1;

	while (!S.empty())
	{
		auto cur = S.top();
		S.pop();
		cout << '(' << cur.first << ", " << cur.second << ") -> ";

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (board[nx][ny] == 0 || vis[nx][ny] == 1)
				continue;
			vis[nx][ny] = 1;
			S.push({ nx,ny });
		}
	}
}

//(0, 0) -> (0, 1) -> (0, 2) -> (1, 0) -> (2, 0) -> (2, 1) -> (2, 2) -> (3, 1) -> (4, 1) -> (3, 0) ->