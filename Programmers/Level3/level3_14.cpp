//여행 경로

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

struct pair_hash
{   
    template<class T1, class T2>
    size_t operator() (const pair<T1, T2>& pair) const
    {
        auto hash1 = hash<T1>{}(pair.first);
        auto hash2 = hash<T2>{}(pair.second);
        return hash1 ^ hash2;
    }
};

unordered_multimap<string, string> um;
unordered_map<pair<string, string>, int, pair_hash> vis;

vector<string> solution(vector<vector<string>> tickets)
{
    vector<string> answer;

    for (int i = 0; i < tickets.size(); ++i)
    {
        um.insert({ tickets[i][0], tickets[i][1] });
        vis[{tickets[i][0], tickets[i][1]}]++; //중복된 티켓을 쓰기 위한 처리
    }
    unordered_map<pair<string, string>, int, pair_hash> tempvis(vis);

    queue<string> q;
    q.push("ICN");
    answer.push_back("ICN");
    string before = "ICN";
    string other = "A";
    
    while (!q.empty())
    {        
        auto cur = q.front(); //key값
        q.pop();

        auto u = um.equal_range(cur); //key값에 해당하는 value들

        vector<string> temp;
        for (auto it = u.first; it != u.second; ++it)
        {            
            //방문하지 않은 경우(즉 티켓이 남아있는 경우)
            if (vis[{before, it->second}] > 0)
            {
                temp.push_back(it->second);
            }
        }

        //갈 곳이 있다면,
        if (!temp.empty())
        {
            int idx = 0;
            sort(temp.begin(), temp.end()); //ATL, SFO            
            
            if(temp[idx] == other)
            {
                while (1)
                {
                    idx++;                                
                    if (temp[idx] != other)
                    {
                        other = "";
                        break;;
                    }
                }
            }
            q.push(temp[idx]);
            vis[{before, temp[idx]}]--; //티켓 하나 지우기
            answer.push_back(temp[idx]);
            before = temp[idx];            
        }              

        //갈 곳이 없고, 다 방문하지 못한 경우
        else if (temp.empty() && answer.size() < tickets.size())
        {
            //새로운 ICN 찾아서 시작
            for (int i = 0; i < answer.size(); ++i)
            {              
                if (answer[i] == "ICN")
                {
                    //잘못된 경로 찾기                 
                    other = answer[i + 1];
                    break;
                }                
            }
            answer.clear();
            vis.clear();        
            vis = tempvis; 

            q.push("ICN");
            before = "ICN";
            answer.push_back("ICN");
        }
    }       

    return answer;
}

int main()
{
    vector<vector<string>> tickets = { {"ICN", "JFK"} ,{"HND", "IAD"},{"JFK", "HND"} };
    vector<vector<string>> tickets2 = { {"ICN", "SFO" }, { "ICN", "ATL" }, { "SFO", "ATL" }, { "ATL", "ICN" }, { "ATL","SFO" } };
    vector<vector<string>> tickets3 = { {"ICN", "BBB"}, {"BBB", "ICN"}, {"ICN","AAA"} };
    vector<vector<string>> tickets4 = { {"ICN", "AAA"}, {"AAA","ICN"},{"ICN","CCC"},{"CCC","ICN"},{"ICN","DDD"},{"DDD","AAA"} };
    vector<vector<string>> tickets5 = { {"ICN", "JFK"} ,{"ICN", "AAD"},{"JFK", "ICN"} };
    vector<vector<string>> tickets6 = { {"ICN", "AAA"} ,{"AAA", "ICN"},{"ICN", "CCC"},{"ICN", "DDD"},{"DDD", "ICN"} };
    vector<vector<string>> tickets7 = { {"ICN", "AAA"}, {"ICN","AAA"},{"AAA","ICN"} };

    auto vec = solution(tickets6);

    for (auto v : vec)
        cout << v << " ";
}