//중복 제외 나보다 작은 것들 몇개인지

//2 4 -10 4 -9
//2 3  0  3  1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int a[1000005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> temp, ans;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];	
		temp.push_back(a[i]);
	}

	sort(temp.begin(), temp.end()); // -10, -9, 2 4 4 

	for (int i = 0; i < n; ++i)
	{
		if (i == 0 || temp[i - 1] != temp[i])
			ans.push_back(temp[i]); //-10 -9 2 4
	}
	
	for (int i = 0; i < n; ++i)
		cout << lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin() << " ";

	//STL
	//sort(temp.begin(), temp.end());
	//temp.erase(unique(temp.begin(), temp.end()), temp.end()); //중복제거
	//for (int i = 0; i < n; ++i)
	//	cout << lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin() << " ";
}