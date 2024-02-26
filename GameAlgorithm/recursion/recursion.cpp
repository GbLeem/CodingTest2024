//재귀함수의 조건
// 1. base condition 존재
// 2. 모든 입력은 base condition으로 수렴해야 함

//재쉬함수의 특징
// 1. 재귀는 코드는 간결하지만, 메모리 시간은 늘어남 -> 비효율적일 수 있다.
// 2. 재귀함수가 자신을 부를 때 메모리 구조의 스택 영역에 누적된다.
#include <iostream>

using namespace std;

//n 부터 1까지 출력하는 함수
//<귀납적>
//f1(1)이 1을 출력
//f1(k) 가 k, k-1, k-2 , ... 1을 출력하면
//f1(k+1)은 k+1, k, k-1, k-2 , ... 1 을 출력한다.
void f1(int n)
{
	if (n == 0)
		return;
	cout << n << endl;
	
	f1(n - 1);
}

//합 출력
int sum(int n)
{
	if (n == 1)
		return 1;
	
	return n + sum(n - 1); 
}


//stack 메모리 제한 100MB로 늘림
void TestFunction(int a)
{
	if (a == 0)
		return;
	TestFunction(a - 1);
}

//===========연습문제=======

int func1(int a, int b, int m)
{
	int val = 1;
	while (b--)
		val *= a;
	return val & m;
}

long long func1_1(long long a, long long b, long long m)
{
	long long val = 1;
	while (b--)
		val = (val * a) % m;
	return val;
}

int main()
{
	f1(10);
	cout << sum(10) << endl;
	TestFunction(100000);
	cout << "done";
}