#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int d[505][505]; //높이 방향
int solution(vector<vector<int>> triangle)
{
    int answer = 0;
    int triangleSize = triangle.size();

    d[0][0] = triangle[0][0];
    if (triangleSize == 1)
        return d[0][0];
   
    d[1][0] = d[0][0] + triangle[1][0];
    d[1][1] = d[0][0] + triangle[1][1];
    
    for (int i = 2; i < triangleSize; ++i) //높이
    {
        for (int j = 0; j < triangle[i].size(); ++j) // 해당 높이의 갯수 
        {
            //가장 왼쪽
            if (j == 0)
                d[i][j] = d[i - 1][j] + triangle[i][j];
            //가장 오른쪽
            else if (j == i)
                d[i][j] = d[i - 1][j - 1] + triangle[i][j];
            //가운데
            else
                d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + triangle[i][j];
        }
    } 

    answer = *max_element(d[triangleSize - 1], d[triangleSize - 1] + triangleSize);
    return answer;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //vector<vector<int>> vec = { {7}, {3,8}, {8,1,0}, {2,7,4,4}, {4,5,2,6,5} };
    vector<vector<int>> vec = { {1}, {1,2},{1,2,99} };
    cout<< solution(vec);
}
