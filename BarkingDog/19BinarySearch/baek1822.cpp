#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int a[500005];
int b[500005];
vector<int> vec;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < m; ++i)
		cin >> b[i];

	sort(b, b + m);

	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		if (!binary_search(b, b + m, a[i]))
		{
			vec.push_back(a[i]);
			cnt++;
		}
	}
	
	cout << cnt;
	sort(vec.begin(), vec.end());
	if (cnt > 0)
	{
		cout << "\n";
		for (auto v : vec)
			cout << v << " ";
	}
}