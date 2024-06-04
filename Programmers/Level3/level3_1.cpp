//이중 우선순위 큐
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<int> pq;
priority_queue<int, vector<int>, greater<int>> pq2; //최소 힙

vector<int> solution(vector<string> operations)
{
    vector<int> answer;
    vector<int> ans;
    int sizeO = 0;
    for (int i = 0; i < operations.size(); ++i)
    {
        if (operations[i][0] == 'I')
        {
            string temp;
            for (int j = 2; j < operations[i].size(); ++j)
            {
                temp += operations[i][j];
            }
            pq.push(stoi(temp));
            pq2.push(stoi(temp));
            answer.push_back(stoi(temp));
            sizeO++;
        }
        else if (operations[i] == "D 1") //최댓값 삭제
        {
            if (sizeO > 0)
            {
                answer.erase(remove(answer.begin(), answer.end(), pq.top()), answer.end());
                pq.pop();
                sizeO--;
            }
        }
        else if (operations[i] == "D -1")//"D -1" 최솟값 삭제
        {
            if (sizeO > 0)
            {
                answer.erase(remove(answer.begin(), answer.end(), pq2.top()), answer.end());
                pq2.pop();
                sizeO--;
            }
        }
    }
    if (sizeO == 0)
    {
        ans.push_back(0);
        ans.push_back(0);
    }
    else
    {
        sort(answer.begin(), answer.end());
        ans.push_back(answer.back());
        ans.push_back(answer.front());
    }

    return ans;
}

int main()
{
    vector<string> vec = { "I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1" };
    vector<string> vec2 = { "I 1", "I 2", "D 1", "D -1", "I 3", "I 4", "D 1" };
    solution(vec2);
}