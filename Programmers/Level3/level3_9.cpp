//기지국 설치

#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    //n개의 아파트
    //현재 설치 stations
    //w 새로운 기지국 범위
    int answer = 0;
    vector<int> vec(2*n);

    for (int i = 0; i < stations.size(); ++i)
    {
        vec[stations[i]]++; //vec[9] = 1
        for (int j = w; j > 0; --j)
        {
            vec[stations[i] - j]++; //9 - 1
            vec[stations[i] + w + 1 - j]++;// 9 + 2 -1 = 10
        }
    }
    vector<int> temp(n);
    int idx = 0;
    for (int i = 1; i < n; ++i)
    {
        if (vec[i] == 0) //방문 x
        {
            temp[idx]++;                  
        }
        if(vec[i] ==1)
            idx++;
    }

   for(auto t: temp)
   {
       while (t > 2 * w + 1)
       {
           answer++;
           t -= 2 * w + 1;
       }
   }

    return answer;
}

int main()
{
    vector<int> s = { 4,11 };
    cout<<solution(11, s, 1);
}