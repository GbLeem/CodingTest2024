#include <iostream>
#include<string>
#include <iostream>
using namespace std;

int solution(string s)
{
    int answer = -1;
    string str = s;

    while (1)
    {
        if (str.size() == 1)
            return 0;
        if (str.size() == 0)
            return 1;

        s = str;
        str.clear();

        for (size_t i = 0; i < s.size() - 1; ++i)
        {
            if ((int)s[i] == (int)s[i + 1])
            {
                //simple?                
                for (size_t j = i + 2; j < s.size(); ++j)
                {
                    str += s[j];
                }
                break;
            }
            str += s[i];
        }
        //cout << str << " ";
    }
    
    return answer;
}

int main()
{
    cout << solution("baabaa") << endl;
    cout << solution("cdcd") << endl;

}