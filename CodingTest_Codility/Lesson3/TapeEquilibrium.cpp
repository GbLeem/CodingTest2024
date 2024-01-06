#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

//int solution(vector<int>& A)
//{
//    int P = A.size() - 1; //4
//    int totalSize = 0; //original
//    int ans = 100001;
//
//    for (int i = 0; i < A.size(); ++i)
//    {
//        totalSize += A[i];
//    }
//
//    while (P > 0)
//    {
//        int first = 0;
//        int second = 0;
//
//        
//        for (int i = 0; i < P; ++i) //0 1 2  3
//        {
//            first += A[i];
//        }
//        second = totalSize - first;
//
//        if (ans > abs(first - second))
//            ans = abs(first - second);
//        P--;
//    }
//    return ans;
//}

int solution2(vector<int>& A)
{
   /* int P = A.size() - 1;

    int* first = new int[P];
    int* second = new int[P];

    first[0] = A[0];
    for (int i = 2; i < P; ++P)
    {
        first[i] = first[i - 1] + A[i - 1];
    }

    return ans;*/
}

int main()
{
    vector<int> a = { 100, 99, 1, 23, 19 };
    vector<int> b = { 3, 1, 2, 4, 3};
    cout << solution2(b) << endl;
}