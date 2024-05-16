//#include <iostream>
//using namespace std;
//
//int n;
//long long d[105];
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	
//	cin >> n;
//	//int endSize = 10 * n - 1;
//	//int startSize = pow(10, n - 1);
//
//	d[1] = 9;
//	
//	for (int i = 2; i <= n; ++i)
//	{
//		d[i] = d[i - 1] * 2 - (i - 1);
//	}
//
//	cout << d[n];
//}