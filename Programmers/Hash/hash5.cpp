#include <string>
#include <vector>
#include <tuple>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(const tuple<string, int, int> &a, const tuple<string, int, int> &b)
{
    return get<1>(a) > get<1>(b);
}

bool cmp2(const pair<string, int> &a, const pair<string, int> &b)
{
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) 
{
    vector<int> answer;
    vector<tuple<string, int, int>> vec;
    unordered_map<string, int> us;

    for (int i = 0; i < genres.size(); ++i)
    {
        vec.push_back({ genres[i], plays[i], i });
        us[genres[i]] += plays[i];
    }   
    vector<pair<string, int>> scores(us.begin(), us.end());
    sort(scores.begin(), scores.end(), cmp2);
    sort(vec.begin(), vec.end(), cmp);

    for (int i = 0; i < scores.size(); ++i)
    {      
        int cnt = 0;
        for (int j = 0; j < vec.size(); ++j)
        {
            if (get<0>(vec[j]) == scores[i].first)
            {
                answer.push_back(get<2>(vec[j]));
                cnt++;
            }
            if (cnt == 2)
                break;
        }       
    }

    return answer;
}

int main()
{
    vector<string> g = { "classic", "pop", "classic", "classic", "pop"};
    vector<int> p = { 500, 600, 150, 800, 2500};

    vector<string> g2 = { "classic", "classic", "classic", "classic", "pop" };
    vector<int> p2 = { 50, 60, 100, 30, 8000 };

    vector<string> g3 = { "classic",  "pop", "classic", "classic"};
    vector<int> p3 = { 800,600,150, 800 }; //0 3 1

    vector<string> g4 = { "pop", "pop", "pop", "rap", "rap" };
    vector<int> p4 = { 45, 50, 40, 60, 70 }; //1 0 4 3

    vector<int> ans = solution(g4, p4);
    for (auto a : ans)
        cout << a << " ";
}