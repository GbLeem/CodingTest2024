//n-1 개의 원판을 기둥 1에서 기둥 2로 옮긴다.
//n 번의 원판을 기둥 1에서 기둥 3로 옮긴다.
//n-1개의 원판을 기둥 2에서 기둥 3로 옮긴다.
//--> 원판이 n-1개일 때 옮길 수 있으면 원판이 n개일 때에도 옮길 수 있다.

#include <iostream>
#include <vector>
using namespace std;

//원판 n개를 기둥 a에서 기둥 b으로 옮기는 방법을 출력하는 함수
void func(int a, int b, int n) 
{
	//base condition
	if (n == 1)
	{
		cout << a << " " << b << "\n";
		return;
	}
	//n-1개의 원판을 기둥 a에서 기둥 6-a-b로 옮긴다.
	func(a, 6 - a - b, n - 1);
	//n번 원판을 기둥 a에서 기둥 b로 옮긴다.
	cout << a << " " << b << "\n";
	//n-1개의 원판을 기둥 6-a-b 에서 기둥 b로 옮긴다.
	func(6 - a - b, b, n - 1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	cout << 2 * N + 1 << endl;
	func(1, 3, N);
}