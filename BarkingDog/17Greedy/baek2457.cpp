////공주님의 정원
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int n;
//
//bool cmp(vector<int> v1, vector<int>v2)
//{
//	if (v1[0] == v2[0])
//	{
//		if (v1[1] == v2[1])
//		{
//			if (v1[2] == v2[2])
//				return v1[3] > v2[3];
//			return v1[2] > v2[2];
//		}
//		return v1[1] < v2[1];
//	}
//	return v1[0] < v1[0];
//
//}
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n;
//	vector<vector<int>> vec(n);
//
//	for (int i = 0; i < n; ++i) 
//	{
//		for (int j = 0; j < 4; ++j)
//		{
//			int num;
//			cin >> num;
//			vec[i].push_back(num);
//		}
//	}
//	
//	sort(vec.begin(), vec.end(), cmp);
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < 4; ++j)
//		{
//			cout << vec[i][j] << " ";
//		}
//		cout << "\n";
//	}
//
//	int ans = 0;
//	int m = 3;
//	int d = 1;
//	bool first = true;
//
//	for (int i = 0; i < n; ++i)
//	{
//		if (first && (vec[i][0] < 3 || (vec[i][0] == 3 && vec[i][1] <= 1)))
//		{
//			ans++;
//			m = vec[i][2];
//			d = vec[i][3];
//			first = false;
//		}
//
//
//
//		if (m >= 11 && d >= 30)
//			break;
//	}
//	cout << ans;
//}