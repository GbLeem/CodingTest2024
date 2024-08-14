//마인크래프트

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, b; //세로, 가로, 인벤 블록 수
int board[505][505];
vector<int> h(505); //높이
pair<int, int> answer = { 0,0 };

//높이가 h일때 해당 하는 자리를 h로 만들때 필요한 시간
int make(int h, int x, int y)
{
	int res = 0;
	
	//같으면 아무것도 안해도 된다.
	if (board[x][y] == h)
		res = 0;

	//쌓아야 할때
	else if (board[x][y] < h) 
	{
		//쌓을 수 있다면, 
		if (h - board[x][y] <= b)
		{
			res = (h - board[x][y]);
			b -= (h - board[x][y]);
		}
		//블럭이 모자란 경우
		else
		{
			res = -1;
		}
	}
	//제거해야 할 때
	else
	{
		res = (board[x][y] - h) * 2;
		b += (board[x][y] - h);
	}


	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> b;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> board[i][j];
			h.push_back(board[i][j]);
		}
	}
	h.erase(unique(h.begin(), h.end()), h.end());

	int land = 0;
	//높이 설정
	for (int i = 0; i < h.size(); ++i)
	{
		land = h[i];
		int temp = 0;

		for (int y = 0; y < n; ++y)
		{
			for (int x = 0; x < m; ++x)
			{
				//쌓을수 없는 경우
				if (make(land, x, y) == -1)
				{
					break;
				}
				else
				{
					temp += make(land, x, y);
				}
			}

			answer = { min(temp, answer.first), land }; //시간, 높이
		}
	}
	
	cout << answer.first << " " << answer.second;
}
