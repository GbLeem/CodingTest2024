#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int>& A)
{
    int arrLength = 0;
    int idx = 0;

    while (1)
    {
        if (A[idx] == -1)
            return arrLength + 1;
        else
        {
            idx = A[idx];
            arrLength++;
        }
    }
}