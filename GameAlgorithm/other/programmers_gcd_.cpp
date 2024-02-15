#include <string>
#include <vector>

using namespace std;

int gcd(int n, int m)
{
    int res;
    while (m != 0)
    {
        res = n % m;
        n = m;
        m = res;
    }
    return n;
}
vector<int> solution(int n, int m)
{
    vector<int> answer;

    answer.push_back(gcd(n, m));
    answer.push_back((n * m) / gcd(n, m));

    return answer;
}