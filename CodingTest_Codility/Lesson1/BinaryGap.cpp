#include <iostream>
using namespace std;

int solution(int N)
{
    int maxGap = 0;
    int Gap = 0;
    int flag = 0;

    while (N != 0)
    {
        if (N % 2 == 1) //1 일때
        {            
            flag++;
            if (flag == 2)
            {
                if(Gap > maxGap)
                    maxGap = Gap;
                Gap = 0;
                flag = 1;
            }
        }
        else //0 일때
        {
            if (flag == 1)
            {              
                Gap++;
            }
        }
        N /= 2;
    }
    return maxGap;
}

int main()
{
    cout << solution(1041) << endl; //5 10000010001
    cout << solution(15) << endl; //0 1111
    cout << solution(32) << endl; //0 100000
    cout << solution(6) << endl; //0 110
    cout << solution(328) << endl; //2 101001000

    cout << solution(561892) << endl; //3  10001001001011100100
    cout << solution(1376796946) << endl; //5
    cout << solution(51712) << endl;//2
    cout << solution(42) << endl;//1
}