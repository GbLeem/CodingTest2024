#include <iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		cout << "make base\n";
	}
	virtual void Foo()
	{
		printf("Base::Foo\n");
	}
	void Bar()
	{
		printf("Base::Bar\n");
	}
	void onlybase() const
	{
		cout << "onlybase\n";
	}
	void  PrintValue() const
	{
		cout << protectValue << "\n";
	}
	virtual ~Base()
	{
		cout << "destroy base\n";
	}
protected:
	int protectValue = 0;
};

class Derived : public Base
{
public:
	Derived()
	{
		cout << "make Derived\n";
	}
	virtual void Foo()
	{
		printf("Derived::Foo\n");
	}
	void Bar() //Overriding			=>		overloading : 함수 이름 같은데 파라메터 다른것
	{
		printf("Derived::Bar\n");
	}
	void OnlyDerived()
	{
		cout << "only derived\n";
	}
	void ChangeValue()
	{
		protectValue = 100;
	}
	virtual ~Derived()
	{
		cout << "destroy derived\n";
	}
};


//가상함수가 아닐때는 자료형에 기반한다.
//"가상함수일" 때 자료형이 아니라 실제로 가리키는 객체를 참조해서 호출 대상 결정!!!

//기본적으로 C++는 정적바인딩 (무늬따라 간다 - 자료형 따라 간다)
//가상함수는 동적 바인딩 -> 가상함수 테이블이 생기는데, 이는 클래스 마다 하나생김

//아래 예시에서 Foo는 가상함수임
int main()
{
	Derived* d = new Derived(); //여기서 base 묵시적으로 만들어짐
	Base* b = reinterpret_cast<Base*>(d);
	Base* b2 = new Base();

	d->Foo(); //Derived::Foo
	d->Bar(); //Derived::Bar
	d->onlybase();
	d->OnlyDerived();
	cout << "\n";

	b->Foo(); //Derived::Foo	
	b->Bar(); //Base::Bar
	b->onlybase();
	cout << "\n";

	b2->Foo(); //Base::Foo
	b2->Bar(); //Base::Bar
	b2->onlybase();

	cout << "\n\n";
	d->PrintValue(); //0
	d->ChangeValue();
	d->PrintValue(); //100

	delete b;
	delete b2;
	//생성할때는 base 부터 생성, 소멸할때는 derived 부터 소멸
}