#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//�ð����⵵  O(M*N) 
//timeout
// 
//vector<int> solution(int N, vector<int>& A)
//{
//    vector<int> ans(N);
//    int maxInt = 0;
//
//    for (int i = 0; i < A.size(); ++i) //A�� ����
//    {
//        if (A[i] == N + 1) // A[i] == 6 -> max counter
//        {
//            //���� ū ���� ã�Ƽ� �����ֱ�
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

            //�ð��ʰ� �ذ� ���� ���� - ��� �ؾ� �ð��ʰ��� �ذ��� �� ������
            //����) 
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