//모음 사전
#include <string>
#include <vector>
#include <iostream>
using namespace std;

char c[10];
int a[10];
int ans[10] = { 0, 1, 1 + 5, 1 + 5 + 25, 1 + 5 + 25 + 125, 1 + 5 + 25 + 125 + 625 };
int solution(string word)
{
    int answer = 0;

    for (int i = 0; i < word.size(); ++i)
    {
        c[5 - i] = word[i];
    }
    fill(a, a + 10, -1);
    for (int i = 1; i <= 5; ++i)
    {
        if (c[i] == 'A')
            a[i] = 0;
        else if (c[i] == 'E')
            a[i] = 1;
        else if (c[i] == 'I')
            a[i] = 2;
        else if (c[i] == 'O')
            a[i] = 3;
        else if (c[i] == 'U')
            a[i] = 4;
    }

    for (int i = 1; i <= 5; ++i)
    {
        if (a[i] != -1)
            answer += ((a[i] * ans[i]) + 1);
    }

    return answer;
}