#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int depth[20][20];
int vis[20];

bool cmp(vector<int> d1, vector<int> d2)
{
    if (d1[0] == d2[0])
        return d1[1] > d2[1];
    return d1[0] > d2[0];
}

int solution(int k, vector<vector<int>> dungeons)
{
    int answer = -1;
    sort(dungeons.begin(), dungeons.end(), cmp);

    for (int i = 0; i < dungeons.size(); ++i) //시작점 설정
    {
        int tempK = k;
        /*for (int dir = 0; dir < dungeons.size(); ++dir)
            fill(depth[dir], depth[dir] + dungeons.size() + 2, 0);*/
        fill(vis, vis + dungeons.size() + 2, 0);

        if (tempK >= dungeons[i][0]) //필요 피로도 통과하면,
        {
            queue<int> q;
            q.push(i); //인덱스 넣기
            depth[i][i] = 1; //깊이 0
            vis[i] = 1; //방문 체크
            tempK -= dungeons[i][1]; //피로도 감소

            while (!q.empty())
            {
                int cur = q.front(); ///cur은 방문한 인덱스  
                q.pop();

                for (int dir = 0; dir < dungeons.size(); ++dir) //모든 경우 수
                {
                    if (tempK < dungeons[dir][0]) //필요 피로도 불가능
                        continue;
                    if (vis[dir]) //이미 방문 했으면, 스킵
                        continue;
                    q.push(dir);
                    vis[dir] = 1;
                    tempK -= dungeons[dir][1];
                    depth[i][dir] = depth[i][cur] + 1;
                }
            }
        }
    }

    for (int i=0;i<dungeons.size();++i)
    {    
        for (int j = 0; j < dungeons.size(); ++j)
            cout << depth[i][j] << " ";
        cout << "\n";
        int maxd = *max_element(depth[i], depth[i] + dungeons.size() + 1);        
        if (answer < maxd)
            answer = maxd;
    }

    return answer + 1;
}

int main()
{
    vector<vector<int>> dungeons1 = { {80,20}, {50,40}, {30,10} };
    solution(80, dungeons1);
}