#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

bool solution(vector<string> phone_book)
{
    unordered_map<string, int> um;
    for (int i = 0; i < phone_book.size(); ++i)
    {
        um[phone_book[i]] = 1;
    }

    for (int i = 0; i < phone_book.size(); ++i)
    {
        string temp = "";
        for (int j = 0; j < phone_book[i].size(); ++j)
        {
            temp += phone_book[i][j];
            if (um[temp] && phone_book[i] != temp)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
	vector<string> v1 = { "119", "97674223", "1195524421" };
	cout << solution(v1) << "\n";
	vector<string> v2 = { "123","456","789" };
	cout << solution(v2);
}