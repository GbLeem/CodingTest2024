//백트래킹
//현재 상태에서 가능한 모든 후보군을 따라 들어가며 탐색하는 알고리즘

//상태가 중요함!


//STL next_permutation
#include <iostream>
#include <algorithm>
using namespace std;

int a[3] = { 1,2,3 };
int b[4] = { 0,0,1,1 }; //4개 중 2개 뽑기

int main()
{
	//순열
	do
	{
		for (int i = 0; i < 3; ++i)
			cout << a[i];
		cout << "\n";
	} while (next_permutation(a, a + 3)); //다음 순열 없으면 false 반환함


	//조합
	do
	{
		for (int i = 0; i < 4; ++i)
		{
			if (b[i] == 0)
				cout << i + 1 << " ";
		}
		cout << "\n";
	} while (next_permutation(b, b + 4));
}
