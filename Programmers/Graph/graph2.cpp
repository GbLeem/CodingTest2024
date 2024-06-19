//플로이드?
//순위

//#include <iostream>
//#include <string>
//#include <vector>
//#include <queue>
//#include <algorithm>
//using namespace std;
//
//vector<int> adjacent[5000];
//int ans[102][102];
//
//int solution(int n, vector<vector<int>> results)
//{
//    int answer = n;
//    for (int i = 0; i <= n; ++i)
//        fill(ans[i], ans[i] + n + 2, -1);
//
//
//    for (int i = 0; i < results.size(); ++i)
//        adjacent[results[i][0]].push_back(results[i][1]);
//
//    for (int i = 1; i <= n; ++i)
//    {
//        queue<int> q;
//        q.push(i);
//        ans[i][i] = 0;
//
//        while (!q.empty())
//        {
//            int cur = q.front();
//            q.pop();
//
//            for (int nxt : adjacent[cur])
//            {
//                if (ans[i][nxt] != -1)
//                    continue;
//                q.push(nxt);
//                ans[i][nxt] = ans[i][cur] + 1;
//            }
//        }
//    }
//    vector<int> temp;
//
//    for (int i = 1; i <= n; ++i)
//    {
//        int maxValue = *max_element(ans[i], ans[i] + n + 2);
//        temp.push_back(maxValue);
//    }
//
//    for (int i = 1; i <= n; ++i)
//        cout << temp[i] << " ";
//
//
//    return answer;
//}