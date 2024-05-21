//연속해서 3개의 문자가 오지 않는 것이 제한조건
//A랑 B의 갯수가 주어질 때 string return 하기

//ex) A = 5 B = 3
//-> aabbaaba
//-> abbaabaa

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solution(int A, int B)
{
    vector<string> tempA;
    vector<string> tempB;
    string answer;
    bool rev = false;
    
    if (A < B)
    {
        swap(A, B);
        rev = true;
    }
    if (B == 0)
    {        
        for (int i = 0; i < A; ++i)
            answer += 'a';        
    }
    else
    {
        int gap = A / 2;

        if (A % 2 == 0 && A != 2)
            gap -= 1;

        for (int i = 0; i < gap; ++i)
            tempB.push_back("b");

        for (int i = 0; i <= gap; ++i)
            tempA.push_back("a"); // a a

        //a vector
        int restA = A - tempA.size(); //4 - 2

        if (restA <= gap)
        {
            for (int j = 0; j < restA; ++j)
            {
                if (tempA[j].size() == 1)
                    tempA[j] = "aa";
            }
        }
        while (restA > gap)
        {
            for (int j = 0; j <= gap; ++j)
            {
                if (tempA[j].size() == 1)
                    tempA[j] = "aa";
            }
            restA -= tempA.size();
        }

        /*if (restA == 1)
            tempA.push_back("a");
        else if (restA == 2)
            tempA.push_back("aa");*/

        //b vector
        int restB = B - gap;
        if (restB <= gap)
        {
            for (int j = 0; j < restB; ++j)
            {
                if (tempB[j].size() == 1)
                    tempB[j] = "bb";
            }
            restB -= tempB.size();
        }
        if (restB > gap)
        {
            for (int j = 0; j < gap; ++j)
            {
                if (tempB[j].size() == 1)
                    tempB[j] = "bb";
            }
            restB -= tempB.size();
        }

        if (restB == 1)
            tempB.push_back("b");
        else if (restB == 2)
            tempB.push_back("bb");

        /*for (auto a : tempA)
            cout << a << " ";
        cout << "\n";

        for (auto b : tempB)
            cout << b << " ";
        cout << "\n";*/

        int idxA = 0;
        int idxB = 0;
        for (int i = 0; i < tempA.size() + tempB.size(); ++i)
        {
            if (i % 2 == 0)
            {
                answer += tempA[idxA];
                idxA++;
            }
            else
            {
                answer += tempB[idxB];
                idxB++;
            }
        }
    }
    if(rev) //A < B
    {
        for (int i = 0; i < answer.size(); ++i)
        {
            if (answer[i] == 'a')
                answer[i] = 'b';
            else
                answer[i] = 'a';
        }
    }
    return answer;
}

int main()
{
    cout << solution(4, 1) << "\n";
    cout << solution(1, 4) << "\n";
    cout << solution(3, 3) << "\n";
    cout << solution(5, 3) << "\n";
    cout << solution(2, 0) << "\n";
    cout << solution(0, 2) << "\n";
}