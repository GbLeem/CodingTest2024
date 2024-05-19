// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <iostream>

#include <queue>
#include <algorithm>

using namespace std;

//int solution(vector<int>& A)
//{    
//    int depth = 0;
//    priority_queue<int>pq;
//    priority_queue<int, vector<int>, greater<int>> pq2;
//    bool ok = false;
//
//    for (int i = 0; i < A.size(); ++i)
//    {
//        int tempDepth = 0;
//
//
//        if (ok && A[i - 1] < A[i])
//        {
//            int minVal = pq2.top();
//            int maxVal = pq.top();
//            int Wall = min(A[i], maxVal);
//            tempDepth = Wall - minVal;
//
//            if (tempDepth > depth)
//                depth = tempDepth;
//            ok = false;
//            continue;
//        }        
//
//        pq.push(A[i]);
//        pq2.push(A[i]);
//        
//        if (pq.top() > A[i])
//        {
//            ok = true;
//        }             
//    }
//    return depth;
//}

int solution(vector<int>& A)
{
    if (A.size() <= 2)
        return 0;

    int tall = 0;
    int small = 0;
    int depth = 0;
    int tempDepth = 0;
    for (int i = 1; i < A.size(); ++i)
    {
        if (A[i] > A[tall])
        {
            tempDepth = A[tall] - A[small];
            tall = i;
            small = tall;
        }
        else if (A[i] > A[small])
            tempDepth = A[i] - A[small];
        else if (A[i] < A[small])
            small = i;

        if (tempDepth > depth)
            depth = tempDepth;
    }
    return depth;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v = { 1,3,2,1,2,1,5,3,3,4,2 };
    vector<int> v2 = { 5, 8 };
    vector<int> v3 = { 2, 1, 3 };

    cout << solution(v) << "\n";  //2
    cout << solution(v2) << "\n"; //0
    cout << solution(v3) << "\n"; //1
}