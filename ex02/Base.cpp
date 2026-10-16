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
It randomly instantiates A, B, or C and returns the instance as a Base pointer. Feel free
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
	if(!p)
		return;
	// try to cast to A
	if(dynamic_cast<A *>(p))
		std::cout<<"Base pointer to A" << std::endl;
	// try to cast to B
	else if (dynamic_cast<B *>(p))
		std::cout<<"Base pointer to B"<<std::endl;
	// try to cast to C
	else if (dynamic_cast<C *>(p))
		std::cout<<"Base poniter to C"<<std::endl;
	else 
		std::cout <<"Base pointer to Unknown type." << std::endl;
}

/*
It prints the actual type of the object referenced by p: "A", "B", or "C". Using a pointer
inside this function is forbidden.

1. dynamic_cast but check for existence 
2. typeid
3. get the pointer from reference and use pointer to identify 
*/
void	identify(Base &p){
	// p is an reference to a base type object 
	// try to cast to A
	try
	{	dynamic_cast<A&>(p);
		std::cout<<"Base Reference to A"<< std::endl;
		return;
	}
	catch (const std::exception &e)
	{
		std::cerr <<e.what() << " Ref Cast to A failed" << std::endl;
	}
	try
	{	
		dynamic_cast<B&>(p);
		std::cout<<"Base reference to B"<< std::endl;
		return;
	}
	catch (const std::exception &e)
	{
		std::cerr <<e.what() << " Ref Cast to B failed" << std::endl;
	}

	try
	{	
		dynamic_cast<C&>(p);
		std::cout<<"Base reference to C"<< std::endl;
		return;
	}
	catch (const std::exception &e)
	{
		std::cerr <<e.what() << " Ref Cast to C failed" << std::endl;
	}
	
}
