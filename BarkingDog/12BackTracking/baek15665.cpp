#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int num[10];
int arr[10];
bool isused[10];

//중복을 허용해야한다.
void func(int cur)
{
	if (cur == m)
	{
		for (int i = 0; i < m; ++i)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	int temp = 0;

	for (int i = 0; i < n; ++i)
	{
		if (temp != num[i])
		{
			arr[cur] = num[i];
			temp = num[i];
			func(cur + 1);
		}
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