#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < 2 * N - 1; ++i)
	{
		if (i < N)
		{
			for (int j = 0; j < N - i - 1; ++j)
				cout << " ";
			for (int j = 0; j < 2 * (i + 1) - 1; ++j)
				cout << "*";			
		}
		else
		{
			for (int j = 0; j < i - N + 1 ; ++j)
				cout << " ";
			int index = i % N; // 0 1 2 3
			for (int j = 0; j < 2 * (N - index - 1) - 1; ++j)
				cout << "*";
		}
		cout << "\n";
	}
}