#include "Data.hpp"
#include "Serializer.hpp"
#include<iostream>

int	main(void)
{
	Data *a = new Data(5);
	uintptr_t ptr = Serializer::serialize(a);

	Data *b = Serializer::deserialize(ptr);
    if(a->getAge()==b->getAge())
        std::cout <<"data is the same"<< std::endl;
    }