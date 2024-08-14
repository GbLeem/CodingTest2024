#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[1000005];
vector<int> vec;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		vec.push_back(arr[i]);
	}
	
	sort(vec.begin(), vec.end()); //-10 -9 2 4 4 

	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	for (int i = 0; i < n; ++i)
	{
		//찾고자 하는 것보다 같거나 큰 처음으로 발견된 위치(index)
		cout << lower_bound(vec.begin(), vec.end(), arr[i]) - vec.begin() << " ";
	}
}