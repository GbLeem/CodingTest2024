#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;
	vector<int> vec(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> vec[i];
	}
	int count = 0;
	
	for (int i = vec.size() - 1; i >= 0; --i)
	{
		if (K == 0)
		{
			cout << count;
			return 0;
		}
		if (K >= vec[i])
		{
			int minus = vec[i];
			while (K >= minus)
			{
				K -= minus;
				count++;
			}
		}
	}	
	cout << count;
 }