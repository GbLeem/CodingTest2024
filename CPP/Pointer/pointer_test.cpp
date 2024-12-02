#include <iostream>
using namespace std;

void foo(int* p_a, int* p_b)
{
	cout <<"before: "<< p_a << " " << p_b << "\n";
	cout << "before: " << *p_a << " " << *p_b << "\n"; //1 6

	int* temp_p = p_a;
	p_a = p_b;
	*p_a = 5;
	cout << "after: " << p_a << " " << p_b << "\n";
	cout << "after: " << *p_a << " " << *p_b << "\n"; //5 5

	*temp_p = 100;
}

void refSwap(int& p_a, int& p_b)
{
	int temp = p_a;
	p_a = p_b;
	p_b = temp;
}

int main()
{	
	int p = 1;
	int q = 6;

	foo(&p, &q);
	cout << p << " " << q << "\n"; //100 5

	refSwap(p, q);
	cout << p << " " << q << "\n"; //5 100

	cout << "\n\n";


	return 0;
}