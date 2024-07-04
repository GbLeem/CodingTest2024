#include <iostream>
#include <algorithm>
using namespace std;

int n;
int len = 0;
int a[1005];

int main()
{	
	//Binary Search
	//a를 빈 배열에서 부터 구성하는 식으로 구현
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int num;
		cin >> num;

		auto pos = lower_bound(a + 1, a + len + 1, num); //같거나 큰 숫자가 처음 등장하는 위치
		
		*pos = num;
		if (pos == a + len + 1)
			len++;
	}
	cout << len;
	return 0;
}