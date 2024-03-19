#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int arr[10] = { 0, }; 
	int N;
	cin >> N;

	while (N > 0)
	{		
		arr[N % 10]++;
		N /= 10;
	}

	arr[6] = arr[6] + arr[9];
	arr[6] = ceil(arr[6] / 2.);
	arr[9] = 0;

	int max = 0;
	for (int i = 0; i < 10; ++i)
	{
		if (max < arr[i])
			max = arr[i];
	}
	cout << max << "\n";
}