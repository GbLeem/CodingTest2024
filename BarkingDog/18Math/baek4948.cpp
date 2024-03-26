#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n = 1;

	while (1)
	{
		cin >> n;
		if (n == 0)
			break;
		vector<bool> vec(2 * n + 2);
		fill(vec.begin(), vec.end(), true);

		vec[1] = false;

		for (int i = 2; i * i <= 2 * n; ++i)
		{
			if (!vec[i])
				continue;
			for (int j = 2 * i; j <= 2*n; j += i)
				vec[j] = false;
		}

		int ans = 0;
		for (int i = n + 1; i <= 2 * n; ++i)
		{
			if (vec[i]) //true
				ans++;
		}
		cout << ans << "\n";
	}
}