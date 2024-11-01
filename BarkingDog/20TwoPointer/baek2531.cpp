#include <iostream>
#include <algorithm>
using namespace std;

int n, d, k, c;
int board[30'002];
int cnt[3002];
int answer = 0;

int main()
{
	cin >> n >> d >> k >> c; //n개, d가지, 연속k개, 쿠폰 번호

	for (int i = 0; i < n; ++i)
	{
		cin >> board[i]; // 7 9 7 30 2 7 9 25
	}	

	int en = 0;
	for (int st = 0; st < n; ++st)
	{		
		int ans = 0;
		while (en < st + k - 1)
		{
			if (cnt[en] == 0) //방문 안된 경우
			{
				ans++;
				cnt[en] = 1;
			}
			en++;

			if (en == n)
				en %= n;
		}
		if (cnt[c] == 0)
			ans++;		
		cnt[st] = 0;
		cout << ans << "\n";
		answer = max(answer, ans);
	}
	//cout << answer;
}