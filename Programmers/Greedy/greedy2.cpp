#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string name)
{
    int answer = 0;
    bool reverse = false;

    for (int i = 0; i < name.size(); ++i)
    {        
        if (name[i] != 'A')
        {
            if (name[i] - 0 <= 77)
            {
                answer += (name[i] - 'A' - 0);
            }

            else
            {
                answer += ('Z' - name[i] + 1);
            }
        }
        else if (name[i] == 'A' && !reverse)
        {
            answer -= 1;
            reverse = true;
        }
        if (i == name.size() - 1)
            break;
        answer += 1;
            
    }
    return answer;
}

int main()
{
    cout << solution("JEROEN")<<"\n"; //56
    cout << solution("JANN")<<"\n"; //37
    cout << solution("JAN") << "\n"; //23
    cout << solution("JACCA") << "\n"; //16
    cout << solution("JAA") << "\n"; //9
}