//#include <iostream>
//#include <string>
//#include <vector>
//#include <queue>
//#include <algorithm>
//using namespace std;
//
//priority_queue<int> pq;
//vector<pair<int,int>> val;
//
//int solution(vector<vector<int>> jobs)
//{
//    int answer = 0;
//    for (int i = 0; i < jobs.size(); ++i)
//    {
//        val.push_back({ jobs[i][1], jobs[i][0] });
//    }
//    sort(val.begin(), val.end());
//    
//    for (int i = 0; i < val.size(); ++i)
//    {
//        int lastIdx = 0;
//        if (pq.empty())
//        {
//            pq.push(val[0].first - val[0].second);
//            lastIdx = val[0].first + val[0].second;
//        }
//        else
//        {            
//            if (lastIdx > pq.top())
//                pq.push(val[i].first);
//            else
//            {
//                int temp = pq.top() + val[i-1].second;            
//                pq.push(temp + val[i].first - val[i].second);
//            }
//        }
//    }
//
//    int size = pq.size();
//    while (!pq.empty())
//    {
//        answer += pq.top();
//        pq.pop();
//    }
//    cout << "ans " << answer << "\n";
//    answer /= size;
//    return answer;
//}
//
//int main()
//{
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//
//    vector<vector<int>> vec1 = { {0, 3},{1, 9}, {2, 6  } };
//    vector<vector<int>> vec2 = { {0, 9} ,{0, 4},{0, 5},{0, 7},{0, 3} };
//    vector<vector<int>> vec3 = { {0, 3 }, { 1, 9 }, { 500, 6 } };
//    
//    //cout<< solution(vec1)<<"\n";    
//    //cout << solution(vec2) << "\n"; //13
//    cout << solution(vec3) << "\n"; //6
//}