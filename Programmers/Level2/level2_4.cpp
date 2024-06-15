//예상 대진표

//#include <iostream>
//#include <cmath>
//using namespace std;
//
//int solution(int n, int a, int b)
//{
//    int cntA = 0;
//    int cntB = 0;
//    int cnt = 0;
//    double tempN = n;
//
//    while (tempN > 0)
//    {
//        tempN = sqrt(tempN);
//        cnt++;
//    }
//
//    cout << cnt;
//    if (b - a == 1)
//        return 1;
//
//    if (a % 2 != 0)
//        a += 1;
//    if (b % 2 != 0)
//        b += 1;
//
//    cntA = a / 2;
//    cntB = b / 2;
//
//    if (cntB > n / 2)
//        return cnt;
//    return cntB - cntA + 1;
//
//}