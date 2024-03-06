#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	map<int, string> m1;
	map<string, int> m2;
	for (int i = 0; i < N; ++i)
	{
		string name;
		cin >> name;
		m1.insert({ i + 1, name });
		m2.insert({ name, i + 1 });
	}

	for (int i = 0; i < M; ++i)
	{
		string test;
		cin >> test;

		if (isdigit(test[0]))
		{
			cout << m1[stoi(test)] << "\n";
		}
		else
		{
			cout << m2[test] << "\n";
		}
	}
}