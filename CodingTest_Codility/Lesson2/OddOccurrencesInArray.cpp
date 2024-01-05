#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int>& A)
{
    sort(A.begin(), A.end());

    for (int i = 0; i < A.size() - 1; i += 2)
    {
        if (A[i] != A[i + 1])
            return A[i];
    }
    return A[A.size() - 1];
}

int main()
{
    vector<int> a = { 1,1,1,2,2 };
    vector<int> b = { 1,2,1,2,2 };
    cout << solution(a) << endl;
    cout << solution(b) << endl;
}