//행렬 곱셈
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    vector<vector<int>> answer;
    int row = arr1.size();
    int col = arr2[0].size();
    int tempCol = arr1[0].size();

    for (int i = 0; i < row; ++i)
    {
        vector<int> temp;
        for (int j = 0; j < col; ++j)
        {
            int value = 0;
            for (int k = 0; k < tempCol; ++k)
            {
                value += arr1[i][k] * arr2[k][j];
            }
            temp.push_back(value);
        }
        answer.push_back(temp);
        temp.clear();
    }

    return answer;
}