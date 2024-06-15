//2xn 타일링
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int d[100000];
int solution(int n)
{
    int answer = 0;
    d[1] = 1;
    d[2] = 2;
    //d[3] = 3;
    //d[4] = 5;
    for (int i = 3; i <= n; ++i)
    {
        d[i] = (d[i - 1] + d[i - 2]) % 1000000007;
    }
    return d[n];
}

int main()
{
    cout << solution(4);
}