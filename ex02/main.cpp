#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include<iostream>

int	main(void)
{
    std::cout << "------------Test: identify from pointer----------- " << std::endl;

    std::cout << "------------identify from A pointer----------- " << std::endl;
	Base *a =new A(); 
    identify(a);
    delete a;
    std::cout << "------------identify from B pointer----------- " << std::endl;

    Base *b = new B();
    identify(b);
    delete b;   
    std::cout << "------------identify from C pointer----------- " << std::endl;

    Base *c= new C();
    identify(c);
    delete c;

    std::cout << "------------Test: identify from reference----------- " << std::endl;

    std::cout << "------------identify from A reference----------- " << std::endl;
    A a_ref;
    identify(a_ref);
    std::cout << "------------identify from B reference----------- " << std::endl;

    B b_ref;
    identify(b_ref);
    std::cout << "------------identify from C reference----------- " << std::endl;

    C c_ref;
    identify(c_ref);

  

    // Base *x=generate();
    // identify(x);

    // Base *y=generate();
    // identify(y);

    // Base *z=generate();
    // identify(z);

    std::cout << "------------Test: generate----------- " << std::endl;

    for(int i=0; i<10;i++)
    {
        std::cout<<"-----" <<i<<"------"<< std::endl;
        Base *x=generate();
        identify(x);
        delete x;
    }
}