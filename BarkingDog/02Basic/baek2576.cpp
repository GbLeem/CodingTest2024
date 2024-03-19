#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int count = 7;
	int sum = 0;
	int num;
	vector<int> vec;
	while (count--)
	{
		cin >> num;
		if (num % 2 != 0)
			vec.push_back(num);
	}

	if (vec.empty())
	{
		cout << -1 << "\n";
		return 0;
	}

	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); ++i)
	{
		sum += vec[i];
	}
	cout << sum << "\n" << vec[0] << "\n";

	return 0;
}