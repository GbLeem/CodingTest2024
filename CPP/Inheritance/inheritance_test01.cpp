//�Լ� �������̵� & ������ ��

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
    void MyFunc() // �Լ� �������̵� (First Ŭ������ MyFunc()�� ����)
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
    void MyFunc() // �Լ� �������̵� (Second Ŭ������ MyFunc()�� ����)
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
    Second* second = reinterpret_cast<Second*>(third); // Ok, third�� ���鶧 �̹� Second, First ��ü�� ���������� �������
    First* first = second;  // Ok, second�� ���鶧 �̹� First ��ü�� ���������� �������     

    // ������ �ɹ� �Լ��� ������ ������ �ش� Ŭ������ �Լ��� ���� ����
    first->MyFunc();
    second->MyFunc();
    third->MyFunc();

    cout << endl;

    first->Func1(); // Ok


    cout << endl;

    second->Func1(); // Ok, First Ŭ������ ��ӹ޾ұ⿡ Func1()�� ���� ����
    second->Func2(); // Ok, �ڱ� �ڽ��� ����Լ�

    cout << endl;

    third->Func1(); // Ok, Third Ŭ������ Second Ŭ������ ���Ͽ� �ᱹ First Ŭ������ ��� �޾��� 
    third->Func2(); // Ok, Third Ŭ������ Second Ŭ������ ��� �޾���
    third->Func3(); // Ok, �ڱ� �ڽ��� ����Լ�

    system("pause");    // VC++ ������
    return 0;
}