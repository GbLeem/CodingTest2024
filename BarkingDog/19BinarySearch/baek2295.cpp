//세수의 합
//a + b + c = list

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int a[1005];
vector<int> sum;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n);

	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < n; ++j)
		{
			sum.push_back(a[i] + a[j]);
		}
	}

	sort(sum.begin(), sum.end());

	int maxNum = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (binary_search(sum.begin(), sum.end(), a[i] - a[j]))
			{
				if (maxNum < a[i])
					maxNum = a[i];
			}
		}
	}
	cout << maxNum;
}