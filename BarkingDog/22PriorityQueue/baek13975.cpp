#include <iostream>
#include <queue>
using namespace std;

int t, k;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--)
	{
		cin >> k;
		priority_queue<long long, vector<long long>, greater<long long>> pq; //최소힙
		for (int i = 0; i < k; ++i)
		{
			int file;
			cin >> file;
			pq.push(file);
		}
		
		long long val = 0;

		while(1)
		{
			long long a = pq.top();
			pq.pop();
			long long b = pq.top();
			pq.pop();
			val += (a + b);
			if (pq.empty())
				break;
			pq.push(a + b);
		}
		cout << val << "\n";
	}
}