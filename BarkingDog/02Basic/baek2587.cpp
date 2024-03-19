#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int count = 5;
	int num;
	int sum = 0;
	vector<int> vec;

	while (count--)
	{
		cin >> num;
		sum += num;
		vec.push_back(num);
	}

	sort(vec.begin(), vec.end());

	cout << sum / 5 << "\n" << vec[2];
}
