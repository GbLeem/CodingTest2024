//여행 경로

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

unordered_multimap<string, string> um;
unordered_map<string, bool> vis;

vector<string> solution(vector<vector<string>> tickets)
{
    vector<string> answer;

    for (int i = 0; i < tickets.size(); ++i)
    {
        um.insert({ tickets[i][0], tickets[i][1] });
    }

    queue<string> q;
    q.push("ICN");
    vis["ICN"] = 1;
    answer.push_back("ICN");

    while (!q.empty())
    {
        auto cur = q.front(); //key값
        q.pop();

        auto u = um.equal_range(cur);

        vector<string> temp;
        for (auto it = u.first; it != u.second; ++it)
        {
            cout << it->second << " ";
            if(vis[it->second] == 0)
                temp.push_back(it->second);
        }
        if (!temp.empty())
        {
            sort(temp.begin(), temp.end());
            q.push(temp[0]);
            answer.push_back(temp[0]);        
            vis[temp[0]] = 1;
        }
        
        

    }

    return answer;
}

int main()
{
    vector<vector<string>> tickets = { {"ICN", "JFK"} ,{"HND", "IAD"},{"JFK", "HND"} };
    vector<vector<string>> tickets2 = { {"ICN", "SFO" }, { "ICN", "ATL" }, { "SFO", "ATL" }, { "ATL", "ICN" }, { "ATL","SFO" } };
    auto vec = solution(tickets2);

    for (auto v : vec)
        cout << v << " ";
}