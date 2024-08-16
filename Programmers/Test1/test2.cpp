#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int cnt[1000002];
vector<vector<int>> adj(1000002);
vector<int> realadj[1000002];
int vis[1000002];
//한 점을 알때 해당 그래프의 타입 구하기
int countType(vector<vector<int>> edges, int n)
{
    int cnt = 0;
    for (int i = 0; i < edges.size(); ++i)
    {
        if (edges[i][0] == n)
            cnt++;
        if (edges[i][1] == n)
            cnt++;
    }
    return cnt;
}
int c1 = 0;
void dfs(int cur)
{
    c1++;
    vis[cur] = 1;
    for (auto nxt : realadj[cur])
    {
        if (vis[nxt])
            continue;
        dfs(nxt);
    }
}

vector<int> solution(vector<vector<int>> edges)
{
    for (int i = 0; i < edges.size(); ++i)
    {
        realadj[edges[i][0]].push_back(edges[i][1]);
    }

    vector<int> answer;
    int maxVertex = 0;
    for (int i = 0; i < edges.size(); ++i)
    {
        //가장 큰 vertex 찾기
        if (maxVertex < edges[i][0])
            maxVertex = edges[i][0];
        if (maxVertex < edges[i][1])
            maxVertex = edges[i][1];

        //가장 많이 연결된 vertex 찾기
        cnt[edges[i][0]]++;
        //vertex와 연결된 인접 vertex 찾기
        adj[edges[i][0]].push_back(edges[i][1]);
    }

    int maxEdges = 0;
    int maxEdgesVertex = 0;

    for (int i = 1; i <= maxVertex; ++i)
    {
        if (maxEdges < cnt[i])
        {
            maxEdges = cnt[i];
            maxEdgesVertex = i;
        }
    }

    //가장 maxEdgesVertex와 연결된 vertex 찾기
    int adjVertexSize = adj[maxEdgesVertex].size();

    //for(int i = 0;i < adjVertex; ++i)
    //{
    //    cout<<adj[maxEdgesVertex][i]<<" ";
    //}

    int dounut = 0;
    int mak = 0;
    int eight = 0;
    for (int i = 0; i < adjVertexSize; ++i)
    {
        int adjVertex = adj[maxEdgesVertex][i];

        int count = countType(edges, adjVertex);
        //cout<<adjVertex<<" :"<<count<<"\n";

        if (count <= 2)
            mak++;
        else if (count > 2 && count <= 3)
            dounut++;
        else
            eight++;
    }

    answer.push_back(maxEdgesVertex);
    answer.push_back(dounut);
    answer.push_back(mak);
    answer.push_back(eight);


    return answer;
}