#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int board[1005];
int d[1005];
vector<int> ans[1005];
vector<int> answer;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> board[i];
		d[i] = 1;
	}

	//d[1] = 1;
	int maxIdx;
	for (int i = 1; i <= n; ++i)
	{
		ans[i].push_back(board[i]);
		for (int j = 1; j <= i; ++j)
		{
			if (board[i] > board[j])
			{
				if (d[i] < d[j] + 1)
				{
					ans[i].clear();
					ans[i] = ans[j];
					ans[i].push_back(board[i]);

					d[i] = d[j] + 1;					
				}				
			}
		}

		if (answer.size() < ans[i].size())
			answer = ans[i];			
	}


	cout << answer.size() << "\n";
	for (auto a : answer)
		cout << a << " ";
}