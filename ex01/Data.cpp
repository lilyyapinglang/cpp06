#include "Data.hpp"
#include "iostream"

Data::Data(int age) : age(age)
{
	std::cout << "Data constructor called" << std::endl;
}
Data::Data(Data &other) : age(other.age)
{
	std::cout << "Data copy constructor called" << std::endl;
}

Data &Data::operator=(Data &other)
{
	if (this != &other)
	{
		this->age = other.age;
	}
	return (*this);
}

Data ::~Data()
{
	std::cout << "Data destructor called" << std::endl;
}

int Data::getAge() const{
    return this->age;
}