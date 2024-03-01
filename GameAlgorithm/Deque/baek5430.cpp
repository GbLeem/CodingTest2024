#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		string p; //function
		cin >> p;
		int n;    //num of list 
		cin >> n; 
		string num;//list
		cin >> num;
		
		deque<int>dq;
		string temp = "";

		for (int i = 1; i < num.size(); ++i)
		{
			if (num[i] == ',' || num[i] == ']')
			{
				if (temp != "") // []
				{
					dq.push_back(stoi(temp));
					temp.clear();
				}
			}
			else			
				temp += num[i];
		}

		bool error = false;
		int reverse = 0;
		for (int i = 0; i < p.size(); ++i)
		{
			if (p[i] == 'R')
			{
				reverse++;
			}
			else //D
			{
				if (dq.empty())
				{
					cout << "error\n";
					error = true;
					break;
				}
				if(reverse % 2 != 0)
					dq.pop_back();
				else
					dq.pop_front();
			}
		} 
		
		if (!error)
		{
			cout << "[";
			while (!dq.empty())
			{
				if (reverse % 2 == 0)
				{
					if (dq.size() == 1)
						cout << dq.front();
					else
						cout << dq.front() << ",";
					dq.pop_front();
				}
				else
				{
					if (dq.size() == 1)
						cout << dq.back();
					else
						cout << dq.back() << ",";
					dq.pop_back();
				}
			}
			cout << "]\n";
		}
	}
}