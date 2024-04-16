#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes)
{
    int answer = 0;
    unordered_map<string, int> um;

    for (int i = 0; i < clothes.size(); ++i)
    {
        um[clothes[i][1]]++;
    }

    int ans = 1;

    //map 에서는 range for 써야지....
    for (auto u : um)
        ans *= u.second + 1;

    ans -= 1;
    answer = ans;
    return answer;
}