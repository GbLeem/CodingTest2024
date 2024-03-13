#include <iostream>
using namespace std;

int s=1, k;
int arr[100];
int num[100];
bool isused[100];

void func(int cur)
{
	if (cur == s)
	{
		for (int i = 0; i < s; ++i)
			cout << num[arr[i]-1] << " ";
		cout << "\n";
		return;
	}

	int index = 0;
	if (cur != 0)
	{
		index = arr[cur - 1] + 1;
	}
	for (int i = index; i < s; ++i)
	{
		if (!isused[i])
		{
			arr[cur] = i;
			isused[i] = 1;
			func(cur + 1);
			isused[i] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	fill(num, num + s, 0);
	for (int i = 0; i < s; ++i)
		cin >> num[i];
	func(0);
}