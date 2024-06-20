#include <iostream>

#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

bool isused[20000005];
//2 4 5 8 10
bool isprime(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int solution(string numbers)
{
    int answer = 0;
    vector<int> vec;

    for (int i = 0; i < numbers.size(); ++i)
        vec.push_back(numbers[i] - '0');
    sort(vec.begin(), vec.end()); // 1 7

    for (int m = 0; m < vec.size(); ++m)
    {
        do
        {
            int num = 0;
            for (int i = 0; i <= m; ++i)
            {
                num += vec[i] * pow(10, m - i);
            }

            if (!isused[num] && isprime(num))
            {
                //cout<<num<<'\n';
                isused[num] = true;
                answer++;
            }

        } while (next_permutation(vec.begin(), vec.end()));
    }
    return answer;
}