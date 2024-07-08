//할인 행사
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> um;

int solution(vector<string> want, vector<int> number, vector<string> discount)
{
    int answer = 0;
    for (int i = 0; i < want.size(); ++i)
    {
        um.insert({ want[i], number[i] });
    }

    for (int i = 0; i < discount.size(); ++i)
    {
        unordered_map<string, int> copyum(um);
        for (int cnt = i; cnt < i + 10; ++cnt)
        {
            if (cnt >= discount.size())
                break;
            copyum[discount[cnt]]--;
        }
        
        bool flag = true;
        for (const auto c : copyum)
        {
            if (c.second != 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            answer++;
    }

    return answer;
}

int main()
{
    vector<string> want = { "banana", "apple", "rice", "pork", "pot" };
    vector<int> number = { 3, 2, 2, 2, 1 };
    vector<string> discount = { "chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana" };

    cout << solution(want, number, discount);
}