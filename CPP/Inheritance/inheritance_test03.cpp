#include <iostream>

using namespace std;

class Person
{
public:
    Person()
    {
        cout << "make P\n";
    }
    virtual ~Person()
    {
        cout << "P destroy\n";
    }
    void Sleep()
    {
        cout << "Sleep" << endl;
    }
};

class Student : public Person
{
public:
    Student()
    {
        cout << "Make S\n";
    }
    virtual ~Student()
    {
        cout << "S destroy\n";
    }
    virtual void Study()
    {
        cout << "Study" << endl;
    }
};

class PartTimeStudent : public Student
{
public:  
    PartTimeStudent()
    {
        cout << "Make PTS\n";
    }
    ~PartTimeStudent()
    {
        cout << "PTS destroy\n";
    }
    virtual void Study()
    {
        cout << "little study T_T \n";
    }
    virtual void Work()
    {
        cout << "Work" << endl;
    }
};

int main()
{
    Person* Kim = new Student;
    cout << "\n";
    Person* Park = new PartTimeStudent;
    cout << "\n";
    Student* Lee = new PartTimeStudent;
       
    cout << "\n";
    Kim->Sleep(); // Student 'IS A' Person.
    Park->Sleep(); // PartTimeStudent 'IS A' Person.    
    Lee->Study(); // PartTimeStudent 'IS A' Student
    Lee->Sleep();

    cout << "\n";
    delete Kim; 
    cout << "\n";
    delete Park;
    cout << "\n";
    delete Lee;

    system("pause");  // VC++ ¿¡¼­¸¸
    return 0;
}