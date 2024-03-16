#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string arr[1002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	int index = 0;
	string temp = "";
	for (int i = 0; i < s.size(); ++i)
	{
		temp.clear();
		for (int j = index; j < s.size(); ++j)
		{
			temp += s[j];
		}
		index++;
		arr[i] = temp;
	}
	sort(arr, arr + s.size());

	for (int i = 0; i < s.size(); ++i)
		cout << arr[i] << "\n";
}