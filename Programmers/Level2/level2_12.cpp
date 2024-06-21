//연속 부분 수열 합의 개수
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> elements)
{
    int answer = 0;
    set<int> s;

    for (int m = 1; m <= elements.size(); ++m) //연속된 수
    {        
        int temp = 0;
        for (int start = 0; start < elements.size(); ++start)
        {
            for (int i = start; i < start + m; ++i)
            {
                if (i >= elements.size())
                    temp += elements[i % elements.size()];
                else
                    temp += elements[i];
            }
            s.insert(temp);
            temp = 0;
        }
    }

    return s.size();
}

//다른 사람 풀이
int solution2(vector<int> elements) 
{
    set<int> S;

    int n = elements.size();

    for (int i = 0; i < n; ++i) 
    {
        int sum = 0;
        for (int j = i; j < i + n; ++j) 
        {
            sum += elements[j % n];
            S.insert(sum);
        }
    }

    return S.size();
}

int main()
{
    vector<int> elements1 = { 7,9,1,1,4 };

    cout << solution2(elements1);
}