#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    vector<vector<int>> answer;
    
    cout << arr1.size() << endl;
    cout << arr1[0].size() << endl;
    
    for (int i = 0; i < arr1.size(); ++i)
    {
        vector<int> temp;
        for (int j = 0; j < arr1[i].size(); ++j)
        {            
            temp.push_back(arr1[i][j] + arr2[i][j]);            
        }
        answer.push_back(temp);
    }
    return answer;
}

int main()
{
    vector<vector<int>> a = { {2,3},{4,5},{6,7} };
    vector<vector<int>> b = { {1,1},{1,1}, {1,1} };
    vector<vector<int>> ans = solution(a, b);

    cout << ans[0][0];
}