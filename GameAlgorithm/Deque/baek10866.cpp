#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	deque<int> dq;

	while (N--)
	{
		string str;
		cin >> str;

		if (str == "push_front")
		{
			int num;
			cin >> num;

			dq.push_front(num);
		}
		else if (str == "push_back")
		{
			int num;
			cin >> num;

			dq.push_back(num);
		}
		else if (str == "pop_front")
		{
			if (!dq.empty())
			{
				cout << dq.front() << "\n";
				dq.pop_front();
			}
			else
				cout << -1 << "\n";
		}
		else if (str == "pop_back")
		{
			if (!dq.empty())
			{
				cout << dq.back() << "\n";
				dq.pop_back();
			}
			else
				cout << -1 << "\n";
		}
		else if (str == "size")
		{			
			cout << dq.size() << "\n";			
		}
		else if (str == "empty")
		{
			cout << dq.empty() << "\n";
		}
		else if (str == "front")
		{
			if (!dq.empty())
				cout << dq.front() << "\n";
			else
				cout << -1 << "\n";
		}
		else if (str == "back")
		{
			if (!dq.empty())
				cout << dq.back() << "\n";
			else
				cout << -1 << "\n";
		}
	}
}