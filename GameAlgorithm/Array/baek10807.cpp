#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, v;
	int answer = 0;
	cin >> N;

	int* arr = new int[N];

	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}
	cin >> v;

	for (int i = 0; i < N; ++i)
	{
		if (arr[i] == v)
			answer++;
	}
	cout << answer;
}