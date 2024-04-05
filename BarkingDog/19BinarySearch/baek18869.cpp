#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n;
int arr[105][10005];

void compress(int *a)
{
	vector<int> temp(n);
	for (int i = 0; i < n; ++i)	
		temp.push_back(a[i]);
	sort(temp.begin(), temp.end());
	temp.erase(unique(temp.begin(), temp.end()), temp.end());
	
	for (int i = 0; i < n; ++i)
	{
		a[i] = lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin();
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> arr[i][j];
		}
	}
	
	int ans = 0;

	for (int i = 0; i < m; ++i)
		compress(arr[i]);

	for (int i = 0; i < m - 1; ++i)
	{
		for (int j = i + 1; j < m; ++j)
		{
			int temp = 0;
			for (int k = 0; k < n; ++k)
			{
				if (arr[i][k] == arr[j][k])
					temp++;
			}			
			if (temp == n)
				ans++;
		}
	}
	cout << ans;
}