//#include <string>
//#include <vector>
//#include <tuple>
//
//using namespace std;
//
//tuple<int, int, int> tempTuple[100005];
//
//vector<int> solution(string s)
//{
//    vector<int> answer;
//    string tempValue;
//    int cnt = 0;
//    int idx = 0;
//    for (int i = 0; i < s.size(); ++i)
//    {
//        if (s[i] == '{')
//            continue;
//        else if (s[i] == '}')
//        {
//            if (i != s.size() - 1 && s[i + 1] == ',') //다음 괄호로 넘어갈때
//            {
//                idx++;                                 
//            }
//
//            if (tempValue != "")
//            {
//                get<1>(tempTuple[idx]) = stoi(tempValue);
//            }
//        }
//        else if (s[i] == ',')
//        {
//
//        }
//        else
//        {
//            tempValue += s[i];
//        }
//    }
//    return answer;
//}