#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> divisor(int n)
{
	vector<int> div;

	for (int i = 1; i * i <= n; ++i)
	{
		if (n % i == 0)
			div.push_back(i);
	}
	for (int j = (int)div.size() - 1; j >= 0; --j)
	{
		if (div[j] * div[j] == n)
			continue;
		div.push_back(n / div[j]);
	}
	return div;
}

int solution(int N)
{
	int answer = 0;
	
	for (unsigned int i = 1; i * i <= N; ++i)
	{	
		if (i * i == N)
			answer++;
		else if (N % i == 0)
			answer += 2;		
	}
	
	return answer;
}

int main()
{
	cout<<solution(24)<<"\n";
	cout << solution(2147483647) << "\n";
}