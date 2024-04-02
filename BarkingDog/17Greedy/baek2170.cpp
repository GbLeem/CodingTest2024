#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> p[1000002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> p[i].first >> p[i].second;

	sort(p, p + n); //1 3, 2 5, 3 5, 6 7

	int last = p[0].second; //3
	int ans = p[0].second - p[0].first; //2

	for (int i = 1; i < n; ++i)
	{
		if (last < p[i].second) //3 < 5
		{
			ans += (p[i].second - p[i].first); //2
			if (p[i].first < last)
				ans -= (last - p[i].first);
			last = p[i].second;
		}
	}
	cout << ans;
}