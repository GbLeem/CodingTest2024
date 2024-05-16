// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <vector>
#include <iostream>
using namespace std;

int d[100005];

int solution(vector<int>& A)
{
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < A.size(); ++i)
    {
        if (ans >= 1'000'000'000)
            return -1;
        if (A[i] == 0)
            cnt++;
        if (A[i] == 1)
            ans += cnt;
    }

    return ans;
}