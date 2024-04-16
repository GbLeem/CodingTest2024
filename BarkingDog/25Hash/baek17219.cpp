#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int n, m;
unordered_map<string, string> um;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		string add, pass;
		cin >> add >> pass;
		um.insert({ add, pass });
	}

	for (int i = 0; i < m; ++i)
	{
		string q;
		cin >> q;
		cout << um[q] << "\n";
	}
}