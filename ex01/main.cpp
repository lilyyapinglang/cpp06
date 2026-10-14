#include "Data.hpp"
#include "Serializer.hpp"
#include<iostream>

int	main(void)
{
	Data *a = new Data("mimi",5);
	uintptr_t ptr = Serializer::serialize(a);

	Data *b = Serializer::deserialize(ptr);
    if(a->getAge()==b->getAge() && a->getName() == b-> getName())
        std::cout <<"data is the same"<< std::endl;
    else{
        std::cout << a->getAge()<<std::endl;
        std::cout << b->getAge() <<std::endl;
        std::cout << a->getName() <<std::endl;
        std::cout <<  b-> getName()<<std::endl;
    }
}