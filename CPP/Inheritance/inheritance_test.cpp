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
	void Bar() //Overriding			=>		overloading : �Լ� �̸� ������ �Ķ���� �ٸ���
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


//�����Լ��� �ƴҶ��� �ڷ����� ����Ѵ�.
//"�����Լ���" �� �ڷ����� �ƴ϶� ������ ����Ű�� ��ü�� �����ؼ� ȣ�� ��� ����!!!

//�⺻������ C++�� �������ε� (���̵��� ���� - �ڷ��� ���� ����)
//�����Լ��� ���� ���ε� -> �����Լ� ���̺��� ����µ�, �̴� Ŭ���� ���� �ϳ�����

//�Ʒ� ���ÿ��� Foo�� �����Լ���
int main()
{
	Derived* d = new Derived(); //���⼭ base ���������� �������
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
	//�����Ҷ��� base ���� ����, �Ҹ��Ҷ��� derived ���� �Ҹ�
}