// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <vector>
#include <iostream>
using namespace std;

//O(B-A)
//int solution(int A, int B, int K)
//{
//    int ans = 0;
//    for (int i = A; i <= B; ++i)
//    {
//        if (i % K == 0)
//            ans++;
//    }
//    return ans;
//}

int solution(int A, int B, int K)
{
    int temp1 = A / K;
    int temp2 = B / K;

    if (A % K == 0)
        temp1 -= 1;
    return temp2 - temp1;
}

int main()
{
    cout << solution(6, 10, 2); // 6 8 10
}