//단어 변환
//DFS BFS
#include <iostream>

#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

map<string, int> dist;

bool check(string start, string end)
{
    int cnt = 0;
    for (int i = 0; i < start.size(); ++i)
    {
        if (start[i] != end[i])
            cnt++;
        if (cnt > 1)
            return false;
    }
    return true;
}

int solution(string begin, string target, vector<string> words)
{
    int answer = 0;
    queue<string> q;

    q.push(begin);    
    dist[begin] = 1;

    while (!q.empty())
    {
        string cur = q.front();
        q.pop();

        for (int i = 0; i < words.size(); ++i)
        {            
            if (check(words[i], cur)) //갈 수 있는 경우
            {
                if (dist[words[i]] > 0) //이미 온 경우
                    continue;
                q.push(words[i]);
                dist[words[i]] = dist[cur] + 1;
            }
        }
    }

    if (dist[target])
        return dist[target] - 1;
    return 0;
}

int main()
{
    vector<string> vec = { "hot", "dot", "dog", "lot", "log", "cog" };
    vector<string> vec2 = { "hot", "dot", "dog", "lot", "log" };
    //cout << solution("hit", "cog", vec) << "\n";
    cout << solution("hit", "cog", vec2) << "\n";
}