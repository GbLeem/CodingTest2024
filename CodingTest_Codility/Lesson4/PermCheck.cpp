#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<int>& A)
{
    sort(A.begin(), A.end());
    if (A[0] != 1)
        return 0;
    if (A[0] ==1 && A.size() == 1)
        return 1;
    for (int i = 0; i < A.size() - 1; ++i)
    {
        if (A[i] + 1 != A[i + 1])
            return 0;
    }
    return 1;
}