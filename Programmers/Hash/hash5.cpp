#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

unordered_map<string, int> um;

bool cmp(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
}
vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;

    unordered_map<string, int> um;
    
    for (int i = 0; i < genres.size(); ++i)
    {
        um[genres[i]] += plays[i];
    }
    vector<pair<string, int>> vec(um.begin(), um.end());

    vector<pair<string, int>> temp(vec);
    sort(temp.begin(), temp.end()); 
    sort(vec.begin(), vec.end(), cmp); // pop 3100, classic 1450

    string max1 = vec[0].first;
    string max2 = vec[1].first;

    while (1)
    {
        bool finish = false;
        if (answer.size() == 4 || finish)
            break;

        vector<pair<int,int>> Scores;
        for (int i = 0; i < temp.size(); ++i)
        {
            if (max1 == temp[i].first)
            {
                Scores.push_back({ temp[i].second, i });
            }
        }
        if (Scores.size() == 1)
        {
            answer.push_back(Scores[0].first);
            finish = true;
        }
        else
        {
            answer.push_back(Scores[0].second);
            answer.push_back(Scores[1].second);
        }
    }

    /*for (int i = 0; i < genres.size(); ++i)
    {
        vec.push_back({ genres[i], plays[i] });
    }*/


    

    /*for (auto u : vec)
        cout << u.first << " " << u.second << "\n";*/
    
    /*  classic 150
        classic 500
        classic 800
        pop 600
        pop 2500*/

   /* for (int i = 0; i < vec.size(); ++i)
    {
        
    }
    */
    return answer;
}

int main()
{
    vector<string> v1 = { "classic", "pop", "classic", "classic", "pop" };
    vector<int> v2 = { 500, 600, 150, 800, 2500 };

    vector<int> ans = solution(v1, v2);
    for (auto a : ans)
        cout << a << " ";
}