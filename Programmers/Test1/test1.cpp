#include <string>
#include <vector>
#include <stack>
using namespace std;

string makeTwo(int n)
{
    stack<int> s;
    string str = "";
    while (1)
    {
        s.push(n % 2);
        n /= 2;
    }
    while (!s.empty())
    {
        str += to_string(s.top());
    }
}

int solution(int n)
{
    int answer = 0;

    

    return answer;
}