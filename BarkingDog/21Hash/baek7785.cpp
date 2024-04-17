#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	unordered_set<string> us;

	for (int i = 0; i < n; ++i)
	{
		string name, state;
		cin >> name >> state;
		
		if (state == "enter")
			us.insert(name);
		else
			us.erase(name);
	}
	vector<string> v(us.begin(), us.end());	
	sort(v.begin(), v.end(), greater<string>());
	for (auto vi : v)
		cout << vi << "\n";
}
