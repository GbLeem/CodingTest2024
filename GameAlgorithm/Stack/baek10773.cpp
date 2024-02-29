#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int K;
	stack<int> s;
	long long answer = 0;
	cin >> K;

	while (K--)
	{
		int num;
		cin >> num;

		if (num == 0)
			s.pop();
		else
			s.push(num);
	}
	while(!s.empty())
	{
		answer += s.top();
		s.pop();
	}
	cout << answer;
}