#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;


//DFS
//int vis[202];
//
//void dfs(int current_computer, int n, vector< vector<int> > computers) 
//{
//    vis[current_computer] = 1;
//
//    for (int i = 0; i < n; i++) 
//    {
//        if (vis[i] == 0 && computers[current_computer][i] == 1) 
//        {
//            dfs(i, n, computers);
//        }
//    }
//}
//
//int solution(int n, vector< vector<int>> computers) 
//{
//    int answer = 0;
//
//    for (int i = 0; i < n; i++) 
//    {
//        if (vis[i] == 0) 
//        {
//            dfs(i, n, computers);
//            answer++;
//        }
//    }
//
//    return answer;
//}

vector<int> adj[202];
int vis[202];

int solution(int n, vector< vector<int>> computers)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (computers[i][j] == 1)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    int answer = 0;

    for (int i = 0; i < n; ++i)
    {
        queue<int> Q;
        if (vis[i])
            continue;
        answer++;
        Q.push(i);

        while (!Q.empty())
        {
            int cur = Q.front();
            Q.pop();

            for (auto nxt : adj[cur])
            {
                if (vis[nxt])
                    continue;
                vis[nxt] = 1;
                Q.push(nxt);
            }
        }
    }
    return answer;
}

int main()
{
    vector<vector<int>> A = { {1,1,1}, {1,1,0}, {1,0,1} };
    vector<vector<int>> B = { {1,1,0}, {1,1,0}, {0,0,1} };
    vector<vector<int>> C = { {1,1,0}, {1,1,1}, {0,1,1} };
    vector<vector<int>> D = { {1,1,0,1}, {1,1, 0,0 }, {0,0,1,1} ,{1,0,1,1} };
    //cout << solution(3, A) << "\n"; //1
    //cout << solution(3, B) << "\n"; //2
    //cout << solution(3, C) << "\n"; //1
    cout << solution(4, D) << "\n"; //1
}

 