//스킬트리

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int solution(string skill, vector<string> skill_trees)
{
    int answer = 0;
    vector<char>vec(skill.size()); //C B D

    for (int i = 0; i < skill.size(); ++i)
        vec.push_back(skill[i]);

    for (int i = 0; i < skill_trees.size(); ++i)
    {
        queue<char> temp;
        for (int j = 0; j < skill_trees[i].size(); ++j)
        {
            if (find(vec.begin(), vec.end(), skill_trees[i][j]) != vec.end())
                temp.push(skill_trees[i][j]); //C B
        }      

        int index = 0;
        bool find = true;

        while (!temp.empty())
        {
            if (skill[index] == temp.front())
            {
                temp.pop();
                index++;
            }
            else
            {
                find = false;
                break;
            }
        }
        if (find)
            answer++;
    }

    return answer;
}

int main()
{
    vector<string> sk = { "BACDE", "CBADF", "AECB", "BDA" };

    cout << solution("CBD", sk);
}