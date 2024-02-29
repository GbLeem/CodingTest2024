#include <iostream>
#include <list>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;
	cout << "<";
	list<int> li;

	for (int i = 0; i < N; ++i)
	{
		li.push_back(i + 1); //1 2 3 4 5 6 7
	}

	list<int>::iterator it = li.begin(); //1
	
	while (!li.empty())
	{
		for (int i = 0; i < K - 1 ; ++i)
		{
			it++;
			if (it == li.end())
			{
				it = li.begin();			
			}		
		}

		if (li.size() == 1)
			cout << *it;
		else
			cout << *it << ", ";
		it = li.erase(it);
		if (it == li.end())
			it = li.begin();
	}

	cout << ">";
}