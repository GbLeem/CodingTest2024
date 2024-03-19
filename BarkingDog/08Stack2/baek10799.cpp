#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;
	
	stack<char>st;
	int answer = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == '(')
		{
			st.push(str[i]);
		}
		else if (str[i] == ')' && st.top() == '(')
		{
			if (str[i - 1] == '(') //laser
			{
				st.pop();
				answer += st.size();
			}
			else //end of pipe
			{
				st.pop();
				answer++;
			}
		}
	}
	cout << answer;
}