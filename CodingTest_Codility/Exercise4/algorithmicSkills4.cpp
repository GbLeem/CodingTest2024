//A = {-1, 6, 3, 4, 7, 4};
//invA = {4, 7, 4, 3, 6, -1};
//(0,1) -> A[1] < A[0] -> 6 < -1
//(0,2) -> 3 < -1
//(0,3) -> 4 < -1
//(0,4) -> 7 < -1
//(0,5) -> 4 < -1

//(1,2) -> 3 < 6
//(1,3) -> 4 < 6
//(1,4) -> 7 < 6
//(1,5) -> 4 < 6

//(2,3) -> 4 < 3
//(2,4) -> 7 < 3
//(2,5) -> 4 < 3

//(3,4) -> 7 < 4
//(3,5) -> 4 < 4

//(4,5) -> 4 < 7

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//int solution(vector<int>& A)
//{
//	
//}
//N은 100000

bool isused[100002];
int arr[100002];
int ans = 0;
//길이가 m 
//1~n까지 자연수

void func(int k, vector<int>& A)
{
	if (k == 2)
	{
		if (A[arr[1] - 1] < A[arr[0] - 1])
		{
			ans++;
		}
		return;
	}
	int st = 1;
	if (k != 0)
		st = arr[k - 1] + 1;

	for (int i = st; i <= A.size(); ++i)
	{
		if (!isused[i])
		{
			arr[k] = i;
			isused[i] = 1;
			func(k + 1, A);
			isused[i] = 0;
		}
	}
}
int solution(vector<int>& A)
{
	func(0, A);
	return ans;
}

int main()
{
	vector<int> A = { -1, 6, 3, 4, 7, 4 };
	cout << solution(A);
}