//BOJ 11728
//#include <iostream>
//#include <queue>
//using namespace std;
//
//queue<int> arr1;
//queue<int> arr2;
//queue<int> ans;
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n, m;
//	cin >> n >> m;
//	int size = n + m;
//
//	for (int i = 0; i < n; ++i)
//	{
//		int num;
//		cin >> num; //3 5
//		arr1.push(num);
//	}
//	for (int i = 0; i < m; ++i)
//	{
//		int num;
//		cin >> num; //2 9
//		arr2.push(num);
//	}
//
//	while (1)
//	{
//		if (arr1.empty())
//		{
//			if (arr2.empty())
//				break;
//			else
//			{
//				while (!arr2.empty())
//				{
//					ans.push(arr2.front());
//					arr2.pop();
//				}
//			}
//
//		}
//		else if (arr2.empty())
//		{
//			if (arr1.empty())
//				break;
//			else
//			{
//				while (!arr1.empty())
//				{
//					ans.push(arr1.front());
//					arr1.pop();
//				}
//			}
//		}
//		else
//		{
//			if (arr1.front() < arr2.front())
//			{
//				ans.push(arr1.front());
//				arr1.pop();
//			}
//			else
//			{
//				ans.push(arr2.front());
//				arr2.pop();
//			}
//		}
//	}
//
//	while (!ans.empty())
//	{
//		cout << ans.front() << " ";
//		ans.pop();
//	}
//}

#include<iostream>
using namespace std;

int n, m;
int a1[1000005];
int a2[1000005];
int ans[1000005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> a1[i];
	for (int i = 0; i < m; ++i)
		cin >> a2[i];

	int a1Idx = 0;
	int a2Idx = 0;

	for (int i = 0; i < n + m; ++i)
	{
		if (a2Idx == m)
			ans[i] = a1[a1Idx++];
		else if (a1Idx == n)
			ans[i] = a2[a2Idx++];
		else if (a1[a1Idx] <= a1[a2Idx]) //stable sort 의 성질을 적용하기
			ans[i] = a1[a1Idx];
		else
			ans[i] = a2[a2Idx];
	}

	for (int i = 0; i < n + m; ++i)
		cout << ans[i] << " ";
}