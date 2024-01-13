#include <stack>
#include <string>
#include <iostream>
using namespace std;

int solution(string& S)
{
    stack<int> s;
    char lastChar = ' ';
    for (int i = 0; i < S.size(); ++i)
    {
        if (S[i] == '(' || S[i] == '{' || S[i] == '[')
        {
            s.push(S[i]);
            lastChar = s.top();
        }
        if (s.empty() && S[i] == ')' || S[i] == '}' || S[i] == ']')
            return 0;
        else
        {           
            if (!s.empty())
            {
                lastChar = s.top();
                if (S[i] == ')')
                {
                    if (lastChar == '(')
                    {
                        s.pop();                        
                    }
                }
                if (S[i] == ']')
                {
                    if (lastChar == '[')
                        s.pop();
                }
                if (S[i] == '}')
                {
                    if (lastChar == '{')
                        s.pop();
                }                
            }
        }
    }
    if (s.empty())
        return 1;
    return 0;
}

int main()
{
    string s1 = "()()()";
    string s2 = "(({})))";
   
    cout << solution(s1) << endl;
    cout << solution(s2) << endl;
}