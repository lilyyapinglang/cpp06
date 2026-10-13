#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

Base::~Base()
{
	std::cout << "Base destructor called" << std::endl;
}
/*
It randomly instantiates A, B,
	or C and returns the instance as a Base pointer. Feel free
to use anything you like for the random choice implementation.
*/
Base	*generate(void)
{
	int		randomNum;
	Base	*a;
	Base	*b;
	Base	*c;

	/// Generate a random number between 0 and 2
	randomNum = rand() % 3;
	switch (randomNum)
	{
	case 0:
		a = new A();
		return (a);
	case 1:
		b = new B();
		return (b);
	case 2:
		c = new C();
		return (c);
	}
}
/*
It prints the actual type of the object pointed to by p: "A", "B", or "C".
*/
void	identify(Base *p){
    
}
/*
It prints the actual type of the object referenced by p: "A", "B",
	or "C". Using a pointer
inside this function is forbidden.
*/
void	identify(Base &p);
