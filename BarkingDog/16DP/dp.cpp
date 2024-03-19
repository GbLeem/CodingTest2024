#include <iostream>
using namespace std;

//중간 결과를 저장하기!!
int fibo(int n) //O(N)
{
	int f[20];
	f[0] = f[1] = 1;
	for (int i = 2; i <= n; ++i)
		f[i] = f[i - 1] + f[i - 2];
	return f[n];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cout << fibo(7); //21
}


//DP
//1. 테이블 정의하기
//2. 점화식 찾기
//3. 초기값 정하기
