#include "Serializer.hpp"
#include <iostream>
#include<fstream>

Serializer::Serializer()
{
    std::cout<< "Serializer constrcutor called" << std::endl;
}
Serializer::~Serializer()
{
    std::cout << "Serializer deconstrcutor called" <<std::endl;
}
uintptr_t Serializer::serialize(Data *ptr)
{
   ofstream MyWriteFile("data.bin");

    if(MyWriteFile.is_open())
        std::cerr <<"Error opening file" << std::endl;

    char* ch = reinterpret_cast<char*>(ptr);

     MyFile.close();

     return ch;
}

Data	*Serializer::deserialize(uintptr_t raw){

    Data *a;
    ifstream MyReadFile("data.bin");
    if(MyReadFile.isopen())
        std::cerr <<"Error opening file" << std::endl;
    MyReadFile.read(0, sizeof(&a));
    a=  reinterpret_cast<Data*>(raw);
    return a;
}
