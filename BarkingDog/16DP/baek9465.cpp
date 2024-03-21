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