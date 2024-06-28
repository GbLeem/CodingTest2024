#include <iostream>
#include <string>
#include <stack>
using namespace std;

string s1, s2;
string temp;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s1 >> s2;

	stack<char> st;
	for (int i = 0; i < s1.size(); ++i)
	{
		temp += s1[i];
		if (temp.back() == s2.back())
		{
			bool flag = true;
			if (temp.size() < s2.size())
				continue;
			for (int j = 0; j < s2.size(); ++j)
			{
				if (temp[temp.size() - s2.size() + j] != s2[j]) //같지 않다.
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				for (int j = 0; j < s2.size(); ++j)
				{
					temp.pop_back();
				}
			}
		}
	}
	
	if (temp.empty())
		cout << "FRULA";
	else
		cout << temp;
}