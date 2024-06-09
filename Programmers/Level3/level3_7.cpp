//최고의 집합

#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> solution(int n, int s)
{
    vector<int> answer;

    //4 15
    int div = s / n; //3
    int mod = s - div * n; //15 - 3*4 = 3

    if (div == 0)
        answer.push_back(-1);
    else
    {
        for (int i = 0; i < n; ++i)
        {
            answer.push_back(div); //3 3 3 3
        }
        for (int i = 0; i < n; ++i)
        {
            if (mod == 0)
                break;
            answer[i]++;
            mod--;
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}