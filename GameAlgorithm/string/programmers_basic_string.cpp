#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int cnt = 0;
    if (s.size() == 4 || s.size() == 6)
    {
        for (int i = 0; i < s.size(); ++i)
        {
            if ((int)s[i] >= 65)
                return false;
            cnt++;
        }
    }    
    if (cnt == s.size())
        return true;
    return false;
}

int main()
{
    cout << solution("1234") << endl;
    cout << solution("Aabb22");

}