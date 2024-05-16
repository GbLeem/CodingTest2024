//파도반 수열
#include <iostream>
using namespace std;

int t, n;
long long d[105];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	d[1] = 1;
	d[2] = 1;
	d[3] = 1;

	d[4] = 2;
	d[5] = 2;

	for (int i = 6; i <= 100; ++i)
	{
		d[i] = d[i - 1] + d[i - 5];
	}

	while (t--)
	{
		cin >> n;
		cout << d[n] << "\n";
	}
}

	//d[6] = 3; //d[5] + d[1];

	//d[7] = 4;

	//d[8] = 5; //d[7] + d[3];

	//d[9] = 7; //d[8] + d[4];
	// 
	//d[10] = 9; //d[9] + d[5];