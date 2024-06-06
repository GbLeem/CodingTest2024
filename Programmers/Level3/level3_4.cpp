//등굣길
//DP

#include <string>
#include <vector>
#include <iostream>
using namespace std;
int d[105][105];

int solution(int m, int n, vector<vector<int>> puddles)
{
    for (int i = 0; i < puddles.size(); ++i)
    {
        d[puddles[i][1]][puddles[i][0]] = -1; //못가는곳          
    }

    for (int i = 1; i <= n; ++i) //row
    {
        if (d[i][1] != -1)
            d[i][1] = 1;
        else
            break;
    }

    for (int j = 1; j <= m; ++j) //col
    {
        if (d[1][j] != -1)
            d[1][j] = 1;
        else
            break;
    }

    for (int i = 2; i <= n; ++i)
    {
        for (int j = 2; j <= m; ++j)
        {
            if (d[i][j] != -1)
            {
                if (d[i][j - 1] == -1)
                    d[i][j] = d[i - 1][j] % 1'000'000'007;

                else if (d[i - 1][j] == -1)
                    d[i][j] = d[i][j - 1] % 1'000'000'007;
                else
                    d[i][j] = (d[i][j - 1] + d[i - 1][j]) % 1'000'000'007;
            }
            else
                continue;
        }
    }

    return d[n][m];
}