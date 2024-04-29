#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int> s;

	s.insert(-10);
	s.insert(100);
	s.insert(20);
	s.insert(300);

	for (auto si : s)
		cout << si << " ";
	cout << "\n";

	int ans = 0;	

	auto it = s.lower_bound(350);
	if (it == s.end())
		cout << "can't find\n";
	else
		cout << *it << "\n";

}