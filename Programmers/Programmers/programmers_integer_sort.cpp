#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long solution(long long n)
{
    long long answer = 0;
    vector<int> v;
    int mod = 10;

    while (n > 0)
    {
        v.push_back(n % mod); //2
        n /= mod; //11847
        //mod *= 10;
    }

    sort(v.begin(), v.end());
    int ten = 1;
    for (int i = 0; i < v.size(); ++i)
    {
        answer += v[i] * ten;
        ten *= 10;
    }

    return answer;
}

int main()
{
    cout<<solution(118472);
}