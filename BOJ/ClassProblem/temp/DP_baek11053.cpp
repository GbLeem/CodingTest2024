//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int n;
//int board[1005];
//int d[1005];
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n;
//
//	for (int i = 1; i <= n; ++i)
//	{
//		cin >> board[i];
//		d[i] = 1;
//	}
//	for (int i = 1; i <= n; ++i)
//	{
//		for (int j = 1; j <= i; ++j)
//		{
//			if (board[j] < board[i])
//			{
//				d[i] = max(d[j] + 1, d[i]);
//			}
//		}
//	}
//	cout << *max_element(d + 1, d + n + 1);
//}