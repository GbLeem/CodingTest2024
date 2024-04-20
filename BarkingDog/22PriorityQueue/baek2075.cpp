#include <iostream>
#include <queue>
using namespace std;

int n;
int num;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n*n; ++i)
	{
		cin >> num;
		pq.push(num);

		if (n < (int)pq.size())
			pq.pop();
	}	
	cout << pq.top();
}
