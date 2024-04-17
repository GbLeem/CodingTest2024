#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = 0;
    vector<int> vec(n + 2);
    fill(vec.begin(), vec.end(), 1);

    for (int i = 0; i < lost.size(); ++i)
    {
        vec[lost[i]] = 0;
    }
    for (int i = 0; i < reserve.size(); ++i)
    {
        vec[reserve[i]]++;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (vec[i] == 0)
        {
            if (vec[i - 1] == 2)
            {
                vec[i - 1] = 1;
                vec[i] = 1;
            }
            else if (vec[i + 1] == 2)
            {
                vec[i + 1] = 1;
                vec[i] = 1;
            }
        }
       
    }

    for (int i = 1; i <= n; ++i)
    {
        if (vec[i] >= 1)
            answer++;
    }
    return answer;
}

int main()
{
    int n = 5;
    vector<int> lost = { 2,4 };
    vector<int> reserve = { 1,3,5 };

    int n2 = 5;
    vector<int> lost2 = {1,2,3};
    vector<int> reserve2 = { 3,4 };

    cout << solution(n2, lost2, reserve2);
}