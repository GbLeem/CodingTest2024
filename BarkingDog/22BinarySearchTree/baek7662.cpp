#include <iostream>
#include <string>
#include <set>
using namespace std;

int T, k;
string query;
int num;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--)
	{
		cin >> k;

		multiset<int> s;
		while (k--)
		{
			cin >> query >> num;
			
			if (query == "D")
			{
				if (s.empty())
					continue;
				if (num == 1)
					s.erase(prev(s.end()));
				if (num == -1)
					s.erase(s.begin());
			}
			else
			{
				s.insert(num);
			}
		}
		if (s.empty())
			cout << "EMPTY\n";
		else
		{
			cout << *prev(s.end()) << " " << *s.begin() << "\n";
		}
	}
}