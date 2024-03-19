#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int num)
{
    long long temp = num;
    int answer = 0;
    bool not_ans = false;

    while (temp != 1)
    {
        if (answer > 500)
        {
            not_ans = true;
            break;
        }

        if (temp % 2 == 0)
            temp /= 2;
        else
            temp = temp * 3 + 1;

        answer++;
    }

    if (not_ans)
        answer = -1;

    return answer;
}

int main()
{
    cout << solution(626331);
}