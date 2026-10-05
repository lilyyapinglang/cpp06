#include "./ScalarConverter.hpp"
#include <string>
#include <iostream>
/*
Write a class ScalarConverter that will contain only one static method "convert"
that will take as a parameter a string representation of a C++ literal in its most common
form and output its value in the following series of scalar types:
• char
• int
• float
• double
*/

/*
You have to first detect the type of the literal passed as a parameter,
convert it from string to its actual type,
then convert it explicitly to the three other data types.
Lastly, display the results as shown below.
*/

/*
./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0
./convert nan
char: impossible
int: impossible
float: nanf
double: nan
./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0
*/
void ScalarConverter::convert(std::string str)
{
    int actual_type = detect_type(str);
    actual_type a = convert2actualtype(str, actual_type);
    std::cout << "char : " << static_cast<char>(a) << std::endl;
    std::cout << "int : " << static_cast<int>(a) << std::endl;
    std::cout << "float : " << static_cast<float>(a) << std::end;
    std::cout << "douvle : " << static_cast<double>(a) << std::endl;
}
// parsing
int detect_type(std::string str)
{
}
