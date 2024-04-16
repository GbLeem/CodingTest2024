#include <iostream>
#include <unordered_map>
using namespace std;

int n, m;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	while (n--)
	{
		cin >> m;

		unordered_map<string, int> um; //category, number

		for (int i = 0; i < m; ++i)
		{
			string name, category;
			cin >> name >> category;

			if (um.find(category) != um.end())
			{
				um[category] += 1;
			}
			else
				um[category] = 1;
		}
		
		int ans = 1;

		for (auto u : um)
			ans *= u.second + 1;
		cout << ans - 1 << "\n";
	}
}