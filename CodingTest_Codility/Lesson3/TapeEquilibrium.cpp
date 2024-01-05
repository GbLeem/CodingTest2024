#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int>& A)
{
    int P = A.size() - 1; //4
    int totalSize = 0; //original P -> 5
    int ans = 100001;

    for (int i = 0; i < A.size(); ++i)
    {
        totalSize += A[i];
    }

    while (P > 0)
    {
        int first = 0;
        int second = 0;

        for (int i = 0; i < P; ++i) //0 1 2  3
        {
            first += A[i];
        }
        second = totalSize - first;

        if (ans > abs(first - second))
            ans = abs(first - second);
        P--;
    }
    return ans;
}

int main()
{
    vector<int> a = { 100, 99, 1, 23, 19 };
    cout << solution(a) << endl;
}