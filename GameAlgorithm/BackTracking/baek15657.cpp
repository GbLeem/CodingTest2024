#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int num[10];
int arr[10];

void func(int cur)
{
	if (cur == m)
	{
		for (int i = 0; i < m; ++i)
			cout << num[arr[i] - 1] << " ";
		cout << "\n";
		return;
	}

	int index = 1;
	if (cur != 0)
		index = arr[cur - 1];

	for (int i = index; i <= n; ++i)
	{	
		arr[cur] = i;
		func(cur + 1);		
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> num[i];

	sort(num, num + n);
	func(0);
}