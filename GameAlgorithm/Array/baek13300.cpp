#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	int S, Y;
	int  answer = 0;
	int arr[2][6] = { 0, };

	cin >> N >> K;

	while (N--)
	{
		cin >> S >> Y;
		arr[S][Y - 1]++;
	}
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			if (arr[i][j] > 0 && arr[i][j] <= K)
				answer++;
			else if (arr[i][j] > K)
			{
				answer++;
				while (arr[i][j] > K)
				{
					answer++;
					arr[i][j] -= K;
				}
			}
		}
	}
	cout << answer;
}