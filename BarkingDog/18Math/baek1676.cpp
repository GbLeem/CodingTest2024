#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	int ans = n / 5;
	int temp1 = n / 25;
	int temp2 = n / 125;

	cout << ans + temp1 + temp2;
}