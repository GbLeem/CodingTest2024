#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dist[105][105];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int solution(vector<vector<int> > maps)
{
    int n = maps.size(); //세로
    int m = maps[0].size(); //가로

    for (int i = 0; i < n; ++i)
        fill(dist[i], dist[i] + m, -1);

    queue<pair<int, int>> Q;

    Q.push({ 0,0 });
    dist[0][0] = 1;

    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (maps[nx][ny] == 0 || dist[nx][ny] >= 0)
                continue;
            Q.push({ nx,ny });
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
        }
    }
    return dist[n - 1][m - 1];
}