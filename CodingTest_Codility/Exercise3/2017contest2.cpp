#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int K, vector<int>& C, vector<int>& D)
{
    int cnt = 0;
    //clean에서 먼저 찾고
    sort(C.begin(), C.end());
    sort(D.begin(), D.end());

    for (int i = 0; i < C.size(); ++i)
    {
        if (i != C.size() - 1 && C[i] == C[i + 1])
        {
            i += 1;
            cnt++;
        }
        else
        {
            //clean에서 남은 거랑 dirty랑 짝 맞을때
            if (binary_search(D.begin(), D.end(), C[i]))
            {
                int idx = lower_bound(D.begin(), D.end(), C[i]) - D.begin();
                if (K > 0)
                {
                    K -= 1;
                    cnt++;
                    D[idx] = 0;
                }
            }
        }
    }
    //K 남아있으면 
    //dirty에서 짝 맞을때
    if (K >= 2)
    {
        sort(D.begin(), D.end());
        for (int i = 0; i < D.size() - 1; ++i)
        {
            if (K < 2)
                break;
            if (D[i] == D[i + 1] && D[i] != 0)
            {
                cnt++;
                K -= 1;
                i += 1;
            }
        }
    }
    return cnt;
}