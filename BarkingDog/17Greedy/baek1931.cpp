//지금 손해여도 나중에 이득인가?

#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> a[100005];

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	
	for(int i = 0; i < N; ++i)
	{
		cin >> a[i].first >> a[i].second; //시작 끝
	}
	sort(a, a + N, cmp);

	int ans = 0;
	int temp = 0;

	for (int i = 0; i < N; ++i)
	{
		if (temp > a[i].first)
			continue;
		ans++;
		temp = a[i].second;
	}
	cout << ans;
}