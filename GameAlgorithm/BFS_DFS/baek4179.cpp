#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int R, C; //세로(행) 가로(열)
string board[1002];
int dist[1002][1002];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


int main()
{
	cin >> R >> C;
	for (int i = 0; i < R; ++i)
	{
		cin >> board[i];
	}

}