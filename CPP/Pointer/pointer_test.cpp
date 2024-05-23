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

class Base
{
public:
	virtual void Foo()
	{
		printf("Base::Foo\n");
	}
	void Bar()
	{
		printf("Base::Bar\n");
	}
};

class Derived : public Base
{
public:
	virtual void Foo()
	{
		printf("Derived::Foo\n");
	}
	void Bar()
	{
		printf("Derived::Bar\n");
	}
};

int main()
{
	//=============포인터===============
	int p = 1;
	int q = 6;

	foo(&p, &q);
	cout << p << " " << q << "\n"; //100 5

	refSwap(p, q);
	cout << p << " " << q << "\n"; //5 100

	cout << "\n\n";

	//==============가상함수==================
	//가상 함수는 파생 클래스에서 다시 정의할 멤버 함수

	Derived* d = new Derived();
	Base* b = reinterpret_cast<Base*>(d);

	d->Foo(); //derived foo
	d->Bar(); //derived bar
	b->Foo(); //derived foo
	b->Bar(); //base bar


	return 0;
}