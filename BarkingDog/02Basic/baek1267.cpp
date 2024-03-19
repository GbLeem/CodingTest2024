#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	int value[22] = { 0, };
	int temp[22] = { 0, };
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> value[i];
		temp[i] = value[i];
	}
	
	int first = 0, second = 0;

	for (int i = 0; i < N; ++i)
	{
		while (value[i] >= 0)
		{
			value[i] -= 30;
			first += 10;
		}

		while (temp[i] >= 0)
		{
			temp[i] -= 60;
			second += 15;
		}
	}

	if (first < second)
		cout << "Y " << first << "\n";
	else if (first > second)
		cout << "M " << second << "\n";

	else
		cout << "Y M " << first << "\n";	
}