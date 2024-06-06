//단속 카메라
//greedy
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> v1, vector<int> v2)
{
    if (v1[1] == v2[1])
        return v1[0] < v2[0];
    return v1[1] < v2[1];
}

int solution(vector<vector<int>> routes)
{
    sort(routes.begin(), routes.end(), cmp);

    int answer = 1;
    int s = routes[1][0];
    int e = routes[0][1];
    int idx = 1;

    while (1)
    {
        if (e > s)
        {
            if (idx == routes.size() - 1)
                break;
            idx++;
            s = routes[idx][0];
        }
        else if (e == s)
        {
            if (idx == routes.size() - 1)
                break;
            e = routes[idx][1];
            idx++;
            s = routes[idx][0];
        }
        else
        {
            answer++;
            if (idx == routes.size() - 1)
                break;
            e = routes[idx][1];
            idx++;
            s = routes[idx][0];
        }
    }
    return answer;
}
int main()
{
    vector<vector<int>>v = { {-20,-15}, {-14,-5}, {-18, -13}, {-5,-3} };
    //vector<vector<int>>v = { {1,2}, {3,4}, {5,6}, {8,9} };
    //vector<vector<int>> v = { {1,20}, {2,5},{3,6 } };
    //vector<vector<int>> v = { {1,2}, {2,4}, {4,5 } };
    cout << solution(v);
}