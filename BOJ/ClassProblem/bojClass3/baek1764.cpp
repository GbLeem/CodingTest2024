#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	int size = N + M;
	vector<string> sum(N + M);
	vector<string> ans;

	for (int i = 0; i < N; ++i)
	{
		cin >> sum[i];
	}

	for (int i = N; i < N + M; ++i)
	{
		cin >> sum[i];
	}
	sort(sum.begin(), sum.end());

	for (int i = 0; i < size - 1; ++i)
	{
		if (sum[i] == sum[i + 1])
		{
			ans.push_back(sum[i]);
		}
	}

	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << "\n";
}