#include <iostream>
using namespace std;

int n, m;
int ans = 100;
string board[55];

string W[8] = { "WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW" };
string B[8] = { "BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB" };

int Bcheck(int x, int y)
{	
	int cnt = 0;	
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{	
			if (board[x+i][y+j] != B[i][j])
				cnt++;
		}
	}
	return cnt;
}

int Wcheck(int x, int y)
{
	int cnt = 0;
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (board[x+i][y+j] != W[i][j])
				cnt++;
		}
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		cin >> board[i];
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int temp = 0;
			if (i + 8 <= n && j + 8 <= m)
			{
				temp = min(Bcheck(i, j), Wcheck(i, j));

				if (ans > temp)
					ans = temp;
			}
		}
	}

	cout << ans;	
}