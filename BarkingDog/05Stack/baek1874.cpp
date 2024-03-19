#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	queue<int> s; //4 3 6 8 7 5 2 1
	queue<int> q; //1 2 3 4 5 6 7 8
	stack<int> st; //새로 만들 곳

	queue<char> ans; 

	for (int i = 0; i < n; ++i)
	{
		q.push(i + 1);

		int num;
		cin >> num;
		s.push(num);
	}

	while (!s.empty())
	{				
		if (!st.empty() && (st.top() == s.front()))
		{
  			ans.push('-');
 			st.pop();
			s.pop();
		}
		else
		{
			if (q.empty())
			{
				cout << "NO\n";
				return 0;
			}
			st.push(q.front());
			q.pop();
			ans.push('+');
		}
	}

	while (!ans.empty())
	{
		cout << ans.front() << "\n";
		ans.pop();
	}
}