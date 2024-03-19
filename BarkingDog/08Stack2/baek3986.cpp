#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	int answer = 0;

	while (N--)
	{
		string str;
		cin >> str;
		stack<char>st;

		for (int i = 0; i < str.size(); ++i)
		{
			if (st.empty())
				st.push(str[i]);
			else
			{
				if (str[i] == 'A' && st.top() == 'A')
					st.pop();
				else if (str[i] == 'B' && st.top() == 'B')
					st.pop();
				else
					st.push(str[i]);
			}
		}			
		if (st.empty())
			answer++;
	}
	cout << answer;
}