//롤케이크 자르기
#include <iostream>


#include <string>
#include <vector>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;

int solution(vector<int> topping)
{
    int answer = 0;
    set<int> s;
    unordered_map<int, int> um;
    unordered_map<int, int> um2;
    for (int i = 0; i < topping.size(); ++i)
        um[topping[i]]++;    

    for (int i = 0; i < topping.size(); ++i)
    {
        um[topping[i]]--;
        um2[topping[i]]++;
        
        if (um[topping[i]] == 0)
            um.erase(topping[i]);        
        
        if (um.size() == um2.size())
            answer++;
    }
    
    return answer;
}

int main()
{
    vector<int> topping = { 1,2,1,3,1,4,1,2 };

    cout << solution(topping);
}