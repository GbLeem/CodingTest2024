#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, m;
int level[100005]; //난이도
set<int> s[100005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	while (n--)
	{
		int p, l;
		cin >> p >> l; //번호 난이도

		level[p] = l; // [번호, 난이도]
		s[l].insert(p); //난이도에 번호 넣기 -> 난이도 순 정렬
	}	
	cin >> m;

	while (m--)
	{
		string query;
		cin >> query;

		if (query == "add")
		{
			int L, P;
			cin >> P >> L;
			level[P] = L;
			s[L].insert(P);
		}
		else if (query == "recommend")
		{
			int num;
			cin >> num;
			if (num == 1) //가장 어려운 문제
			{							
				for (int i = 100; i >= 0; --i)
				{
					if (s[i].empty())
						continue;
					cout << *(prev(s[i].end())) << "\n";
					break;
				}
			}
			else //num == -1
			{
				for (int i = 0; i <= 100; ++i)
				{
					if (s[i].empty())
						continue;
					cout << *s[i].begin() << "\n";
					break;
				}
			}
		}
		else //solved
		{
			int num;
			cin >> num;
			s[level[num]].erase(num);
		}
	}
}



//난이도가 100개 밖에 안되니까  for문 돌면서 다 찾기
//set의 사용법