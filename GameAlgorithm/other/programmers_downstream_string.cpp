#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s)
{
    string answer = s;
    std::sort(answer.begin(), answer.end(), std::greater<int>());
    
    return answer;
}

int main()
{
    cout << solution("Zbcdefg");
}