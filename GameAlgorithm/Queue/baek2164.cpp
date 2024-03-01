#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	queue<int>q;

	for (int i = 0; i < N; ++i)
	{
		q.push(i + 1);
	}

	while (1)
	{
		if (q.size() == 1)
			break;
		q.pop();
		int temp = q.front();
		q.pop();
		q.push(temp);
	}
	cout << q.front();
}