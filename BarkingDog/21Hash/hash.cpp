//insert, erase, find ..
//모든 연산이 O(1)

//해시 함수
//임의 길이의 데이터를 고정 길이 데이터로 바꿔주는 함수

//STL
//unordered_set 
//unordered_multiset
//unordered_map
//unordered_multimap

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

//0000 0000 0000 3333
//9999 9999 9999 3333
//-> 맨 뒤의 네자리 숫자를 기준으로 저장

//<충돌 방지>
//1. chaining
// STL이 쓰는 방식
// 연결 리스트로 만들기
// 충돌이 빈번할수록 성능저하

//2. open addressing
//insert: 이미 사용하는 공간이면 다음 빈 공간을 찾아서 넣기
//find 맨 뒤의 자리수를 통해 O(1) 로 찾고 전체 주소가 다르면 하나씩 뒤로 가면서 같은 것 찾기
//그런데 빈칸 나올때까지 못찾으면 없는 것
//erase: 그냥 칸을 지워버리면 안되니까(빈칸있을 때 find를 멈추니까) Dummy 값을 넣어주기

//뒤로 넘기는 방식
//*Linear Probing : 충돌시 한칸씩 이동 -> cache hit 높으나 clustering 생겨 성능 저하 생길 수 있다.
//*Quadratic Probing : 충돌 발생 시 오른쪽으로 1, 3, 5... 칸씩 이동 -> cache hit 낫밷, clustering 회피 가능
//그러나 해시 값이 같을 경우 clustering 여전함
//*double hashing : 충돌 발생 시 이동할 칸의 수를 새로운 해시 함수로 계산하기