// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

int solution(string& S)
{
    int mid = S.size() / 2;
    queue<char> q;
    stack<char> s;

    if (S.size() == 0)
        return -1;
    if (S.size() % 2 == 0)
        return -1;
    for (int i = 0; i < S.size(); ++i)
    {
        q.push(S[i]);
        s.push(S[i]);
    }

    bool same = true;
    for (int i = 0; i < q.size(); ++i)
    {
        if (q.front() != s.top())
        {
            same = false;
            break;
        }
        q.pop();
        s.pop();
    }
    if (same)
        return mid;
    else
        return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s1 = "";
    string s2 = "aabb";
    string s3 = "xxvxx";
    string s4 = "abba";
    cout << solution(s1)<<'\n';
    cout << solution(s2) << "\n";
    cout << solution(s3) << "\n";
    cout << solution(s4) << "\n";
}
