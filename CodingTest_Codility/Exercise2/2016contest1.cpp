#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;

int solution(vector<int>& A, int X)
{
    set<int> s;
    vector<pair<int, int>> vec;    

    if (A.size() < 4)
        return 0;

    for (int i = 0; i < A.size(); ++i)    
        s.insert(A[i]); //1 2 3 5
    
    auto cur = s.begin();

    for (int i = 0; i < s.size(); ++i)
    {
        if (count(A.begin(), A.end(), *cur) < 2)
        {
            cur++;
            continue;
        }
        else
        {
            vec.push_back({ *cur, count(A.begin(), A.end(),*cur) });            
        }
        cur++;
    }
    vector<int> temp;
    for (int i = 0; i < vec.size(); ++i)
        temp.push_back(vec[i].first);

    //vec : (1 4), (2 2), (5 2)
    int cnt = 0;

    sort(temp.begin(), temp.end());
    sort(vec.begin(), vec.end());

    for (int i = 0; i < temp.size(); ++i)
    {
        double length = ceil((double)X / temp[i]);
        int idx = lower_bound(temp.begin(), temp.end(), length) - temp.begin();        
        if (idx >= temp.size())
            continue;
        if (temp[i] <= vec[idx].first && vec[idx].second >= 2)
            cnt += (temp.size() - idx);
    }

    return cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> vec = { 1,1,2,2,2,2,5,5,3 };
    vector<int> vec2 = { 1,2,5,1,1,2,3,5,1 };
    vector<int> vec3 = { 1,1,1,1 };
    vector<int> vec4 = { 2,2,2,2 };
    //sort(vec.begin(), vec.end()); //1 1 1 1 2 2 3 5 5 

    //cout << *lower_bound(vec.begin(), vec.end(), 4);//k보다 크거나 같은 최초의 숫자
    //cout << lower_bound(vec.begin(), vec.end(), 4) - vec.begin(); // 4보다 크거나 같은 것이 나온 인덱스
    cout << solution(vec, 4) << "\n";
    cout << solution(vec2, 5) << "\n";
    cout << solution(vec3, 2) << "\n";
    cout << solution(vec4, 4) << "\n";
}