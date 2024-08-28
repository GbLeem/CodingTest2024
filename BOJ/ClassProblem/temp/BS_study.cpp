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

	cout << s.erase(100) << "\n";
	cout << s.erase(20) << "\n";
	if (s.find(15) != s.end())
		cout << "15 in set\n";
	else
		cout << "15 not in set\n";

	cout << s.size() << "\n";
	cout << s.count(50) << "\n"; // 0
	cout << s.count(100) << "\n";
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
	cout << *s.lower_bound(-20) << "\n"; //-10 -> -20 보다 크거나 같은 가장 처음의 숫자
	s.insert(-20);
	cout << *s.lower_bound(-20) << "\n"; //-20

	auto it4 = s.find(15); ////-40 -10 15(it4)


}