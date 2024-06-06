//숫자 게임
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(), A.end(), greater<>()); //2 3 5 7
    sort(B.begin(), B.end()); //1 4 4 8

    for (int i = 0; i < A.size(); ++i)
    {
        if (upper_bound(B.begin(), B.end(), A[i]) != B.end())
        {
            B.erase(upper_bound(B.begin(), B.end(), A[i]));
            answer++;
        }
    }

    return answer;
}

int main()
{
    //vector<int>A = { 2, 3, 5, 7 };
    //vector<int>B = { 1, 4, 4 ,8 };
    vector<int>A = { 1, 3, 9, 9};
    vector<int>B = { 2, 2, 8, 10};
    cout << solution(A, B); //3
}