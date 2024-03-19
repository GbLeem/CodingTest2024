#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int t, n, m;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	
	while (t--)
	{
		cin >> n >> m; //A B
		vector<int> arr1(n);
		vector<int> arr2(m);

		for (int i = 0; i < n; ++i)		
			cin >> arr1[i];
		
		for (int i = 0; i < m; ++i)
			cin >> arr2[i];

		sort(arr1.begin(), arr1.end(), greater<int>()); //8 7 3 1 1
		sort(arr2.begin(), arr2.end(), greater<int>()); //6 3 1

		int cnt = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (arr1[i] > arr2[j])
				{
					cnt += m - j;
					break;
				}
			}
		}

		cout << cnt << "\n";
	}	
}