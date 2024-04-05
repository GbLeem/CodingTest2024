#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer(prices.size());

    for (int i = 0; i < prices.size(); ++i)
    {
        int temp = 0;
        for (int j = i + 1; j < prices.size(); ++j)
        {   
            temp++;
            if (prices[i] > prices[j])            
                break;                       
        }
        answer[i] = temp;
    }
    return answer;
}
int main()
{
    vector<int> v = { 1,2,3,2,3 };
    vector<int> ans = solution(v);

    for (auto a : ans)
        cout << a << " ";
}

//1 
//2 1
//3 2 1
//