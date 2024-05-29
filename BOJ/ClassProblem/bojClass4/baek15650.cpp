#include <iostream>
using namespace std;

int n, m;
int arr[10];
int isused[10];

void func(int cur)
{
	if (cur == m)
	{
		for (int i = 0; i < m; ++i)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	
	//오름 차순 정렬
	int index = 1;
	if (cur != 0)
		index = arr[cur - 1] + 1; //cur != 0인 경우

	for (int i = index; i <= n; ++i) //index 부터 n까지의 수
	{
		if (!isused[i]) //i가 아직 사용안된경우
		{
			arr[cur] = i; //cur번째 수를 i로
			isused[i] = 1; //i를 사용했다고 표시
			func(cur + 1); //재귀
			isused[i] = 0; //cur 번째 수를 i로 정한 후 모든 경우 체크했으니 i를 이제 사용되지 않았다고 명시
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	func(0);
}