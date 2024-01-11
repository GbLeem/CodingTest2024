#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int>& A)
{
    if (A.empty())
        return 0;
    sort(A.begin(), A.end()); // 1 1 1 2 2 3 3 100
    vector<int> temp(A[A.size()-1]); // 0 0 0 0 0 0   

    for (int i = 0; i < A.size(); ++i)
    {
        temp[A[i] - 1]++; //3 2 1 0 0 0
    }
    for (int i = 0; i < temp.size(); ++i)
    {
        if (temp[i] == 1)
            return i + 1;
    }
    return 0;
}

int main()
{
    vector<int> a = { 2, 1, 1, 2, 3, 1,3, 100 };
    vector<int> b = {  };
    vector<int> c = { 10000000 };
    cout << solution(a) << endl;
    cout << solution(b) << endl;
    cout << solution(c) << endl;
}