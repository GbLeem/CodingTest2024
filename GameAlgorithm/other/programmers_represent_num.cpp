#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n)
{
    int answer = 0;
    int start = 0;
    int temp = 1;

    while (temp <= n)
    {
        int sum = 0;

        start = temp;
        while (sum <= n)
        {
            if (sum > n)
            {
                break;
            }
            if (sum == n)
            {
                answer++;
                break;
            }
            sum += start;
            start++;
        }

        temp++;
    }
    return answer;
}

int main()
{
    cout << solution(15) << endl;
    cout << solution(1);
}