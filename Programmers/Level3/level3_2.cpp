//야근 지수

#include <string>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int> pq;

long long solution(int n, vector<int> works)
{
    long long answer = 0;
    vector<int> ans;
    for (int i = 0; i < works.size(); ++i)
        pq.push(works[i]); //4 3 3

    while (1)
    {
        int temp = pq.top() - 1;
        pq.pop();
        n--;
        if (temp != 0)
        {
            pq.push(temp);
        }


        if (pq.empty())
            break;
        if (n == 0)
        {
            while (!pq.empty())
            {
                ans.push_back(pq.top());
                pq.pop();
            }
            break;
        }
    }

    for (int i = 0; i < ans.size(); ++i)
        answer += ans[i] * ans[i];

    return answer;
}