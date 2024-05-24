#include<array>
#include<iostream>

class Animal
{
public:
	virtual void speak()
	{
		std::cout << "Animal" << std::endl;
	}
private:
	double height; //8byte
};

class Cat : public Animal
{
public:
	void speak() override
	{
		std::cout << "Cat" << std::endl;
	}
private:
	double weight; //8+8 byte
};

int main()
{
	std::cout << sizeof(Animal) << std::endl; //16 byte
	std::cout << sizeof(Cat) << std::endl; //24 byte

	Animal* polyAnimal = new Cat();
	polyAnimal->speak(); //Cat 출력
	delete polyAnimal;

	return 0;
}