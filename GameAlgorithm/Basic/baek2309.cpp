#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int num[9];
vector<int> ans;
int sum = 0;

int main()
{
	for (int i = 0; i < 9; ++i)
	{
		cin >> num[i];
	}

	sort(num, num + 9);



		
	for (const auto a : ans)
		cout << a << "\n";
}