#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

vector<int> solution(int n, vector<string> words)
{
    vector<int> answer;
    vector<string> vec;

    for (size_t i = 0; i < words.size() - 1; ++i) //전체 배열 다 돌기
    {
        vec.push_back(words[i]);

        if (vec[i][vec[i].size() - 1] != words[i + 1][0])
        {
            if ((i + 2) % n == 0)
                answer.push_back(n);
            else
                answer.push_back((i + 2) % n);

            answer.push_back(ceil((i + 2) / (float)n));
            return answer;
        }


        for (size_t j = 0; j < vec.size(); ++j)
        {
            if (vec[j] == words[i + 1]) //같은 것 발견
            {
                if ((i + 2) % n == 0)
                    answer.push_back(n);
                else
                    answer.push_back((i + 2) % n);

                answer.push_back(ceil((i + 2) / (float)n));
                return answer;
            }
        }
    }

    answer.push_back(0);
    answer.push_back(0);

    return answer;
}

int main()
{
    
    vector<string> words = { "tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank" };
    vector<string> words2 = { "hello", "observe", "effect", "take", "either", "recognize", "encourage", "ensure", "establish", "hang", "gather", "refer", "reference", "estimate", "executive" };
    vector<string> words3 = { "hello", "one", "even", "never", "now", "world", "draw" };


    


    vector<int> ans = solution(3, words);
    cout << ans[0] << " " << ans[1] << endl;

    vector<int> ans2 = solution(5, words2);
    cout << ans2[0] << " " << ans2[1] << endl;

    vector<int> ans3 = solution(2, words3);
    cout << ans3[0] << " " << ans3[1] << endl;
}