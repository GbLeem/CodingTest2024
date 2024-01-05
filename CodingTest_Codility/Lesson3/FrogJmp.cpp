//time complexity : O(1)
#include <iostream>

using namespace std;

int solution(int X, int Y, int D)
{
    int ans = 0;

    Y -= X; //75
    ans = Y / D;

    if (Y % D == 0)
        return ans;
    else
        return ans + 1;

}

int main()
{
    cout << solution(10, 85, 30);
}