#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//소문자 대문자 숫자
//문자수는 짝수
//숫자는 홀수

int solution(string& S)
{
	vector<int> count;
	int idx = 0;
	int digit = 0;
	int alpha = 0;

	for (int i = 0; i < S.size(); ++i)
	{
		if ((int)S[i] == 32)
		{		
			if (digit == 0 && alpha % 2 == 0)
				count.push_back(digit + alpha);
			if (alpha == 0 && digit % 2 != 0)
				count.push_back(digit + alpha);
			if (digit % 2 != 0 && alpha % 2 == 0)
				count.push_back(digit + alpha);
			idx++;
			digit = 0;
			alpha = 0;
		}

		if (isdigit(S[i]))
		{
			digit++;
		}
		if (isalpha(S[i]))
		{
			alpha++;
		}
	}

	if (digit || alpha)
	{
		if (digit == 0 && alpha % 2 == 0)
			count.push_back(digit + alpha);
		if (alpha == 0 && digit % 2 != 0)
			count.push_back(digit + alpha);
		if (digit % 2 != 0 && alpha % 2 == 0)
			count.push_back(digit + alpha);
	}

	if (count.empty())
		return -1;
	if (count.size() == 1)
		return count[0];
	return *max_element(count.begin(), count.end());	
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s = "test 5 a0A pass007 ?xy1";
	string s1 = "123 AA";
	string s2 = "A";
	string s3 = "AA";
	//space == 32
	//a == 97
	//0 == 48
	//A == 65
	cout<<solution(s3);
}