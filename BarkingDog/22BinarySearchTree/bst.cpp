//이진 트리 : 각 노드의 자식이 2개 이하인 트리

//이진 검색 트리 : 왼쪽 서브트리의 모든 값은 부모의 값보다 작고 오른쪽 서브트리의 모든 값은 부모의 값보다 큰 트리

//insert, erase, find, update -> O(lgN) 

//erase할때 - 자식이 두개인 것
//-> 지우려고 하는것 오른쪽 자식을 찾은 후
// 계속 왼쪽자식만 찾아서 마지막 자식과 바꾸기


//이진 검색 트리가 자가 균형 트리 아니면 성능 안좋음

//자가 균형 트리 예시
//AVL 트리
//Red Black 트리 (STL 구현 방식) - 성능 더 좋음


//이진 검색 트리 STL
// set
// multiset  : 중복 허용되는 set -> erase 주의
// - find가 중복되는 것 중 아무거나 줘버림
// - 제일 먼저 등장하는 수 찾으려면 lower_bound 로 찾기
// map

//cf) hash STL
//-> unordered_set, unordered_multiset, unordered_map


#include <set>
#include <iostream>
using namespace std;

int main()
{
	set<int> s;

	s.insert(-10);
	s.insert(100);
	s.insert(15);
	//-10 100 15

	s.insert(-10);
	//-10 100 15

	cout<<s.erase(100)<<"\n";
	cout << s.erase(20) << "\n";
	if (s.find(15) != s.end())
		cout << "15 in set\n";
	else
		cout << "15 not in set\n";

	cout << s.size() << "\n";
	cout << s.count(50) << "\n"; // 0
	for (auto e : s)
		cout << e << " ";
	cout << "\n";
	s.insert(-40);

	auto it1 = s.begin(); //-40(it1) -10 15
	it1++;				  //-40 -10(it1) 15
	auto it2 = prev(it1); //-40(it2) -10 15
	it2 = next(it1);      //-40 -10 15(it2)
	advance(it2, -2);     //-40(it2) -10 15

	auto it3 = s.lower_bound(-20); //-40 -10(it3) 15 -> 특정 원소가 삽입되어도 오름차순 순서가 유지되는 가장 왼쪽 위치
	auto it4 = s.find(15); ////-40 -10 15(it4)
}