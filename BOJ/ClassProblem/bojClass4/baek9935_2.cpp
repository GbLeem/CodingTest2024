#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s1;
	string s2;
	
	cin >> s1 >> s2;	

	for (int i = 0; i < s1.size(); ++i)
	{
		int cnt = 0;
		if (cnt <= s2.size())
		{
			for (int s = 0; s < s2.size(); ++s)
			{
				if (s1[i + s] != s2[s])
					break;
				else
					cnt++;
			}
			if (cnt == s2.size()) //다 찾으면
			{
				s1.erase(i, s2.size());
				i -= s2.size();
				if (i < 0)
					i = -1;
			}				
		}
	}
	if (s1.empty())
		cout << "FRULA";
	else
		cout << s1;	
}