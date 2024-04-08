#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int intersect(int c, int r, vector<pair<int, int>>& v)
{
	int ct = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		if (abs(v[i].second - c) <= r + v[i].first)
			ct++;
	}
	return (ct - 1) / 2;
}

int solution(vector<int>& A)
{
	vector<pair<int, int>> vec(A.size()); //r c
	for (int i = 0; i < A.size(); ++i)
	{
		vec[i].first = A[i];
		vec[i].second = i;
	}
	sort(vec.begin(), vec.end());
	int cnt = 0;

	for (int i = 0; i < vec.size(); ++i)
	{
		cnt += intersect(vec[i].first, vec[i].second, vec);
	}

	return cnt;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> a = { 1,5,2,1,4,0 };
	cout << solution(a);
}