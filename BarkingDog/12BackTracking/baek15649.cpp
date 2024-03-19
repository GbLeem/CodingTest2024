#include <iostream>
using namespace std;

int arr[10];
bool isused[10]; //특정 수가 쓰였는지 안쓰였는지 
int n, m;

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
			isused[i] = 1;
			func(k + 1);
			isused[i] = 0;
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