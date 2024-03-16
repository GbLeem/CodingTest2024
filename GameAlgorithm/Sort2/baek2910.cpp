#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long arr[1001];

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first > b.first;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, c;

    cin >> n >> c;

    vector<pair<int, int>> arr; // count value
    for (int i = 0; i <n ;++i) 
    {
        int num;
        cin >> num;
        bool chk = false;
        for (auto& a : arr) 
        {
            if (a.second == num) 
            {
                chk = true;
                a.first++;
                break;
            }
        }
        if (!chk) arr.push_back({ 1, num });
    }
    stable_sort(arr.begin(), arr.end(), cmp);

    for (auto b : arr)
        while (b.first--) 
            cout << b.second << ' ';
}