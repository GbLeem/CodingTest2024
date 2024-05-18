#include <vector>
#include <iostream>

#include <map>
#include <algorithm>
using namespace std;
//맨 처음으로 나오는 중복되지 않은 수 return 하기

int solution(vector<int>& A)
{
    map <int, pair<int,int>> idx; // value, cnt
    vector<pair<int, int>> vec; //인덱스 저장
    vector<int> temp(A); //sorting
    
    for (int i = 0; i < A.size(); ++i)
    {
        vec.push_back({ A[i], i });        
        idx.insert({ A[i], {0, i} }); //key value
    }

    sort(temp.begin(), temp.end());
    sort(vec.begin(), vec.end());

    int tempIdx = 100001;
    int cnt = 0;

    for (int i = 0; i < vec.size(); ++i)
    {      
        if (binary_search(temp.begin(), temp.end(), vec[i].first)) //찾으면
            idx[vec[i].first].first++;
    }
    for (int i = 0; i < temp.size(); ++i)
    {
        if (idx[temp[i]].first == 1) // {(2,1) (4,2) (5,1) (10,2)}
        {
            if (tempIdx > idx[temp[i]].second)
                tempIdx = idx[temp[i]].second;
        }
    }
    if (tempIdx == 100001)
        return -1;
    return A[tempIdx];
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v1 = { 4, 10, 5 ,4, 2, 10 }; // 2 4 4 5 10 10 
    vector<int> v2 = { 1, 4, 3, 3, 1, 2 }; // 1 1 2 3 3 4
    vector<int> v3 = { 6,4,4,6 };

    cout << solution(v1) << "\n";
    cout << solution(v2) << "\n";
    cout << solution(v3) << "\n";
}
