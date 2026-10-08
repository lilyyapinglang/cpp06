#include "./ScalarConverter.hpp"
#include <string>
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <sstream>
#include <iomanip>
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

/*
Authorized: Any function to convert from a string to an int, a float, or a
double.
*/

// Examples of char literals : ’c’, ’a’, ...
// Examples of int literals: 0, -42, 42...
// Examples of float literals: 0.0f, -4.2f, 4.2f...
// Examples of double literals: 0.0, -4.2, 4.2...
enum types
{
    CHAR = 0,
    INT = 1,
    FLOAT = 2,
    DOUBLE = 3,
    UNKNOWN_TYPE = 4
};

types detect_type(std::string str)
{
    std::stringstream ss;
    ss << str;
    int i = 0;
    float f = 0.0f;
    double d = 0.0;
    char suffix;
    if (str.length() == 1 && !std::isdigit((str[0])))
        return CHAR;
    if (ss >> f && ss >> suffix && (suffix == 'f' || suffix == 'F') && ss >> std::ws && ss.eof())
        return FLOAT;
    if (ss >> d && ss.eof())
        return DOUBLE;
    if (ss >> i && ss.eof())
        return INT;

    ss.str("");
    ss.clear();
    ss << str;

    return UNKNOWN_TYPE;
}
/*
Except for char parameters, only the decimal notation will be used.
non-displayable characters shouldn’t be used as
inputs. If a conversion to char is not displayable, print an informative message.
*/
void display_char(std::string str)
{
    std::cout << "in display char " << std::endl;

    char c = str[0];
    if (c > 31 && c < 127)
        std::cout << "char: " << static_cast<char>(c) << std::endl;
    else
        std::cout << "char:  Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void display_int(std::string str)
{
    std::cout << "in display int " << std::endl;
    int i = std::atoi(str.c_str());
    float f = static_cast<float>(i);
    if (i > 31 && i < 127)
        std::cout
            << "char: " << static_cast<char>(i) << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << std::fixed << std::setprecision(1);

    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void display_float(std::string str)
{
    //  std::cout << "in display float " << std::endl;

    //-inff, +inff, nan
    float f = static_cast<float>(std::atof(str.c_str()));
    int i = static_cast<int>(f);
    std::cout << "char: " << "\'" << static_cast<char>(i) << "\'" << std::endl;
    std::cout << "int: " << i << std::endl;

    std::cout << "float: " << str << std::endl;
    std::cout << "double: " << str.substr(0, str.size() - 1) << std::endl;
}
void display_double(std::string str)
{
    std::cout << "in display double " << std::endl;

    //-inf +inf nan
    double d = std::atof(str.c_str());
    int i = static_cast<int>(d);
    std::cout << "char: " << static_cast<char>(i) << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << std::endl;
}
void ScalarConverter::convert(std::string str)
{
    types actual_type = detect_type(str);

    switch (actual_type)
    {
    case CHAR:
        display_char(str);
        break;
    case INT:
        display_int(str);
        break;
    case FLOAT:
        display_float(str);
        break;
    case DOUBLE:
        display_double(str);
        break;
    case UNKNOWN_TYPE:
        std::cout << "unknown type" << std::endl;
    }
}
