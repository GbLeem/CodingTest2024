#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

int k, l;
unordered_map<string, int> um;

bool cmp(pair<string, int> a, pair<string, int>b)
{
	return a.second < b.second;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> k >> l;

	for (int i = 0; i < l; ++i)
	{	
		string id;
		cin >> id;
		
		if (um.find(id) != um.end())
		{
			um[id] = i;
		}
		else
			um.insert({ id, i });
	}
	
	vector<pair<string, int>> vec(um.begin(), um.end());
	sort(vec.begin(), vec.end(), cmp);

	int val = (k < vec.size()) ? k : vec.size();
	for (int i = 0; i < val; ++i)
	{
		cout << vec[i].first << "\n";
	}
}