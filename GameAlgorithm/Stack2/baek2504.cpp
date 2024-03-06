#include <iostream> 
#include <stack>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;
	stack<char> st;
	int answer = 0;

	for (int i = 0; i < str.size(); ++i)
	{
		int tempVal = 0;

		if (str[i] == '(' || str[i] == '[')
			st.push(str[i]);

		else if (str[i] == ')' && !st.empty() && st.top() == '(')
		{
			st.pop();
			if (str[i - 1] == '(')
			{
				tempVal += 2;
				stack<char> temp = st;
				while (!temp.empty())
				{
					if (temp.top() == '(')
						tempVal *= 2;
					else if (temp.top() == '[')
						tempVal *= 3;
					temp.pop();
				}
			}
		}
		else if (str[i] == ']' && !st.empty() && st.top() == '[')
		{
			st.pop();
			if (str[i - 1] == '[')
			{
				tempVal += 3;
				stack<char> temp = st;
				while (!temp.empty())
				{
					if (temp.top() == '(')
						tempVal *= 2;
					else if (temp.top() == '[')
						tempVal *= 3;
					temp.pop();
				}
			}
		}

		//
		else if (str[i] == ')')
		{
			if (st.empty() || st.top() != '(')
			{
				cout << 0 << "\n";
				return 0;
			}
		}
		else if (str[i] == ']')
		{
			if (st.empty() || st.top() != '[')
			{
				cout << 0 << "\n";
				return 0;
			}
		}
		answer += tempVal;
	}
	if (!st.empty())
	{
		cout << "0\n";
		return 0;
	}
	cout << answer;
}