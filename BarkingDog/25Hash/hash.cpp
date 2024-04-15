//insert, erase, find ..
//모든 연산이 O(1)

//해시 함수
//임의 길이의 데이터를 고정 길이 데이터로 바꿔주는 함수

//STL
//unordered_set 

#include <unordered_set>
#include <unordered_map>
#include <iostream>
using namespace std;
void unordered_set_example()
{
	unordered_set<int> s; //원소 중복x
	s.insert(-10);
	s.insert(100);
	s.insert(15);
	cout << s.erase(100) << "\n";
	for (auto i : s)
		cout << i << " ";

	unordered_multiset<int> ms; //원소 중복 o
	ms.insert(-10);
	ms.insert(100);
	ms.insert(15);
	ms.insert(-10);

	cout << ms.erase(-10); // 모두 지우기
	ms.erase(ms.find(-10)); // 하나만 지우기

	unordered_map<string, int> m;

	//unordered_multimap  잘안씀
}