#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<int, int>a, pair<int, int>b)
{
    if (a.first == b.first)
        return a.first > b.first;
    return a.first > b.first;
}
vector<int> solution(vector<int> answers)
{
    vector<int> ans;
    vector<pair<int, int>> p;
    vector<int> one = { 1, 2, 3, 4, 5 };
    vector<int> two = { 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> three = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    
    //������ ����
    int oneA = 0;
    int twoA = 0;
    int threeA = 0;

    for (int i = 0; i < answers.size(); ++i)
    {
        if (answers[i] == one[i % one.size()])
            oneA++;
        if (answers[i] == two[i % two.size()])
            twoA++;
        if (answers[i] == three[i % three.size()])
            threeA++;
    }
    p.push_back({ oneA, 1 });
    p.push_back({ twoA, 2 });
    p.push_back({ threeA, 3 });
    
    sort(p.begin(), p.end(), cmp);

    if (p[0].first == p[1].first)
    {
        if (p[1].first == p[2].first)
        {
            ans.push_back(1);
            ans.push_back(2);
            ans.push_back(3);
        }
        else
        {
            ans.push_back(p[0].second);
            ans.push_back(p[1].second);
        }
    }
    else
        ans.push_back(p[0].second);

    return ans;
}

int main()
{
    vector<int> answer = { 1,2,3,4,5 };
    solution(answer);
}