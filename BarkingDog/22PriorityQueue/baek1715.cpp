//허프만 코딩

#include <iostream>
#include <queue>
using namespace std;

int n;
int ans = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;	
	priority_queue<int, vector<int>, greater<int>> pqi;

	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		pqi.push(num);		
	}

	//10 20 40
	while (pqi.size() > 1)
	{
		int a = pqi.top();
		pqi.pop();
		int b = pqi.top();
		pqi.pop();

		ans += (a + b);
		pqi.push(a + b);
	}

	cout << ans;
}