//#include <iostream>
//using namespace std;
//
//int n, m; //세로 가로
//int board[10][10];
//int ans = 0;
//
////전체  - 감시 가능
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n >> m;
//	int cctv[5] = { 0, };
//	int cnt[4] = { 0, };
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < m; ++j)
//		{
//			cin >> board[i][j];
//			if (board[i][j] < 6 && board[i][j] > 0)
//				cctv[board[i][j] - 1]++;
//		}
//	}
//	//cout << board[2][4];
//	for (int i = 0; i < n; ++i) //세로
//	{
//		for (int j = 0; j < m; ++j) //가로
//		{
//			if (board[i][j] == 1) //2 2
//			{
//				int tempX = i;
//				int tempY = j;			
//
//				//오른쪽
//				for (int k = tempY; k < m - tempY; ++k) //6 - 2
//				{
//					if (board[i][k] == 6)
//						break;
//					cnt[0]++;
//				}
//				
//				//왼쪽
//				for (int k = tempY; k > 0; --k)
//				{
//					if (board[i][k] == 6)
//						break;
//					cnt[1]++;
//				}
//				
//				//위쪽
//				for (int k = tempX; k > 0; --k)
//				{
//					if (board[k][j] == 6)
//						break;
//					cnt[2]++;
//				}
//				
//				//아래쪽
//				for (int k = tempX; k < n - tempX; ++k)
//				{
//					if (board[k][j] == 6)
//						break;
//					cnt[3]++;
//				}
//			}
//		}
//	}
//
//	for (int i = 0; i < 4; ++i)
//		cout << cnt[i] << "\n";
//}