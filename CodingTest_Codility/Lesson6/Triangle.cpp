#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int>& A)
{
    int size = A.size();
    sort(A.begin(), A.end());
    
    if (A.size() == 0)
        return 0;

    for (int i = 0; i < size-2; ++i)
    {     
        long long int a = A[i];
        long long int b = A[i + 1];
        long long int c = A[i + 2];
        if (a + b > c && b + c > a && c + a > b)
        {
            return 1;
        }      
    }
    return 0;
}

int main()
{
    vector<int> a = { 10 ,2, 5, 1, 8 ,20 };
    vector<int> b = { 3, 4, 5 };
    vector<int> c = { };
    vector<int> d = { 2147483647, 2147483647, 2147483647 }; //1

    cout << solution(a) << endl;
    cout << solution(b) << endl;
    cout << solution(c) << endl;
    cout << solution(d) << endl;
    //cout << 2147483647 + 2147483647 << endl;
}