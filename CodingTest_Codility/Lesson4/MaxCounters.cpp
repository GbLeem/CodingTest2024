#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//시간복잡도  O(M*N) 
//timeout
// 
//vector<int> solution(int N, vector<int>& A)
//{
//    vector<int> ans(N);
//    int maxInt = 0;
//
//    for (int i = 0; i < A.size(); ++i) //A를 돌기
//    {
//        if (A[i] == N + 1) // A[i] == 6 -> max counter
//        {
//            //가장 큰 숫자 찾아서 맞춰주기
//            for (const auto& a : ans)
//            {
//                if (maxInt < a)
//                    maxInt = a;
//            }
//
//            for (int j = 0; j < N; ++j)
//            {
//                ans[j] = maxInt;
//            }
//        }
//        else
//            ans[A[i] - 1]++;
//    }
//    return ans;
//}


vector<int> solution(int N, vector<int>& A)
{
    vector<int> ans(N);
    int maxInt = 0;

    for (int i = 0; i < A.size(); ++i)
    {
        if (A[i] == N + 1)
        {
            ans.clear();
            ans.resize(N, maxInt);
        }
        else
        {
            ans[A[i] - 1]++;

            //시간초과 해결 아직 못함 - 어떻게 해야 시간초과를 해결할 수 있을까
            //참고) 
            //https://sorious77.tistory.com/19
            
            if (ans[A[i] - 1] > maxInt)
            {
                maxInt = ans[A[i] - 1];
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> a = { 3, 4, 4, 6, 1, 4, 4 };
    vector<int> ans = solution(5, a);

    for (auto ai : ans)
    {
        cout << ai << " ";
    }
}