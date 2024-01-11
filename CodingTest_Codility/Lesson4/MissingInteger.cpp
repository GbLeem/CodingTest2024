#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int>& A)
{
    int size = A.size(); //6
    sort(A.begin(), A.end()); //1 2 3 4 5 6

    int cnt = 0;
    for (const auto& a : A)
    {
        if (a == 1)
            break;
        else
            cnt++;
    }

    if (A[size - 1] <= 0) //가장 큰 수가 양수가 아닐 때
        return 1;

    for (int i = 0; i < size - 1; ++i)
    {
        if (A[i] < 0 && A[i + 1] < 0)
            continue;
        else if (A[i] < 0 && A[i + 1] > 0) // -2 2
        {

        }
        else if (A[i] == 0 && A[i + 1] > 0) //0 2
        {
            if()
        }

    }
}

int main()
{
    vector<int> a = { -1, -2, 2 }; //-2 -1 2
    vector<int> b = { -2, -1, 0, 2};
    vector<int> c = {-2, -1, 0, 1 };
    vector<int> d = {-2, -1, 1};     //-2 -1 1
    vector<int> e = { -2, 2 }; //5

    cout << solution(a) << endl; //1
    cout << solution(b) << endl; //1
    cout << solution(c) << endl; //2
    cout << solution(d) << endl; //2
    cout << solution(e) << endl; //1
}