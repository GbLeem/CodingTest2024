#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> count(progresses.size());
    queue<int> Q;
    
    for (int i = 0; i < progresses.size(); ++i)
    {
        while (progresses[i] < 100)
        {
            progresses[i] += speeds[i];
            count[i]++;
        }
        Q.push(count[i]);
    }
    vector<int> answer;
    while (!Q.empty())
    {
        int cnt = 0;
        int temp = Q.front();
        Q.pop();

        while (temp >= Q.front())
        {
            Q.pop();
            cnt++;
            if (Q.empty())
                break;
        }
        answer.push_back(cnt + 1);       
    }

    return answer;
}

int main()
{
   /* vector<int>progresses = { 93, 30, 55 };
    vector<int>speeds = { 1, 30, 5 };*/
    vector<int> progresses = { 95, 90, 99, 99, 80, 99 };
    vector<int> speeds = { 1, 1, 1, 1, 1, 1 };
    vector<int> ans;
    ans = solution(progresses, speeds);

    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " ";
}