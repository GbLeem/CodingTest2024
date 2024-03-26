#include <iostream>
#include <vector>
using namespace std;

int n, k;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	vector<bool> vec(n + 2); //
	
	fill(vec.begin(), vec.end(), true); 
	int temp = 0;
	vec[1] = false;

	for (int i = 2; i <= n; ++i)
	{
		if (!vec[i])
			continue;
		for (int j = i; j <= n; j += i) 
		{
			if (vec[j])
			{
				vec[j] = false;
				temp++;
				if (temp == k)
				{
					cout << j;
					return 0;
				}
			}
		}
	}
}