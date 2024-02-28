#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 1; i <= 2 * N - 1; ++i)
	{
		if (i < N)
		{
			for (int j = 1; j <= i; ++j)
				cout << "*";
			for (int j = 1; j <= 2 * (N - i); ++j)
				cout << " ";
			for (int j = 1; j <= i; ++j)
				cout << "*";
		}
		else if (i == N)
		{
			for (int j = 1; j <= 2 * N; ++j)
				cout << "*";
		}
		else
		{
			int index = i % N; //1 2 3 4
			for (int j = 1; j <= N - index; ++j)
				cout << "*";
			for (int j = 1; j <= 2 * index ; ++j)
				cout << " ";
			for (int j = 1; j <= N - index; ++j)
				cout << "*";
		}
		cout << "\n";
	}
}