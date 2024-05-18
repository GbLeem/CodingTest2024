#include <iostream>

int solution(int P, int C)
{
    int Game = 0;
    Game = P / 2;

    if (Game <= C)
        return Game;
    else
        return C;
}