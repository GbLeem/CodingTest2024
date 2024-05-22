#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//66% (100, 25)
//int solution(vector<int>& A)
//{	
//	int maxProfit = 0;
//	for (int i = 0; i < A.size(); ++i)
//	{
//		int tempVal = A[i];
//		vector<int> temp;
//				
//		for (int j = i; j < A.size(); ++j)
//		{
//			if (A[j] > tempVal)
//			{
//				temp.push_back(A[j]);
//			}
//		}
//		int tempMaxProfit = 0;
//		if (!temp.empty())
//		{
//			tempMaxProfit = *max_element(temp.begin(), temp.end()) - tempVal;
//			if (tempMaxProfit > maxProfit)
//				maxProfit = tempMaxProfit;
//		}
//	}
//
//	return maxProfit;
//}

//100%
int solution(vector<int>& A)
{
	if (A.size() == 0)
		return 0;
	int minVal = A[0];
	int maxProfit = 0;
	int tempProfit = 0;

	for (int i = 1; i < A.size(); ++i)
	{
		tempProfit = A[i] - minVal;
		if (A[i] < minVal)
			minVal = A[i];
		maxProfit = max(maxProfit, tempProfit);		
	}
	if (maxProfit < 0)
		return 0;
	return maxProfit;
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> A = { 23171, 21011, 21123, 21366, 21013, 21367 }; //n개 
	cout << solution(A);
}