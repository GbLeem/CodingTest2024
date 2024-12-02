#include <iostream>

using namespace std;

class Person
{
public:
    void Sleep()
    {
        cout << "Sleep" << endl;
    }
};

class Student : public Person
{
public:
    void Study()
    {
        cout << "Study" << endl;
    }
};

class PartTimeStudent : public Student
{
public:
    void Work()
    {
        cout << "Work" << endl;
    }
};

int main()
{
    Person* Kim = new Student;
    Person* Park = new PartTimeStudent;
    Student* Lee = new PartTimeStudent;

    Kim->Sleep(); // Student 'IS A' Person.
    Park->Sleep(); // PartTimeStudent 'IS A' Person.
    Lee->Study(); // PartTimeStudent 'IS A' Student
    Lee->Sleep();

    delete Kim;
    delete Park;
    delete Lee;

    system("pause");  // VC++ ¿¡¼­¸¸
    return 0;
}