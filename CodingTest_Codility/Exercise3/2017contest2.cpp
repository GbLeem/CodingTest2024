#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int K, vector<int>& C, vector<int>& D)
{
	sort(C.begin(), C.end());
	sort(D.begin(), D.end());
	int cnt = 0;
	for (int i = 0; i < C.size(); ++i)
	{
		if (i != C.size() - 1 && C[i] == C[i + 1])// only clean
		{
			i += 1;
			cnt++;
		}
		else //clean and dirty
		{
			if (binary_search(D.begin(), D.end(), C[i])) // find C[i]
			{
				int idx = lower_bound(D.begin(), D.end(), C[i]) - D.begin(); //find C[i] index
				if (K >= 1)
				{
					K -= 1;
					D[idx] = 0;
					cnt++;
					//i += 1;
				}

			}
		}
	}

	//1 1 1 2
	//1 2 3 4 4

	//K = 3
	// 1 1 1 
	// 1 2 3 4 4 -> 0 2 2 4 4 


	if (K >= 2)
	{
		sort(D.begin(), D.end());

		for (int i = 0; i < D.size(); ++i)
		{
			if (i != D.size() - 1 && D[i] == D[i + 1])
			{
				if (D[i] != 0)
				{
					cnt++;
					K -= 2;
					i += 1;
				}
				if (K < 2)
					break;
			}
		}
	}
	return cnt;
}

int main()
{
	vector<int> C = { 1,2,1,1 };
	vector<int> D = { 1,4,3,2,4 };

	vector<int> C1 = { 1,1,1 };
	vector<int> D1 = { 1,2,3,4,4 };

	cout << solution(2, C, D) << "\n";
	cout << solution(3, C1, D1) << "\n";
}