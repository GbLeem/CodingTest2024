//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int n;
//int d[1002];
//int a[1002];
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n;
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> a[i];
//		d[i] = a[i]; //1 100 2 50 60 3 5 6 7 8
//	}
//
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < i; ++j)
//		{
//			if (a[j] < a[i])
//			{
//				d[i] = max(d[j] + a[i], d[i]);
//			}
//		}
//	}
//	cout << *max_element(d, d + n);
//}