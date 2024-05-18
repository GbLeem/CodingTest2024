#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

//소문자 대문자 숫자


vector<string> split(string input, char dlim)
{
    vector<string> result;	

    stringstream ss;		
    string stringBuffer;	
    ss.str(input);			

    while (getline(ss, stringBuffer, dlim))
    {
        result.push_back(stringBuffer);
    }

    return result;
}

int solution(string& S)
{
    vector<string> temp = split(S, ' ');
    int maxCount = -1;

    for (int i = 0; i < temp.size(); ++i)
    {
        int digit = 0;
        int alpha = 0;
        for (int j = 0; j < temp[i].size(); ++j)
        {
            if (isdigit(temp[i][j]))
                digit++;
            else if (isalpha(temp[i][j]))
                alpha++;
            else
            {
                digit = 0;
                alpha = 0;
                break;
            }
        }

        if (digit == 0 && alpha == 0)
        {            
            continue;
        }
        //0은 짝수다!
        if (digit % 2 != 0 && alpha % 2 == 0 || digit % 2 != 0 && alpha == 0)
        {
            if (maxCount < digit + alpha)
                maxCount = digit + alpha;
        }
    }
    return maxCount;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s = "test 5 a0A pass007 ?xy1";
	string s1 = "123 AA";
	string s2 = "#";
	string s3 = "AA";
    string s4 = "[ F";
    string s5 = "a";
    string s6 = "zaq!2#edc";
    string s7 = "asdf! 3ab qqqq adw3";
	//space == 32
	//a == 97
	//0 == 48
	//A == 65
    cout << solution(s) << "\n";    //7
    cout << solution(s1)<<"\n";     //3
    cout << solution(s2)<<"\n";     //-1   
    cout << solution(s3)<<"\n";     //2
    cout << solution(s4) << "\n";   //-1
    cout << solution(s5) << "\n";   //-1
    cout << solution(s6) << "\n";   //-1
    cout << solution(s7) << "\n";   //3
}