#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include<iostream>

int	main(void)
{
	Base *a =new A();
    Base *b = new B();
    Base *c= new C();
    
    identify(a);
    identify(b);
    identify(c);

    A a_ref;
    B b_ref;
    C c_ref;

    identify(a_ref);
    identify(b_ref);
    identify(c_ref);

    delete a;
    delete b;
    delete c;

    Base *x=generate();
    identify(x);

    Base *y=generate();
    identify(y);

    Base *z=generate();
    identify(z);

    for(int i=0; i<10;i++)
    {
        Base *x=generate();
        identify(x);
    }
}