#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int solution(vector<int>& A, vector<int>& B)
{
    int answer = 0;
    vector<pair<int, int>> vec;
    for (int i = 0; i < A.size(); ++i)
    {
        vec.push_back({ A[i], B[i] });
    }
    sort(vec.begin(), vec.end(), cmp); //끝나는 시간 오름차순

    int temp = -1; //마지막 끝나는 시간
    for (int i = 0; i < vec.size(); ++i)
    {            
        if (temp >= vec[i].first)
            continue;
        answer++;
        temp = vec[i].second;
    }

    return answer;
}

int main()
{
    vector<int> A = { 0,2,4 };
    vector<int> B = { 1,3,7 };
    
    vector<int> A1 = { 0 };
    vector<int> B1 = { 0 };

    vector<int> A2 = { 0 };
    vector<int> B2 = { 1 };

    vector<int> A3 = { 1,3,7,9,9 };
    vector<int> B3 = { 5,6,8,9,10 };

    cout << solution(A, B) << "\n";   //3
    cout << solution(A1, B1) << "\n"; //1
    cout << solution(A2, B2) << "\n"; //1
    cout << solution(A3, B3) << "\n"; //3
}