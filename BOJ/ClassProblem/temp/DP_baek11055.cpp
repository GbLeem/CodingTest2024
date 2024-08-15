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
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> board[i];
//		d[i] = board[i];
//	}
//
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < i; ++j)
//		{
//			if (board[i] > board[j])
//				d[i] = max(d[i], d[j] + board[i]);
//		}
//	}
//	cout << *max_element(d, d + n + 2);
//}