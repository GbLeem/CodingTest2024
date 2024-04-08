#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int>& A)
{
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    return A.size();
}

int main()
{
    vector<int> a = { 2, 1, 1, 2, 3, 1, 3 }; 
    //vector<int> b = {  };
    //vector<int> c = { 1, 1'000'000 };
    cout << solution(a) << endl;
    //cout << solution(b) << endl;
    //cout << solution(c) << endl;
}