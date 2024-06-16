//괄호 회전하기
#include <iostream>

#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s)
{
    int answer = s.size() - 1;
    stack<char>q;
    for (int i = 0; i < s.size() - 1; ++i)
    {
        bool flag = true;
        for (int j = i; j < i + s.size(); ++j) //항상 size갯수만큼 
        {
            int tempJ = -1;
            if (j >= s.size())
            {
                tempJ = j % s.size();
                //j %= s.size(); // 6 -> 0
            }
            if (tempJ != -1)
            {
                if (s[tempJ] == '[' || s[tempJ] == '{' || s[tempJ] == '(')
                    q.push(s[tempJ]);
                else if (s[tempJ] == ']')
                {
                    if (!q.empty() && q.top() == '[')
                        q.pop();
                    else
                    {
                        flag = false;
                        answer--;
                        break;
                    }

                }
                else if (s[tempJ] == '}')
                {
                    if (!q.empty() && q.top() == '{')
                        q.pop();
                    else
                    {
                        flag = false;
                        answer--;
                        break;
                    }
                }
                else if (s[tempJ] == ')')
                {
                    if (!q.empty() && q.top() == '(')
                        q.pop();
                    else
                    {
                        flag = false;
                        answer--;
                        break;
                    }
                }
            }
            else
            {
                if (s[j] == '[' || s[j] == '{' || s[j] == '(')
                    q.push(s[j]);
                else if (s[j] == ']')
                {
                    if (!q.empty() && q.top() == '[')
                        q.pop();
                    else
                    {
                        flag = false;
                        answer--;
                        break;
                    }

                }
                else if (s[j] == '}')
                {
                    if (!q.empty() && q.top() == '{')
                        q.pop();
                    else
                    {
                        flag = false;
                        answer--;
                        break;
                    }
                }
                else if (s[j] == ')')
                {
                    if (!q.empty() && q.top() == '(')
                        q.pop();
                    else
                    {
                        flag = false;
                        answer--;
                        break;
                    }
                }
            }
        }
        if (flag && !q.empty())
            answer--;
    }

    return answer;
}

int main()
{
    cout << solution("[](){}") << "\n";
    cout << solution("}]()[{") << "\n";
    cout << solution("(){{") << "\n"; //0
}