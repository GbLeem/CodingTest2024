#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	long long int answer = 0;
	cin >> N;
	stack<int> st;

	while (N--)
	{	
		int h;
		cin >> h;

		while (!st.empty() && st.top() <= h)
			st.pop();
		answer += st.size();
		st.push(h);		
	}
	
	cout << answer;
}


//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	int N;
//	long long int answer = 0;
//	cin >> N;
//	vector<int> vec;
//	while (N--)
//	{
//		int h;
//		cin >> h;
//
//		vec.push_back(h);
//	}
//
//	for (int i = 0; i < vec.size(); ++i)
//	{
//		for (int j = i + 1; j < vec.size(); ++j)
//		{
//			if (vec[i] > vec[j])
//				answer++;
//			else //같거나 높음
//				break;
//		}
//	}
//	cout << answer;
//}