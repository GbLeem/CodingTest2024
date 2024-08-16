#include <iostream>
#include <algorithm>
using namespace std;

int n;
int board[1002][4];
int d[1002][4]; //r g b

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cin >> board[i + 1][j + 1];
		}
	}

	//k번째 집 
	d[1][1] = board[1][1]; //r
	d[1][2] = board[1][2]; //g
	d[1][3] = board[1][3]; //b 로 색칠할떄의 값

	for (int i = 2; i <= n; ++i)
	{
		d[i][1] = min(d[i - 1][2], d[i - 1][3]) + board[i][1];
		d[i][2] = min(d[i - 1][1], d[i - 1][3]) + board[i][2];
		d[i][3] = min(d[i - 1][1], d[i - 1][2]) + board[i][3];
	}	
	cout << *min_element(d[n] + 1, d[n] + 4);

}