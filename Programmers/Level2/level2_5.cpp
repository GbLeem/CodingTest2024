//멀리 뛰기
//피보나치 dp
#include <string>
#include <vector>
using namespace std;

int d[2005];

long long solution(int n)
{
    long long answer = 0;

    d[1] = 1;
    d[2] = 2;

    for (int i = 3; i <= n; ++i)
        d[i] = (d[i - 1] + d[i - 2]) % 1234567;

    return d[n];
}