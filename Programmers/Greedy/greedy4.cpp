//#include <iostream>
//
////구명 보트
//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int solution(vector<int> people, int limit)
//{
//    int answer = 0;
//    int en = 1;
//
//    sort(people.begin(), people.end());
//
//    for (int st = 0; st < people.size(); ++st)
//    {       
//        while (en < people.size() && people[st] + people[en] <= limit && en - st < 2)
//        {
//            en++;            
//        }
//        answer++;
//        if (en == people.size())
//            break;
//    }
//    return answer;
//}
//
//int main()
//{
//    //vector<int> p = { 70,50,80 };
//    vector<int> p = { 10, 20, 30, 40 };
//    cout << solution(p, 100);
//}