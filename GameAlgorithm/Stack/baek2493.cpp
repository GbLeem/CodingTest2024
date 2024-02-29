//#include <iostream>
//#include <vector>
//using namespace std;
//
//int N;
//vector<int> vec;
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> N;
//
//	while (N--)
//	{
//		int num;
//		cin >> num;
//
//		bool flag = false;
//		for (int i = 0; i < vec.size(); ++i)
//		{
//			if (vec[vec.size() - i - 1] > num)
//			{
//				cout << vec.size() - i << " ";
//				flag = true;
//				break;
//			}
//		}
//		if (!flag)
//			cout << 0 << " ";
//
//		vec.push_back(num);
//	}
//}

#include <iostream>
#include <stack>
using namespace std;

int N;
stack<int> st;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	//st.push(100000001);
	int index = 0;
	while (N--)
	{
		int num;
		cin >> num;

		if (st.empty())
		{
			cout << "0 ";
		}
		else
		{
			while (st.top() < num)
			{
				st.pop();
				index--;
			}
			cout << index << " ";
		}

		st.push(num);
		index++;
	}
}

//#include <iostream>
//#include <stack>
//using namespace std;
//
//int N;
//stack<pair<int, int>> tower;
//
//int main() 
//{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//
//    cin >> N;
//    tower.push({ 100000001, 0 });
//    for (int i = 1; i <= N; i++) 
//    {
//        int height;
//        cin >> height;
//        while (tower.top().first < height)
//            tower.pop();
//        cout << tower.top().second << " ";
//        tower.push({ height, i });
//    }
//}