#include "Serializer.hpp"
#include <iostream>
#include <fstream>

Serializer::Serializer()
{
    std::cout<< "Serializer constrcutor called" << std::endl;
}
Serializer::~Serializer()
{
    std::cout << "Serializer deconstrcutor called" <<std::endl;
}

// uintptr_t is an unsigned integer type that is guaranteed to be large enough to hold a pointer.
uintptr_t Serializer::serialize(Data *ptr)
{
    //open for binary writing
//    std::ofstream MyWriteFile("data.bin", std::ios::binary);

//     if(!MyWriteFile.is_open())
//     {
//         std::cerr <<"Error opening file" << std::endl;
//         return ;
//     }

//     char* ch = reinterpret_cast<char *>(ptr);
//     MyWriteFile.write(ch, sizeof(Data));
//      MyWriteFile.close();
    uintptr_t p = reinterpret_cast<uintptr_t>(ptr);
  
    return p;
}

Data	*Serializer::deserialize(uintptr_t raw){

    Data *a;
    // std::ifstream MyReadFile("data.bin",std::ios::binary);
    // if(!MyReadFile.is_open())
    // {
    //     std::cerr <<"Error opening file" << std::endl;
    //     return ;
    // }
    // char* ch = reinterpret_cast<char *>(raw);
    // MyReadFile.read(ch, sizeof(&a));
    
    // MyReadFile.close();
    a=  reinterpret_cast<Data*>(raw);
   
    return a;
}
