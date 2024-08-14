//갑자기 생각나서
//boj 15486 : DP

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int board[1500005][2];
long long d[15000005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> board[i][0] >> board[i][1]; //걸리는 시간, 금액
	}

	for (int i = n; i >= 1; --i)
	{
		if (board[i][0] + i <= (n + 1)) //걸릴시간 + 현재 시간 <= 퇴사일
		{
			//i일에 해당 상담을 하여, 해당 날짜의 이익 + 상담 끝난 날의 d값 VS i+1일의 d값
			d[i] = max(d[i + board[i][0]] + board[i][1], d[i + 1]);
		}
		//일 못하면 i일의 d값은 i+1값과 같음
		else
			d[i] = d[i + 1];
	}
	cout << *max_element(d, d + n + 1);
}