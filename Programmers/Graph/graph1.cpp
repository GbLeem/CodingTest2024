//가장 먼 노드

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> adjacent[200005];
int depth[20005];

int solution(int n, vector<vector<int>> edge)
{
    int answer = 0;
    fill(depth, depth + n + 2, -1);

    for (int i = 0; i < edge.size(); ++i)
    {
        adjacent[edge[i][0]].push_back(edge[i][1]);
        adjacent[edge[i][1]].push_back(edge[i][0]);
    }

    queue<int> q;
    q.push(1);
    depth[1] = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int nxt : adjacent[cur]) //nxt -> 2랑 3
        {
            if (depth[nxt] >= 0)
                continue;
            q.push(nxt);
            depth[nxt] = depth[cur] + 1;
        }
    }

    int maxValue = *max_element(depth + 1, depth + n + 2);
    for (int i = 1; i <= n; ++i)
    {
        if (depth[i] == maxValue)
            answer++;
    }

    return answer;
}