//자릿수를 하나씩 확인해서 sorting
//D자릿수, 갯수 K 일때
//시간 복잡도 O(DN)

#include <iostream>
#include <vector>
using namespace std;

int n = 15;//원소의 수
int arr[1000001] = {}; //원소들의 목록
int d = 3; //자릿수 최댓값
int p10[3]; //10의 지수 저장

int digitNum(int x, int a)
{
	return (x / p10[a]) % 10; //x에서 10^a 자리를 추출하는 함수
}

vector<int> l[10];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	p10[0] = 1;
	//정수의 거듭제곱을 구하는 코드!
	for (int i = 1; i < d; ++i)
		p10[i] = p10[i - 1] * 10;

	for (int i = 0; i < d; ++i)
	{
		for (int j = 0; j < 10; ++j)
			l[j].clear();
		for (int j = 0; j < n; ++j)
			l[digitNum(arr[j], i)].push_back(arr[j]);
		int aidx = 0;
		for (int j = 0; j < 10; ++j)
			for (auto x : l[j])
				arr[aidx++] = x;
	}
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
}

//comparison sort
//버블, 머지, 퀵 소트

//non-comparison sort
//카운팅 라딕스 소트