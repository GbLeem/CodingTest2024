#include<iostream>
using namespace std;

int t, n;
int board[2][100005];
int d[100005][3]; //(값, 마지막으로 선택한 타일)

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
		
	cin >> t;

	while (t--)
	{
		cin >> n;

		for (int i = 0; i < 2; ++i)
			fill(board[i], board[i] + n, 0);

		for (int i = 0; i < n; ++i)
			fill(d[i], d[i] + 3, 0);

		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < n; ++j)
				cin >> board[i][j]; // board[0][1] 은 첫줄 2번째
		}
		
		d[0][0] = 0;
		d[0][1] = board[0][0];
		d[0][2] = board[1][0];	

		if (n == 1)
			cout << max(max(d[0][0], d[0][1]), d[0][2]) << "\n";
		else
		{
			for (int i = 1; i < n; ++i)
			{
				//첫줄 붙이거나 둘째줄 붙이거나 안붙이거나
				d[i][0] = max(max(d[i - 1][1], d[i - 1][2]), d[i - 1][0]);
				d[i][1] = max(d[i - 1][0], d[i - 1][2]) + board[0][i]; //첫줄 붙임
				d[i][2] = max(d[i - 1][0], d[i - 1][1]) + board[1][i]; //둘째줄 붙임
			}
			
			cout << max(max(d[n - 1][0], d[n - 1][1]), d[n - 1][2]) << "\n";
		}
	}
}



//#include <iostream>
//#include <vector>
//using namespace std;
//
//int t, n;
//int d[100002][2];
//int a[200004];
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> t;
//	while (t--)
//	{
//		cin >> n;
//		fill(a, a + n * 2, 0);
//
//		for (int i = 0; i < 2 * n; ++i)
//			cin >> a[i]; //50 10 100 20 40 / 30 50 70 10 60
//
//		d[1][0] = a[0];//위
//		d[1][1] = a[n];//아래 (5)
//		
//		for (int i = 2; i <= n; ++i)
//		{
//			d[i][0] = max(d[i - 1][1], 0) + a[i - 1];
//			d[i][1] = max(d[i - 1][0], 0) + a[i - 1 + n]; //2-1+5
//		}
//		cout << max(d[n][0], d[n][1]) << "\n";
//	}
//}