//방문 길이
//구현?
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<pair<vector<int>, vector<int>>> p;

int solution(string dirs)
{    
    vector<int> cur = { 0,0 };
    int cnt = 0;

    for (int i = 0; i < dirs.size(); ++i)
    {
        vector<int> temp = cur;
        bool find2 = false;

        if (dirs[i] == 'U')
        {
            if (temp[1] + 1 > 5)
            {
                find2 = true;                
            }
            else
                temp[1]++;
        }
        else if (dirs[i] == 'D')
        {
            if (temp[1] - 1 < -5)
            {
                find2 = true;
            }      
            else
                temp[1]--;
        }
        else if (dirs[i] == 'R')
        {
            if (temp[0] + 1 > 5)
            {
                find2 = true;                
            }             
            else
                temp[0]++;
        }
        else //L
        {
            if (temp[0] - 1 < -5)
            {
                 find2 = true;                
            }   
            else
                temp[0]--;
        }
        
        if (!find2)
        {
            bool find = false;

            for (auto pi : p)
            {
                if (cur == pi.first && temp == pi.second || cur == pi.second && temp ==pi.first)
                {
                    find = true;
                    break;
                }
            }
            p.push_back(make_pair(cur, temp));
            if(!find)
                cnt++;
        }
        cur = temp;
    }
   
    return cnt;
}

int main()
{
    //cout << solution("ULURRDLLU") << "\n";
    cout << solution("LULLLLLLU") << "\n";
}