#include <iostream>
#include <string>
using namespace std;

class B
{
public:
	B() :name("null"){ cout << "constructor\n"; }
	~B() { cout << name << " destructor\n"; }
	B(const B& b) :name(b.name) { cout << "copy constructor\n"; }
	B(B&& b) :name(move(b.name)) { cout << "move constructor\n"; }

	string name;
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
	//B b = Func(); // move
	//
	//cout << "\n\n";

	//Func1();
	//Func2(Func1());

	//-----------------------------
	B b1; //constructor 
	B b2 = b1; //copy constructor
	B b3{ b1 };//copy constructor
	B b4{ move(b1) }; //move constructor
	// b4 --> null destructor
	// b3 --> null destructor
	// b2 --> null destructor
	// b1 -->  destructor (b4가 b1의 ownership 뺏어서 이전에 없어져버림)

	return 0;
}