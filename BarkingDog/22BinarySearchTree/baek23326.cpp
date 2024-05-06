#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n, q;
set<int> s;
int c = 1;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
	{
		int num;
		cin >> num;

		if (num == 1)		
			s.insert(i); // 2 5		
	}

	while (q--)
	{
		int query;
		cin >> query;

		if (query == 1)
		{
			int num;
			cin >> num;

			if (s.find(num) != s.end())//Ã£À¸¸é
				s.erase(num);
			else
				s.insert(num);	
		}
		else if (query == 2)
		{
			int num;
			cin >> num;

			c = (c + num - 1) % n + 1;
		}
		else //3
		{			
			int ans = 0;
			if (s.empty())
				cout << -1 << "\n";
			else
			{
				auto it = s.lower_bound(c);

				if (it == s.end())
					cout << n - c + *s.begin() << "\n";
				else
					cout << *it - c << "\n";
			}
		}
	}
}