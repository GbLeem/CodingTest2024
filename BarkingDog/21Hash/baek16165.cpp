#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n, m;
unordered_multimap<string, string> um; //key : group, val : name
vector<pair<string, string>> vec;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		string group;
		int num;
		cin >> group;
		cin >> num;

		for (int j = 0; j < num; ++j)
		{
			string name;
			cin >> name;
			um.insert({ group, name });
		}
	}

	for (int i = 0; i < m; ++i)
	{
		string q;
		int n;
		cin >> q;
		cin >> n;

		if (n == 1)
		{
			for (auto u : um)
			{
				if (u.second == q)
				{
					cout << u.first << "\n";
					break;
				}
			}
		}
		else
		{			
			vector<string> tempName;
			for (auto u : um)
			{
				if (u.first == q)
					tempName.push_back(u.second);
			}
			sort(tempName.begin(), tempName.end());
			for (auto t : tempName)
				cout << t << "\n";
		}
	}
}

//이거 참고해야지
//int main(void) 
// {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int N, M, mems;
//	string team, member;
//	unordered_map<string, string> m2t; //-> 이름이 키, 팀이름이 값
//	unordered_map<string, vector<string>> t2m; // -> 팀이름이 키, 이름이 값
//	cin >> N >> M;
//	while (N--) 
// {
//		cin >> team >> mems;
//		while (mems--) 
//		{
//			cin >> member;
//			m2t[member] = team;
//			t2m[team].push_back(member);
//		}
//		sort(t2m[team].begin(), t2m[team].end());
//	}
//
//	int c;
//	string quiz;
//	while (M--) 
//	{
//		cin >> quiz >> c;
//		if (c)
//			cout << m2t[quiz] << '\n';
//		else
//			for (string m : t2m[quiz]) cout << m << '\n';
//	}
//}