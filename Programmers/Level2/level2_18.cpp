//뒤에 있는 큰 수 찾기
#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> numbers)
{
    vector<int> answer(numbers.size(), -1);
    stack<int> s;

    s.push(numbers[numbers.size() - 1]);

    for (int i = numbers.size() - 2; i >= 0; --i)
    {
        bool find = false;

        while (!s.empty())
        {
            int temp = s.top();
            s.pop();

            if (temp > numbers[i])
            {
                answer[i] = temp;
                find = true;
                break;
            }
        }
        if (find)
            s.push(answer[i]);
        s.push(numbers[i]);
    }

    return answer;
}




//참고) 주식 가격
//#include <string>
//#include <vector>
//#include <stack>
//
//using namespace std;
//
//vector<int> solution(vector<int> prices) 
//{
//    vector<int> answer(prices.size());
//    stack<int> s;
//    int size = prices.size();
//
//    for (int i = 0; i < size; i++) 
//    {
//        while (!s.empty() && prices[s.top()] > prices[i]) 
//        {
//            answer[s.top()] = i - s.top();
//            s.pop();
//        }
//        s.push(i);
//    }
//    while (!s.empty()) 
//    {
//        answer[s.top()] = size - s.top() - 1;
//        s.pop();
//    }
//    return answer;
//}