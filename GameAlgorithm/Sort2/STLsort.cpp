#include <algorithm>
#include <string>
using namespace std;

int a[5] = { 1,4,5,2,7 };

bool cmp(int a, int b)
{
	//우선순위가 같을때 처리를 먼저 해주는 식으로 구현하기

}

//bad -> 불필요한 복사 일어남
bool cmp(string a, string b)
{
	return a.back() < b.back();
}

//good
bool cmp(const string& a, const string& b)
{
	return a.back() < b.back();
}

int main()
{
	sort(a, a + 5); //최악의 경우에도 O(NlgN)을 보장한다.
	stable_sort(a, a + 5);
}

//pair 나 tuple 
//맨 앞의 원소부터 정렬한다.
//같으면 다음 원소 이용