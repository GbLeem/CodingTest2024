//BOJ 15688
#include <iostream>
using namespace std;

int arr[2000002];
int N;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int num;
		cin >> num;
		
		arr[num + 1000000]++;
	}
	for (int i = 0; i <=2000000; ++i)
	{
		while (arr[i] > 0)
		{
			cout << i - 1000000 << "\n";
			arr[i]--;
		}
	}
}


//수의 범우가 작을때 쓰면 개이득임