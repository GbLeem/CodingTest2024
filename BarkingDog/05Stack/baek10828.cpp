#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	stack<int> s;
	cin >> N;
	
	while (N--)
	{
		string str;
		cin >> str;

		if (str == "push")
		{
			int num;
			cin >> num;

			s.push(num);
		}
		else if (str == "pop")
		{
			if (!s.empty())
			{
				cout << s.top() << "\n";
				s.pop();
			}
			else
				cout << -1 << "\n";
		}
		else if (str == "size")
		{
			cout << s.size() << "\n";
		}
		else if (str == "empty")
		{
			cout << s.empty() << "\n";
		}
		else if (str == "top")
		{
			if (!s.empty())
			{
				cout << s.top() << "\n";
			}
			else
				cout << -1 << "\n";
		}
	}
}