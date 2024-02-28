#include <iostream>
#include <string>
#include <list>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;
	list<char> li;

	for (int i = 0; i < str.size(); ++i)
	{
		li.push_back(str[i]); //a b c d
	}

	int N;
	cin >> N;
	list<char>::iterator it = li.end();

	while (N--)
	{
		char st;
		cin >> st;

		if (st == 'L')
		{
			if(it != li.begin())
				it--;
		}
		else if (st  == 'D')
		{
			if (it != li.end())
				it++;
		}
		else if (st == 'B')
		{
			if(it != li.begin())
				it = li.erase(--it);
		}
		else if (st == 'P')
		{
			char s;
			cin >> s;
			li.insert(it, s);		
		}
	}

	for (list<char>::iterator it = li.begin(); it != li.end(); ++it)
	{
		cout << *it;
	}
}