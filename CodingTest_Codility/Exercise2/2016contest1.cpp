#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

//int solution(vector<int>& A, int X)
//{
//    vector<pair<int, int>> vec;
//    vector<int> tempA;
//
//    for (int i = 0; i < A.size(); ++i)
//    {
//        if (count(A.begin(), A.end(), A[i]) < 2)
//            continue;
//        else
//        {
//            vec.push_back({ A[i], count(A.begin(), A.end(), A[i]) });
//            tempA.push_back(A[i]);
//        }
//    }
//    sort(vec.begin(), vec.end(), greater<int>()); // 5 5 2 2 1 1 1 1
//    sort(tempA.begin(), tempA.end()); //1 1 1 1 2 2 5 5
//    for (int i = 0; i < vec.size(); ++i)
//    {
//        int tempSize = X / vec[i].first; // 5/5
//       
//        //auto idx = lower_bound(vec.begin(), vec.end(), tempSize);
//        
//    }
//}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> vec = { 1,2,5,1,1,2,3,5,1 };
    sort(vec.begin(), vec.end()); //1 1 1 1 2 2 3 5 5 

    cout << *lower_bound(vec.begin(), vec.end(), 4);//k보다 크거나 같은 최초의 숫자
    cout << lower_bound(vec.begin(), vec.end(), 4) - vec.begin(); // 4보다 크거나 같은 것이 나온 인덱스
}