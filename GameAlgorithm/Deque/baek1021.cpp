#include <iostream>
#include <deque>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	int answer = 0;
	cin >> N >> M;

	deque<int> dq;
	for (int i = 0; i < N; ++i)
	{
		dq.push_back(i + 1);
	}
	

	while (M--)
	{
		int num;
		cin >> num; //1 2 3
		deque<int>::iterator it = dq.begin();

		while (*it != num)
		{
			if (num > dq.size() / 2) //왼쪽
			{
				it--;
				if (it == dq.begin())
					it = dq.end();
			}
			else //오른쪽
			{
				it++;
				if (it == dq.end())
					it = dq.begin();
			}
			answer++;
		}
		dq.erase(it);
	}
	cout << answer;
}