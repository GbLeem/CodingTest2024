#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int>& A)
{
    if (A.size() == 0)
        return -1;
    map<int, int> m;
    set<int> s;

    int midSize = A.size() / 2 + 1;

    for (int i = 0; i < A.size(); ++i)
    {
        m.insert({ A[i], i });
        s.insert(A[i]);
    }

    sort(A.begin(), A.end());

    vector<pair<int,int>> count;
    auto cur = s.begin();
    

    while(1)
    {
        int idx1 = lower_bound(A.begin(), A.end(), *cur) - A.begin();
        cur++;
        if (cur == s.end())
        {
            count.push_back({ *(--cur), A.size() - idx1 });
            break;
        }
        int idx2 = lower_bound(A.begin(), A.end(), *cur) - A.begin();
        auto temp = cur;
        count.push_back({ *(--temp), idx2 - idx1});
    }

    bool ok = false;
    for (int i = 0; i < count.size(); ++i)
    {
        if (count[i].second >= midSize)
        {
            return m[count[i].first];
        }
    }
    return -1;
}

int main()
{
    vector<int> v = { 2, 1, 1, 1 };
    vector<int> v1 = { 2147483647 };
    vector<int> v2 = { 2,1,1 };
    vector<int> v3 = {  };
    vector<int> v4 = { 2,2,1,1,3 };
    cout << solution(v) << "\n";
    cout << solution(v1) << "\n";
    cout << solution(v2) << "\n";
    cout << solution(v3) << "\n";
    cout << solution(v4) << "\n";

}