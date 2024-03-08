#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;

	vector<int> num;
	bool plus = true;
	string s = "";

	for (int i = 0; i < str.size(); ++i)
	{		
		if (i == str.size() - 1)
		{
			s += str[i];
			if(plus)
				num.push_back(stoi(s));
			else
				num.push_back(-stoi(s));
		}
		if (str[i] == '+')
		{
			if (plus)
			{
				num.push_back(stoi(s));
				s.clear();
			}
			else
			{
				num.push_back(-stoi(s));
				s.clear();
			}	
			plus = true;
		}
		else if (str[i] == '-')
		{
			if (plus)
			{
				num.push_back(stoi(s));
				s.clear();
			}
			else
			{
				num.push_back(-stoi(s));
				s.clear();
			}
			plus = false;
		}
		else //숫자
		{
			s += str[i];
		}
	}

	int answer = 0;
	for (int i = 0; i < num.size(); ++i)
	{
		if (num[i] < 0)
		{
			int temp = -num[i];
			while (i + 1 < num.size() && num[i + 1] > 0)
			{
				i++;
				temp += num[i];
			}
			answer += -temp;
		}
		else
		{
			answer += num[i];
		}
	}
	cout << answer;
}