#include <iostream>
#include <algorithm>
using namespace std;

int n;
int board[1500005][2];
long long d[1500005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)	
		cin >> board[i][0] >> board[i][1]; //기간, 금액
	
	for (int i = n; i >= 1; --i)
	{
		if (board[i][0] + i <= n + 1) //퇴사전에 끝내기
		{
			d[i] = max(d[i + board[i][0]] + board[i][1], d[i + 1]); //상담을 했을때, 안했을때
		}
		else
			d[i] = d[i + 1];
	}
	cout << *max_element(d, d + n + 1);
}