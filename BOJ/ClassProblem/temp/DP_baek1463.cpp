//1차원 BFS
//#include <iostream>
//#include <queue>
//using namespace std;
//
//int n;
//int d[1000002][3];
//int board[1000002];
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n;
//
//	fill(board, board + 1000002, -1);
//
//	queue<int> q;
//	q.push(1);
//	board[1] = 0;
//
//	while (!q.empty())
//	{
//		int cur = q.front();
//		q.pop();
//
//		for (int nxt : {cur * 3, cur * 2, cur + 1})
//		{
//			if (nxt < 0 || nxt > 1000000)
//				continue;
//			if (board[nxt] != -1)
//				continue;			
//
//			board[nxt] = board[cur] + 1;
//			q.push(nxt);
//		}
//	}
//
//	cout << board[n];
//}


//DP
#include <iostream>
using namespace std;

int n;
int d[1000002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	//현재 숫자가 n일때 사용한 연산의 횟수
	d[1] = 0;
	
	for (int i = 2; i <= n; ++i)
	{
		d[i] = d[i - 1] + 1;
		if (i % 2 == 0)
		{
			d[i] = min(d[i], d[i / 2] + 1);
		}
		if (i % 3 == 0)
		{
			d[i] = min(d[i], d[i / 3] + 1);
		}
	}
	cout << d[n];
}