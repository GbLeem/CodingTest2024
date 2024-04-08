#include <iostream>
#include <vector>
using namespace std;

vector<bool>state(4000002, true);

void sieve(int n)
{
	state[1] = false; 
	for (int i = 2; i * i <= n; ++i)
	{
		if (state[i] == false)
			continue;
		for (int j = 2 * i; j <= n; j += i)
			state[j] = false;
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	sieve(n);

	int sum = 2;
	int cnt = 0;
	int en = 2;
	bool ok = false;
	
	for (int st = 2; st <= n; ++st)
	{
		if (state[st])
		{
			while (en <= n && sum < n)
			{
				en++;
				if (state[en])
				{
					if (en > n)
						break;
					sum += en;
					if (sum == n)
					{
						ok = true;
						break;
					}
				}
			}
			if (sum == n || ok)
			{
				ok = false;
				cnt++;
			}
			sum -= st;
		}
	}
	cout << cnt;
}