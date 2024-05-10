#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) 
{
    int answer = 0;    
    sort(citations.begin(), citations.end());

    for (int flag = 0; flag <= citations.back(); ++flag) //h번 이상
    {
        int cnt = 0;
        for (int i = 0; i < citations.size(); ++i)
        {
            if (flag <= citations[i])
                cnt++; //h개
        }
        if (flag == cnt)
            answer = cnt;
    }

    return answer;
}

int solution2(vector<int> citations)
{
    int answer = 0;
    int n = citations.size();

    sort(citations.begin(), citations.end());

    for (int j = 0; j < citations.size(); ++j) //가장 큰 인용된 횟수
    {
        int cnt = 0;
        for (int i = 0; i < citations.size(); ++i)
        {
            if (citations[j] <= citations[i])
                cnt++;
        }
        cnt = min(cnt, citations[j]);
        answer = max(cnt, answer);
    }

    return answer;
}

int main() 
{
    vector<int> v= { 3, 0, 6, 1, 5 };
    vector<int> v2 = { 6, 5, 3, 3, 0 };
    vector<int> v3 = { 10, 8, 5, 4, 3 };

    cout<<solution2(v3);

}

//[10, 8, 5, 4, 3] 의 인용횟수를 가진 교수가 있다면
//10번 이상 인용 횟수를 가진 논문은 1편입니다.이때 H - Index는 1입니다.
//8번 이상 인용 횟수를 가진 논문은 2편입니다.이때 H - Index는 2입니다.
//5번 이상 인용 횟수를 가진 논문은 3편입니다.이때 H - Index는 3입니다.
//4번 이상 인용 횟수를 가진 논문은 4편입니다.이때 H - Index는 4입니다.
//3번 이상 인용 횟수를 가진 논문은 5편입니다.이때 H - Index는 3입니다.