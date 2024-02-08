#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int board[202][202];
int vis[202][202];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int solution(int n, vector<vector<int>> computers)
{
    /*for (int i = 0; i < n; ++i)
    {
        fill(board[i], board[i] + n, 0);
        fill(vis[i], vis[i] + n, 0);
    }*/
    int answer = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (computers[i][j] == 1)
            {
                board[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (board[i][j] == 1 && vis[i][j] == 0) //연결되어있고, 안거침
            {
                queue<pair<int, int>> Q;
                Q.push({ i,j });
                vis[i][j] = 1;
                answer++;

                while (!Q.empty())
                {
                    auto cur = Q.front();
                    Q.pop();

                    for (int dir = 0; dir < 4; ++dir)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                            continue;
                        if (board[nx][ny] != 1 || vis[nx][ny] == 1) //못가는 곳이거나 방문함
                            continue;

                        Q.push({ nx, ny });
                        vis[nx][ny] = 1;
                    }
                }
            }
        }
    }
    return answer;
}

int main()
{
    vector<vector<int>> v = { {1, 1, 0},{1, 1, 0},{0, 0, 1} };
    vector<vector<int>> v2 = { {1, 1, 0, 0, 0},{1, 1, 1, 1, 0},{0,1,1,0,0},{0,1,0,1,1},{0,0,0,1,1} };
    cout << solution(5, v2);
}