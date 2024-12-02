#include <iostream>
using namespace std;

class B
{
public:
	B() { cout << "constructor\n"; }
	~B() { cout << "destructor\n"; }
	B(const B& b) { cout << "copy constructor\n"; }
	B(B&& b) noexcept { cout << "move constructor\n"; }
};


B Func()
{
	B b; //기본 생성자 call
	return b;
}

class T
{
public:
	T() { cout << "constructor\n"; a = 4; }
	~T() { cout << "destructor\n"; a = 2; }
	T(const T& t) { cout << "copy constructor\n"; }
	T& operator=(const T& t) { cout << "대입 연산자\n"; }
	T(T&& t)noexcept { cout << "move constructor\n"; a = t.a; }
	T& operator=(T&& t) noexcept { cout << "이동 대입 연산자\b"; }

	int a;
};

T Func4(T t)
{
	T d = t;
	return d;
}

void Func3(T t)
{
	Func4(move(t));
}

void Func2(T t)
{
	Func3(t);
}

T Func1()
{
	T t;
	return t;
}


int main()
{
	B b = Func(); // move
	
	cout << "\n\n";

	Func1();
	Func2(Func1());

	return 0;
}