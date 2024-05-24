//함수 오버라이딩 & 포인터 형

#include <iostream>

using namespace std;

class First
{
public:
    void MyFunc()
    {
        cout << "First::MyFunc()" << endl;
    }
    void Func1()
    {
        cout << "First::Func1()" << endl;
    }
};

class Second : public First
{
public:
    void MyFunc() // 함수 오버라이딩 (First 클래스에 MyFunc()가 있음)
    {
        cout << "Second::MyFunc()" << endl;
    }
    void Func2()
    {
        cout << "Second::Func2()" << endl;
    }
};

class Third : public Second
{
public:
    void MyFunc() // 함수 오버라이딩 (Second 클래스에 MyFunc()가 있음)
    {
        cout << "Third::MyFunc()" << endl;
    }
    void Func3()
    {
        cout << "Third::Func3()" << endl;
    }
};

int main()
{
    Third* third = new Third;
    Second* second = reinterpret_cast<Second*>(third); // Ok, third를 만들때 이미 Second, First 객체를 묵시적으로 만들었음
    First* first = second;  // Ok, second를 만들때 이미 First 객체를 묵시적으로 만들었음     
    
    // 하지만 맴버 함수를 접근할 때에는 해당 클래스의 함수만 접근 가능
    first->MyFunc();
    second->MyFunc();
    third->MyFunc();

    cout << endl;

    first->Func1(); // Ok


    cout << endl;

    second->Func1(); // Ok, First 클래스를 상속받았기에 Func1()에 접근 가능
    second->Func2(); // Ok, 자기 자신의 멤버함수

    cout << endl;

    third->Func1(); // Ok, Third 클래스는 Second 클래스를 통하여 결국 First 클래스를 상속 받았음 
    third->Func2(); // Ok, Third 클래스는 Second 클래스를 상속 받았음
    third->Func3(); // Ok, 자기 자신의 멤버함수

    system("pause");    // VC++ 에서만
    return 0;
}