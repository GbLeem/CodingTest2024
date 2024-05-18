#include <iostream>

#include <cmath>
using namespace std;

int solution(int N)
{
    int divNum = 2;
    int idx = 1;
    while (1)
    {
        divNum = pow(2, idx);
        if (N % divNum != 0)
        {
            idx--;
            break;
        }
        idx++;
    }
    return idx;
}

int main()
{
    cout << solution(1);
}