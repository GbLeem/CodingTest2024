#include <iostream>
#include<string>
#include <iostream>
#include <stack>
using namespace std;

//int solution(string s)
//{
//    int answer = -1;
//    string str = s;
//    int size = s.size();
//
//    while (1)
//    {        
//        if (str.size() == 1) //one letter left
//            return 0;
//        if (str.size() == 0) //clear all
//            return 1;
//
//        s = str; //baabaa -> bbaa -> aa
//        int index = 0;
//
//        if (s[index] == s[index + 1])
//        {
//            str.clear();
//            str += s.substr(0, index + 1);
//            str += s.substr(index + 2, s.size());
//        }
//        index++;
//
//        if (index >= size)
//            return 0;
//    }
//}

int solution(string s)
{
    stack<char> str;    
    char temp = ' ';
    
    for (size_t i = 0; i < s.size(); ++i)
    {
        str.push(s[i]);

        if (str.top() == temp)
        {
            str.pop();
            str.pop();
        }
        if (!str.empty())
            temp = str.top();
        else
            temp = ' ';
    }

    if (str.empty())
        return 1;
    else
        return 0;
}


int main() 
{
    cout << solution("baabaa") << endl; //1
    cout << solution("cdcd") << endl; //0
    cout << solution("xx") << endl; //1
    cout << solution("abbbaa") << endl; //0
}