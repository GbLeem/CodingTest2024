//배낭문제
#include <iostream>
using namespace std;

pair<int, int> p[105];
int value[105][100005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		cin >> p[i].first >> p[i].second;
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= k; ++j)
		{
			//현재 무게, 가치
			int w = p[i].first;
			int v = p[i].second;

			if (w > j)
				value[i][j] = value[i - 1][j];
			else
				value[i][j] = max(value[i - 1][j], value[i - 1][j - w] + v);			
		}
	}
	cout << value[n][k];
}