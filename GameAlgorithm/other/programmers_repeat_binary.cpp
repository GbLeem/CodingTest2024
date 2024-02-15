#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(string s)
{
    vector<int> answer;
    int ans = 0;
    int zero = 0;
    while (s != "1")
    {
        int cnt = 0;
        for (size_t i = 0; i < s.size(); ++i)
        {
            if (s[i] == '1')
                cnt++;
        }
        zero += (s.size() - cnt);
        s.clear();

        //이진수로 바꾸기 (cnt 를 2진수로)
        while (cnt >= 1)
        {
            if (cnt % 2 == 0)
                s += "0";
            else
                s += "1";            
            cnt /= 2;
        }        
        std::reverse(s.begin(), s.end());
        ans++;
    }

    answer.push_back(ans);
    answer.push_back(zero);


    return answer;
}

int main()
{
    string s = "110010101001";
    vector<int> ans= solution(s);
    cout << ans[0] << " " << ans[1];
}