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
		int frontVal = dq.front();
		
		while (frontVal != num)
		{
			int index = 0;
			for (int i = 0; i < dq.size(); ++i)
			{
				if (num == dq[i])
					index = i;
			}
			if (index <= dq.size()/2) //왼쪽
			{				
				int temp = dq.front();
				dq.pop_front();
				dq.push_back(temp);			
			}
			else //오른쪽
			{
				int temp = dq.back();
				dq.push_front(temp);
				dq.pop_back();
			}
			frontVal = dq.front();			
			answer++;
		}
		dq.pop_front();
	}
	cout << answer;
}