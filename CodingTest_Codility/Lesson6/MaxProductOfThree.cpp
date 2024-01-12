#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

// -3 1 2 -2 5 6
int solution(vector<int>& A)
{
    sort(A.begin(), A.end()); //-3 -2 1 2 5 6
    vector<int> minus;
    vector<int> plus;
    vector<int> zero;
    int ans = 0;

    for (const auto a : A)
    {
        if (a < 0)
            minus.push_back(a);
        else if (a > 0)
            plus.push_back(a);
        else
            zero.push_back(a);
    }
    if (plus.size() == 0) //모두 음수 -> 답이 음수
    {
        sort(minus.begin(), minus.end());
        if (minus.size() >= 3)
            ans = (minus[minus.size() - 1] * minus[minus.size() - 2] * minus[minus.size() - 3]);
        else
            ans = A[0] * A[1] * A[2];

        if (!zero.empty())
            ans = 0;
    }
    else // 답이 양수 or size == 3
    {
        sort(minus.begin(), minus.end());
        sort(plus.begin(), plus.end());

        int temp1 = 0, temp2 = 0;
        //음음 양
        if(minus.size() >= 2)
            temp1 = minus[0] * minus[1] * plus[plus.size() - 1];
        //양양양       
        if (plus.size() >= 3)
            temp2 = plus[plus.size() - 1] * plus[plus.size() - 2] * plus[plus.size() - 3];
        
        else if(A.size()==3)//N==3
        {
            ans = A[0] * A[1] * A[2];
            return ans;
        }

        ans = temp1 > temp2 ? temp1 : temp2;        
    }
    return ans;
}

int solution2(vector<int>& A)
{
    int size = A.size();
    sort(A.begin(), A.end());

    int max1 = A[0] * A[1] * A[size - 1];
    int max2 = A[size - 1] * A[size - 2] * A[size - 3];

    return max1 > max2 ? max1 : max2;
}

int main()
{
    vector<int> a = { -5, 5, -5, 4 }; //-5 -5 4 5
    vector<int> b = { 5,5,5,1,2,2 }; //1 2 2 5 5 5
    vector<int> c = { -2, -3, 0 };
    vector<int> d = { -10, -5, -3, -2, 1, 2, 3 };
    vector<int> e = { -10, -5, -1, 5, 7, 10, 20 };

    cout << solution(a) << endl;
    cout << solution(b) << endl;
    cout << solution(c) << endl;
    cout << solution(d) << endl;
    cout << solution(e) << endl;
}