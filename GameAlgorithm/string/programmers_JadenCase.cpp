#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s)
{
    string answer = s;
    bool first = true;
    std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

    for (int i = 0; i < s.size(); ++i)
    {        
        if (isdigit(answer[0]) == 0 && first) //맨 앞 처리
        {
            int temp = (int)answer[0];
            temp -= 32;
            char str = temp;
            answer[0] = str;
            first = false;
        }               

        else if (answer[i] == ' ') // 빈칸 다음 빈칸 아닐때
        {
            if (answer[i + 1] != ' ' && isdigit(answer[i + 1]) == 0)
            {
                int temp = (int)answer[i + 1];
                temp -= 32;
                char str = temp;
                answer[i + 1] = str;
            }
        }        
    }    
    return answer;
}

int main()
{
    string ans = "3people unFollowed me"; //3people unfollowed me
    string ans1 = "for the last week";

    string ans2 = "3   folling in 3love";
    cout << solution(ans1);
}