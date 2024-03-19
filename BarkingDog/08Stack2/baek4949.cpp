#include <iostream>
#include<string>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str = "";

	while (1)
	{
		getline(cin, str);

		if (str == ".")
			return 0;
		stack<char> st;
		bool finish = true;

		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i] == '(' || str[i] == '[')
				st.push(str[i]);
			if (str[i] == ')')
			{
				if (!st.empty() && st.top() == '(')
					st.pop();
				else
				{
					cout << "no\n";
					finish = false;
					break;
				}
			}
			if (str[i] == ']')
			{
				if (!st.empty() && st.top() == '[')
					st.pop();
				else
				{
					cout << "no\n";
					finish = false;
					break;
				}
			}
			if (str[i] == '.' && !st.empty())
			{
				cout << "no\n";
				finish = false;
				break;
			}

		}
		if (st.empty() && finish)
			cout << "yes\n";
	}
}