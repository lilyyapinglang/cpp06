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
	default:
		return NULL;
	}	
}

/*
It prints the actual type of the object pointed to by p: "A", "B", or "C".
dynamic_cast safely converts a base class pointer to a derived class pointer at runtime. 
If the cast succeeds, the pointer is valid; if it fails, it returns nullptr.
*/
void	identify(Base *p){
	// try to cast to A
	if(A *a_ptr= dynamic_cast<A *>(p))
		std::cout<<"A " << a_ptr<< std::endl;
	// try to cast to B
	else if (B *b_ptr= dynamic_cast<B *>(p))
		std::cout<<"B " <<b_ptr<<std::endl;
	// try to cast to C
	else if (C *c_ptr= dynamic_cast<C *>(p))
		std::cout<<"C " <<c_ptr<<std::endl;
	else 
		std::cout <<"Unknown type." << std::endl;
}

/*
It prints the actual type of the object referenced by p: "A", "B", or "C". Using a pointer
inside this function is forbidden.
*/
void	identify(Base &p){
	// p is an reference to a base type object 
	Base *ptr = &p;
	identify(ptr);
}
