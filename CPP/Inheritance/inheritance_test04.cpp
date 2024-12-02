#include<array>
#include<iostream>

class Animal
{
public:
	virtual void speak()
	{
		std::cout << "Animal" << std::endl;
	}
	void Eat()
	{
		std::cout << "Animal : YamYam\n";
	}
	virtual ~Animal() = default;
};

class Cat : public Animal
{
public:
	void speak() override
	{
		std::cout << "Cat" << std::endl;
	}
	void Eat()
	{
		std::cout << "Cat : YamYam\n";
	}
};

class Dog :public Animal
{
	void speak() override
	{
		std::cout << "Dog" << std::endl;
	}
	void Eat()
	{
		std::cout << "Dog : YamYam\n";
	}
};

int main()
{
	std::array<Animal*, 5> animals;

	for (auto& animalPtr : animals)
	{
		int i = 0;
		std::cin >> i;
		if (i == 1)
			animalPtr = new Cat();
		else
			animalPtr = new Dog();
	}

	for (auto& animalPtr : animals)
	{
		animalPtr->speak(); //speak 는 가상함수니까 실제로 가리키는 것이 중요
		animalPtr->Eat();   //Eat은 가상 함수아니니까 자료형이 중요
		delete animalPtr;
	}

	return 0;
}