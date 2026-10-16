#include "Data.hpp"
#include "iostream"

Data::Data(std::string name, int age):name(name), age(age)
{
	std::cout << "Data constructor called" << std::endl;
}
Data::Data(Data &other) :name(other.name), age(other.age){
	std::cout << "Data copy constructor called" << std::endl;
}

Data &Data::operator=(Data &other)
{
	std::cout << "Data copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->age = other.age;
		this->age = other.age;
	}
	return (*this);
}

Data::~Data()
{
	std::cout << "Data destructor called" << std::endl;
}

int Data::getAge() const
{
	return this->age;
}

std::string Data::getName() const{
	return this->name;
}