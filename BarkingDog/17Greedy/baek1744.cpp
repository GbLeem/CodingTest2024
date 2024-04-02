#include <iostream>
#include <algorithm>
using namespace std;

int arr[52];
int m[52];
int p[52];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	sort(arr, arr + n);

	//-1 1 2 3 4

	//0 1 2 3 4 5 

	//-1
	int ans = 0;
	int cnt1 = 0;
	int cnt2 = 0;
	int i1 = 0;
	int i2 = 0;
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] < 0)
		{
			cnt1++;
			m[i1] = arr[i];
			i1++;
		}
		else
		{
			cnt2++;
			m[i2] = arr[i];
			i2++;
		}
	}
	
	if (i1 % 2 == 0)//짝수
	{
		for (int i = 0; i < i1; i+=2)
		{
			ans += m[i] * m[i + 1];
		}
	}
	else
	{
		for (int i = 0; i < i1 - 1; i += 2)
			ans += m[i] * m[i + 1];
		ans += m[i1 - 1];
	}

	while (i1 > 1)
	{
		ans += p[i1] * p[i1 - 1];
		i1--;
	}
	if(i1==1)

}