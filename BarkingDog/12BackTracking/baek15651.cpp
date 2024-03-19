#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int arr[100];
int isused[100];

void func(int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; ++i)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; ++i)
	{
		if (!isused[i])
		{
			arr[k] = i;
			func(k + 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	func(0);	
}