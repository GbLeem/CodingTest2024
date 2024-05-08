#include <iostream>
#include <queue>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> minpq;
priority_queue<int> maxpq; //min

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		
		if (minpq.size() >= maxpq.size())
			maxpq.push(num);
		else
			minpq.push(num);
		if (!minpq.empty() && minpq.top() < maxpq.top())
		{
			minpq.push(maxpq.top());
			maxpq.pop();
			maxpq.push(minpq.top());
			minpq.pop();
		}

		cout << maxpq.top() << "\n";
		
	}
}

//1
//1 5
//1 2 5
//1 2 5 10
//-99 1 2 5 10
//-99 1 2 5 7 10
//-99 1 2 5 5 7 10