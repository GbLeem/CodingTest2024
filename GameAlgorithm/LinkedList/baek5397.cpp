#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	while (N--)
	{
		string str;
		cin >> str;

		list<char> ch;
		list<char>::iterator it = ch.begin();

		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i] == '<')
			{
				if (it != ch.begin())
				{
					--it;
				}
			}
			else if (str[i] == '>')
			{
				if (it != ch.end())
					++it;
			}
			else if (str[i] == '-')
			{
				if(it!=ch.begin())
					it = ch.erase(--it);
			}
			else
			{
				ch.insert(it, str[i]);
			}						
		}		
		for (list<char>::iterator it = ch.begin(); it != ch.end(); ++it)
		{
			cout << *it;
		}
		cout << "\n";
	}
}