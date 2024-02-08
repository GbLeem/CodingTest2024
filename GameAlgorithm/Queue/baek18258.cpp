#include <iostream>
#include <queue>
using namespace std;

int N;
string order;
int num;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	queue<int> q;

	while (N--)
	{
		cin >> order;

		if (order == "push")
		{
			cin >> num;
			q.push(num);
		}
		else if (order == "pop")
		{
			if (!q.empty())
			{
				cout << q.front() << "\n";
				q.pop();
			}
			else
				cout << -1 << "\n";
		}
		else if (order == "size")
		{
			cout << q.size() << "\n";
		}
		else if (order == "empty")
		{
			cout << q.empty() << "\n";
		}
		else if (order == "front")
		{
			if (q.empty())
				cout << -1 << "\n";
			else
				cout << q.front() << "\n";
		}
		else if (order == "back")
		{
			if (q.empty())
				cout << -1 << "\n";
			else
				cout << q.back() << "\n";
		}
	}
}