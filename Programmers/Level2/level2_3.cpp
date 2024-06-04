//N개의 최소공배수

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int  b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

int solution(vector<int> arr)
{
    int answer = 0;
    if (arr.size() == 1)
        return arr[0];
    answer = lcm(arr[0], arr[1]);

    for (int i = 2; i < arr.size(); ++i)
    {
        answer = lcm(answer, arr[i]);
    }

    return answer;
}