// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <cmath>
#include <string>
#include <iostream>
using namespace std;

int solution(string& E, string& L)
{
    int pay = 2;
    int entrance = 0;
    int leave = 0;

    for (int i = 0; i < 5; ++i)
    {
        if (i < 2)
        {
            entrance += (E[i] - '0') * pow(10, 3 - i);
            leave += (L[i] - '0') * pow(10, 3 - i);
        }
        else if (i > 2)
        {
            entrance += (E[i] - '0') * pow(10, 4 - i);
            leave += (L[i] - '0') * pow(10, 4 - i);
        }
    }

    double gap = leave - entrance; //148
    bool firstTime = true;

    if (firstTime)
    {
        pay += 3;
        if (gap >= 100)
        {
            gap -= 100;
        }
        else
            return pay;
        firstTime = false;
    }

    if (!firstTime)
    {
        int temp = ceil(gap / 100);
        pay += (temp * 4);
        return pay;
    }    

    return pay;
}
int main()
{
    string E = "10:00";
    string L = "13:21";

    string E1 = "17:00";
    string L1 = "18:48";

    string E2 = "18:21";
    string L2 = "18:29";

    cout << solution(E, L) << "\n"; //17
    cout << solution(E1, L1) << "\n"; //9
    cout << solution(E2, L2) << "\n"; //5
}