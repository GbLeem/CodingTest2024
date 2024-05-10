#include <iostream>
#include <queue>
using namespace std;

int n, k;
int board[100005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k; //수빈 동생

	fill(board, board + 100002, -1);
	board[n] = 0;	

	queue<int> Q;

	Q.push(n);

	while (board[k] == -1)
	{
		auto cur = Q.front();
		Q.pop();

		for (int dir : {cur - 1, cur + 1, cur * 2})
		{
			if (dir < 0 || dir > 100000)
				continue;
			if (board[dir] != -1) //이미 갔자나
				continue;
			board[dir] = board[cur] + 1;
			Q.push(dir);
		}
	}
	cout << board[k];
}