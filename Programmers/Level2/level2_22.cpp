//땅따먹기
//DP

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int d[100005][5]; //층, 인덱스

int solution(vector<vector<int> > land)
{
	int answer = 0;
	int n = land.size();

	/*d[1][0] = land[0][0];
	d[1][1] = land[0][1];
	d[1][2] = land[0][2];
	d[1][3] = land[0][3];*/

	for (int i = 1; i <= n; ++i)
	{
		d[i][0] = max(max(d[i - 1][1], d[i - 1][2]), d[i - 1][3]) + land[i-1][0];
		d[i][1] = max(max(d[i - 1][0], d[i - 1][2]), d[i - 1][3]) + land[i-1][1];
		d[i][2] = max(max(d[i - 1][0], d[i - 1][1]), d[i - 1][3]) + land[i-1][2]; 
		d[i][3] = max(max(d[i - 1][0], d[i - 1][1]), d[i - 1][2]) + land[i-1][3];
	}

	answer = *max_element(d[n], d[n] + 4);

	return answer;
}

int main()
{
	vector<vector<int>> v = { {1,2,3,5},{5,6,7,8},{4,3,2,1} };
	cout<<solution(v);
}