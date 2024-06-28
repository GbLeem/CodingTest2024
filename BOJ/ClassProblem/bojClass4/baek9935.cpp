//문자열 폭발

//O(n^3)?
#include <iostream>
#include <string>
using namespace std;

bool finds2(string &s1, string s2)
{
	int s2size = s2.size();
	bool ok = true;

	for (int i = 0; i < s1.size(); ++i)
	{
		if (s1[i] == s2[0])
		{
			for (int s = 1; s < s2size; ++s)
			{
				if (s + i >= s1.size())
				{
					ok = false;
					break;
				}
				if (s1[i + s] != s2[s])
				{
					ok = false;
					break;
				}
			}
			if (ok)
			{
				s1.erase(i, s2size);				
				return true;
			}
			ok = true;
		}
	}
	return false;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s1;
	string s2;

	cin >> s1 >> s2;

	while (!s1.empty())
	{
		if (!finds2(s1, s2))
			break;
	}

	if (s1.empty())
		cout << "FRULA";
	else
		cout << s1;
	
}