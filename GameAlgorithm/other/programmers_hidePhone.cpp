#include <string>
#include <vector>

using namespace std;

string solution(string phone_number)
{
    string answer = "";
    int size = phone_number.size();

    for (int i = 0; i < size - 4; ++i)
    {
        answer += "*";
    }
    for (int i = size - 4; i < size; ++i)
    {
        answer += phone_number[i];
    }

    return answer;
}