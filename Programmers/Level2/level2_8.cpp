//귤 고르기
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, vector<int> tangerine)
{
    //1 2 2 3 3 4 5 5 -> 6
    //길이가 긴 것부터 넣기

    int answer = 0;
    vector<int> length;
    sort(tangerine.begin(), tangerine.end());
    int cnt = 1;
    for (int i = 0; i < tangerine.size(); ++i)
    {
        if (i == tangerine.size() - 1 && cnt != 0)
            length.push_back(cnt);
        else if (tangerine[i] != tangerine[i + 1])
        {
            length.push_back(cnt);
            cnt = 1;
        }
        else
        {
            cnt++;
        }
    }
    sort(length.begin(), length.end(), greater<int>());
    
    for (int i = 0; i < length.size(); ++i)
    {
        k -= length[i];
        answer++;
        if (k <= 0)
        {
            return answer;
        }
    }
    return answer;
}

int main()
{
    vector<int> v1 = { 1, 3, 2, 5, 4, 5, 2, 3 };
    vector<int> v2 = { 1, 1, 1, 1, 2, 2, 2, 3 };
    cout<<solution(2, v2);
    cout<<solution(6, v1);

}