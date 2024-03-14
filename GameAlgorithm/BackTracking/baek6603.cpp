#include <iostream>
using namespace std;

int s, k;
int arr[100];
int num[100];
bool isused[100];

void func(int cur, int index)
{
	if (cur == 6)
	{
		for (int i = 0; i < 6; ++i)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = index; i < s; ++i)
	{
		if (!isused[i])
		{
			arr[cur] = num[i]; 
			isused[i] = 1;
			func(cur + 1, i + 1);
			isused[i] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	s = 1;
	while (s != 0)
	{
		cin >> s;
		fill(num, num + s, 0);
		for (int i = 0; i < s; ++i)
			cin >> num[i];
		func(0, 0);
		cout << "\n";
	}
}