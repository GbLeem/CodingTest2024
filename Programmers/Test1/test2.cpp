//도넛과 막대 그래프
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int cnt[1000002]; //가장 많이 연결된 vertex 찾기
vector<vector<int>> adj(1000002); //가장 많이연결된 vertex와 연결된 vertex의 모음
vector<int> realadj[1000002];//dfs용 배열
int vis[1000002];//dfs용 배열

int c1 = 0;
int c2 = 0;

void dfs(int cur)
{
    c1++; //정점의 갯수
    vis[cur] = 1;
    for (auto nxt : realadj[cur])
    {
        c2++;
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

    int dounut = 0;
    int mak = 0;
    int eight = 0;
    for (int i = 0; i < adjVertexSize; ++i)
    {
        int adjVertex = adj[maxEdgesVertex][i];

        //초기화
        fill(vis, vis + 1000002, 0);
        c1 = 0; //정점
        c2 = 0; //엣지
        dfs(adjVertex);     
        
        if (c2 == c1 + 1)
            eight++;
        else if (c2 == c1 - 1)
            mak++;
        else if(c2 == c1)
            dounut++;
    }

    answer.push_back(maxEdgesVertex);
    answer.push_back(dounut);
    answer.push_back(mak);
    answer.push_back(eight);


    return answer;
}

int main()
{
    vector<vector<int>> v1 = { {2,3},{4,3},{1,1},{2,1} };
    vector<vector<int>> v2 = { {4,11},{1,12},{8,3},{12,7},{4,2},{7,11},{4,8},{9,6},{10,11},
        {6,10},{3,5},{11,1},{5,3},{11,9},{3,8} };
    solution(v2);
}