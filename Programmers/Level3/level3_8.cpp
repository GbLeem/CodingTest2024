//#include <iostream>
//
////큰 수 만들기
//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//string solution(string number, int k)
//{
//    string answer = "";
//    vector<int> vec;
//
//    for (int i = 0; i < number.size(); ++i)
//    {
//        vec.push_back(number[i] - '0');
//    }
//    sort(vec.begin(), vec.end(), greater<>()); //9421
//
//    for (int i = 0; i < number.size() - k; ++i)
//    {
//        //9 -> '9'
//        answer += vec[i] + '0';
//    }
//
//    return answer;
//}
//
//int main()
//{
//    string s = "1924";
//    cout<<solution(s, 2);
//}