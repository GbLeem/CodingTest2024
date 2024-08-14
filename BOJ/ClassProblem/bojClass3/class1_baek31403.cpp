#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b, c;
    cin >> a >> b >> c;

    string temp = a + b;

    cout << stoi(a) + stoi(b) - stoi(c) << "\n";
    cout << stoi(temp) - stoi(c);
}