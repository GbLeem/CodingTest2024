//기지국 설치
//100%
#include <iostream>
#include <vector>
using namespace std;


int solution(int n, vector<int> stations, int w)
{
    //n개의 아파트
    //현재 설치 stations
    //w 새로운 기지국 범위
    int answer = 0;
    int minVal = 0;
    int maxVal = 0;
    int tempVal = 0;

    for (int i = 0; i < stations.size(); ++i)
    {
        minVal = stations[i] - w; //3 -> 10
        maxVal = stations[i] + w; //5 -> 12
        
        if (minVal > 1 && i == 0) //왼쪽 끝 처리(맨 처음만)
        {
            int temp = minVal - 1;
            answer += ceil(double(temp) / (2 * w + 1));            
        }
        if (tempVal > 0 && i != 0) //가운데 처리
        {
            int temp = minVal - tempVal - 1;
            answer += ceil(double(temp) / (2 * w + 1));
        }
        if (i == stations.size() - 1 && maxVal < n) //오른쪽끝 (맨 마지막만)
        {
            int temp = n - maxVal;
            answer += ceil(double(temp) / (2 * w + 1));            
        }
        tempVal = maxVal;
    }
    
    return answer;
}

int main()
{
    vector<int> s = { 4, 11 };
    cout << solution(11, s, 1) << "\n"; //3

    vector<int> s1 = { 9 };
    cout << solution(16, s1, 2) << "\n";; //3
     
    vector<int>s2 = { 1,2,3,4,5 };
    cout << solution(5, s2, 1) << "\n";; //0

    vector<int>s3 = { 3 };
    cout << solution(5, s3, 2) << "\n";; //0

    vector<int> s4 = { 100000000 };
    cout << solution(200000000, s4, 5) << "\n"; //18181818

    vector<int> s5 = { 1,16 };
    cout << solution(16, s5, 2); //2
}