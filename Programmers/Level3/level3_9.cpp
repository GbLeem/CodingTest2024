//기지국 설치
//-> 효율성 0%
#include <iostream>
#include <vector>
using namespace std;

int vec[200050000];
int solution(int n, vector<int> stations, int w)
{
    //n개의 아파트
    //현재 설치 stations
    //w 새로운 기지국 범위
    int answer = 0;

    for (int i = 0; i < stations.size(); ++i)
    {
        vec[stations[i]] = 1; //vec[9] = 1
        for (int j = w; j > 0; --j)
        {
            if (stations[i] - j > 0)
                vec[stations[i] - j] = 1; //9 - 1
            if(stations[i] + w + 1 - j <= n)
                vec[stations[i] + w + 1 - j] = 1; // 9 + 2 -1 = 10                
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (vec[i] == 0)        
            cnt++;
        if (vec[i] == 1 && cnt > 0)
        {
            double d = (double)cnt / (2 * w + 1);
            int id = cnt / (2 * w + 1);
            if (id < d)
                answer += (id + 1);
            else
                answer += id;
            cnt = 0;
        }
    }
    if (cnt > 0)
    {
        double d = (double)cnt / (2 * w + 1);
        answer += ceil(d);
        cnt = 0;
    }
    
    return answer;
}

int main()
{
    //vector<int> s = { 4, 11 };
    //cout << solution(11, s, 1) << "\n";
    vector<int> s1 = { 9 };
    cout << solution(16, s1, 2) << "\n";;
     
    //vector<int>s2 = { 1,2,3,4,5 };
    //cout << solution(5, s2, 1) << "\n";; //0

    //vector<int>s3 = { 3 };
    //cout << solution(5, s3, 2) << "\n";; //0

    //vector<int> s4 = { 100000000 };
    //cout << solution(200000000, s4, 5) << "\n"; //18181818

    //vector<int> s5 = { 1,16 };
    //cout << solution(16, s5, 2); //2
}