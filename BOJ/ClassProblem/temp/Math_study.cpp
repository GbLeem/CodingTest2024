//약수
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;

vector<int> divisor(int n)
{
	vector<int> div;

	for (int i = 1; i * i <= n; ++i)
	{
		if (n % i == 0)
			div.push_back(i); // 1 2 3 4
	}
	for (int j = (int)div.size() - 1; j >= 0; --j)
	{
		if (div[j] * div[j] == n)
			continue;
		div.push_back(n / div[j]);
	}
	return div;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	/*for (int i = 1; i * i <= n; ++i)
	{
		if (i * i == n)
			vec.push_back(i);
		else if (n % i == 0)
		{
			vec.push_back(i);
			vec.push_back(n / i);
		}
	}

	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << "\n";
	}*/
	vector<int> ans = divisor(10);

	for (auto a : ans)
		cout << a << "\n";
}