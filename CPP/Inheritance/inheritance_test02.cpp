#include <iostream>

using namespace std;

class First
{
public:
    virtual void MyFunc() // ���� �Լ�
    {
        cout << "First::MyFunc()" << endl;
    }
};

class Second : public First
{
public:
    virtual void MyFunc() override// ���� �Լ�
    {
        cout << "Second::MyFunc()" << endl;
    }
};

class Third : public Second
{
public:
    virtual void MyFunc() override// ���� �Լ�
    {
        cout << "Third::MyFunc()" << endl;
    }
};

int main()
{
    Third* third = new Third;
    Second* second = third; // Ok, third�� ���鶧 �̹� Second, First ��ü�� ���������� �������
    First* first = second;  // Ok, second�� ���鶧 �̹� First ��ü�� ���������� �������

    cout << "address of third (��, thrid ���� ����  = �ּ�) " << third << endl;
    cout << "address of second(��, second ���� ���� = �ּ�) " << second << endl;
    cout << "address of first (��, first ���� ����  = �ּ�) " << first << endl;

    // �����Լ��� ����� �ɹ� �Լ��� ������ ������ ���� ��ü�� �ɹ� �Լ� ȣ��
    // �����Լ��� ����� third = second = first �� ��Ȳ�̹Ƿ� third�� �ɹ� �Լ� ȣ��
    first->MyFunc();
    second->MyFunc();
    third->MyFunc();

    system("pause");   // VC++ ������
    return 0;
}