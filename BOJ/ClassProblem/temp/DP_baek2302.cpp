#include <iostream>
using namespace std;

int n, m;
int board[42];
int d[42]; //가짓수
int answer = 1;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int fixed;
		cin >> fixed;
		board[fixed] = 1; //board[4], board[7] 
	}
	
	d[0] = 1;
	d[1] = 1;
	d[2] = 2;	

	for (int i = 3; i <= 40; ++i)
		d[i] = d[i - 1] + d[i - 2];

	int temp = 0;
	for (int i = 1; i <= n; ++i)
	{					
		if (board[i] == 1)
		{
			answer *= d[temp];
			temp = 0;
		}
		else
			temp++;
	}
	if (temp != 0)
		answer *= d[temp];

	cout << answer;
}