//피보나치 수
//dp

#include <string>
#include <vector>
#include <iostream>

using namespace std;
int f[100005];

int fib(int n)
{
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= n; ++i)
        f[i] = (f[i - 1] + f[i - 2]) % 1234567;
    return f[n];
}

int solution(int n)
{
    return fib(n);
}