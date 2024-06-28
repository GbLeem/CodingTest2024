//인류의 적 모기 퇴치

#include <iostream>
using namespace std;

int n, m;
int board[55][55];
int dx[4] = { -1, 1,-1,1 };
int dy[4] = { 1,1,-1,-1 };

int dx1[4] = { 1,0,-1,0 };
int dy1[4] = { 0,1,0,-1 };

int CountCross(int i, int j)
{
	int cnt = board[i][j];
	int nextValue[2] = { 0,0 };

	for (int dir = 1; dir <= m; ++dir)
	{
		for (int nxt = 0; nxt < 4; ++nxt)
		{
			nextValue[0] = i + dir * dx1[nxt];
			nextValue[1] = j + dir * dy1[nxt];

			if (nextValue[0] < 0 || nextValue[0] > n || nextValue[1] < 0 || nextValue[1] > n)
				continue;
			cnt += board[nextValue[0]][nextValue[1]];
		}

	}
	return cnt;
}

int CountX(int i, int j)
{
	int cnt = board[i][j];
	int nextValue[2] = { 0,0 };

	for (int dir = 1; dir <= m; ++dir)
	{
		for (int nxt = 0; nxt < 4; ++nxt)
		{
			nextValue[0] = i + dir * dx[nxt];
			nextValue[1] = j + dir * dy[nxt];

			if (nextValue[0] < 0 || nextValue[0] > n || nextValue[1] < 0 || nextValue[1] > n)
				continue;
			cnt += board[nextValue[0]][nextValue[1]];
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
		for (int j = 0; j < n; ++j)
			cin >> board[i][j];
			
	int maxValue = -1;
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (maxValue < CountCross(i, j))
				maxValue = CountCross(i, j);
			if (maxValue < CountX(i, j))
				maxValue = CountX(i, j);
		}
	}
	cout << maxValue;
}