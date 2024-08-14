//숫자 변환하기
//1차원 BFS

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int board[1'000'005];

int solution(int x, int y, int n) 
{
    int answer = 0;
    fill(board, board + 1000005, -1);
    queue<int> q;

    board[x] = 0;
    q.push(x);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int nxt : {cur * 2, cur * 3, cur + n})
        {
            if (nxt < 0 || nxt > 1000000)
                continue;
            if (board[nxt] != -1)
                continue;
            board[nxt] = board[cur] + 1;
            q.push(nxt);
        }
        if (board[y] != -1)
        {
            return board[y];            
        }
    }
    answer = -1;

    return answer;
}