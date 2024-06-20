//#include <iostream>
//#include <string>
//#include <vector>
//#include <queue>
//#include <algorithm>
//using namespace std;
//int depth[20];
//int vis[20];
//
//bool cmp(vector<int> d1, vector<int> d2)
//{
//    if (d1[0] == d2[0])
//        return d1[1] > d2[1];
//    return d1[0] > d2[0];
//}
//
//int solution(int k, vector<vector<int>> dungeons)
//{
//    int answer = -1;
//    sort(dungeons.begin(), dungeons.end(), cmp);
//
//    int tempK = k;
//    fill(vis, vis + dungeons.size() + 2, 0);
//
//    if (tempK >= dungeons[0][1]) //필요 피로도 통과하면,
//    {
//        queue<int> q;
//        q.push(0); //인덱스 넣기
//        depth[0]++;
//        //vis[0] = 1; //방문 체크
//        tempK -= dungeons[0][1]; //피로도 감소
//
//        while (!q.empty())
//        {
//            int cur = q.front(); ///cur은 방문한 인덱스  
//            q.pop();
//
//            int temptempK = tempK;
//            for (int dir = 0; dir < dungeons.size(); ++dir) //모든 경우 수
//            {
//                if (temptempK < dungeons[dir][0]) //필요 피로도 불가능
//                    continue;
//                //if (vis[dir]) //이미 방문 했으면, 스킵
//                    //continue;
//
//                q.push(dir);
//                //vis[dir] = 1;
//                temptempK -= dungeons[dir][1];
//                depth[dir] = depth[cur] + 1;
//            }
//        }
//    }
//    
//    for (int i = 0; i < dungeons.size(); ++i)
//    {
//        cout << depth[i] << " ";
//    }
//
//    return answer + 1;
//}
//
//int main()
//{
//    vector<vector<int>> dungeons1 = { {80,20}, {50,40}, {30,10} };
//    solution(80, dungeons1);
//}