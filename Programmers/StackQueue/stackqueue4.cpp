#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> priorities, int location)
{
    queue<pair<int, int>> q;
    priority_queue<int> pq;

    int answer = 0;

    for (int i = 0; i < priorities.size(); ++i)
    {
        q.push({ priorities[i], i });
        pq.push(priorities[i]);
    }

    while (!pq.empty())
    {
        if (pq.top() == q.front().first)
        {
            if (q.front().second == location)
            {
                answer++;
                return answer;
            }
            answer++;
            pq.pop();
            q.pop();
        }
        else
        {
            pair<int, int> temp(q.front().first, q.front().second);
            q.pop();
            q.push(temp);
        }
    }
    return answer;
}