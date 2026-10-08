#include "./ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <cfloat>
#include <limits>

enum types
{
    CHAR = 0,
    INT = 1,
    FLOAT = 2,
    DOUBLE = 3,
    UNKNOWN_TYPE = 4
};

static bool is_pseudo_literal(const std::string &str)
{
    return (str == "nan" || str == "nanf" ||
        str == "+inf" || str == "-inf" || str == "inf" ||
        str == "+inff" || str == "-inff" || str == "inff");
}

static bool is_int_literal(const std::string &str)
{
    if (str.empty())
        return false;
    std::size_t i = 0;
    if (str[i] == '+' || str[i] == '-')
        i++;
    if (i == str.size())
        return false;
    while (i < str.size())
    {
        if (!std::isdigit(static_cast<unsigned char>(str[i])))
            return false;
        i++;
    }
    return true;
}

static bool parse_full_double(const std::string &str, double &value)
{
    char *endptr = NULL;
    value = std::strtod(str.c_str(), &endptr);
    return (endptr != str.c_str() && *endptr == '\0');
}

static bool is_double_literal(const std::string &str)
{
    if (str.empty())
        return false;
    if (is_pseudo_literal(str))
        return true;
    if (str.find('.') == std::string::npos &&
        str.find('e') == std::string::npos &&
        str.find('E') == std::string::npos)
        return false;
    double value;
    return parse_full_double(str, value);
}

static bool is_float_literal(const std::string &str)
{
    if (str.size() < 2)
        return false;
    if (str[str.size() - 1] != 'f' && str[str.size() - 1] != 'F')
        return false;

    std::string base = str.substr(0, str.size() - 1);
    if (base == "nan" || base == "+inf" || base == "-inf" || base == "inf")
        return true;

    if (base.find('.') == std::string::npos &&
        base.find('e') == std::string::npos &&
        base.find('E') == std::string::npos)
        return false;

    double value;
    return parse_full_double(base, value);
}

static types detect_type(const std::string &str)
{
    if (str.size() == 1 && !std::isdigit(static_cast<unsigned char>(str[0])))
        return CHAR;
    if (is_int_literal(str))
        return INT;
    if (is_float_literal(str))
        return FLOAT;
    if (is_double_literal(str))
        return DOUBLE;
    return UNKNOWN_TYPE;
}

static bool is_nan(double value)
{
    return value != value;
}

static bool is_inf(double value)
{
    const double max = std::numeric_limits<double>::max();
    return (value > max || value < -max);
}

static void print_char(double value)
{
    if (is_nan(value) || is_inf(value) || value < 0.0 || value > 127.0 ||
        value != static_cast<double>(static_cast<int>(value)))
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }
    int int_value = static_cast<int>(value);
    char c = static_cast<char>(int_value);
    if (int_value >= 32 && int_value <= 126)
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

static void print_int(double value)
{
    if (is_nan(value) || is_inf(value) || value < static_cast<double>(INT_MIN) || value > static_cast<double>(INT_MAX))
    {
        std::cout << "int: impossible" << std::endl;
        return;
    }
    std::cout << "int: " << static_cast<int>(value) << std::endl;
}

static void print_float(double value)
{
    if (is_nan(value))
    {
        std::cout << "float: nanf" << std::endl;
        return;
    }
    if (is_inf(value))
    {
        if (value < 0)
            std::cout << "float: -inff" << std::endl;
        else
            std::cout << "float: inff" << std::endl;
        return;
    }
    std::cout << std::fixed << std::setprecision(1)
        << "float: " << static_cast<float>(value) << "f" << std::endl;
}

static void print_double(double value)
{
    if (is_nan(value))
    {
        std::cout << "double: nan" << std::endl;
        return;
    }
    if (is_inf(value))
    {
        if (value < 0)
            std::cout << "double: -inf" << std::endl;
        else
            std::cout << "double: inf" << std::endl;
        return;
    }
    std::cout << std::fixed << std::setprecision(1)
        << "double: " << value << std::endl;
}

static double to_double(const std::string &str, types type)
{
    if (type == CHAR)
        return static_cast<double>(static_cast<unsigned char>(str[0]));
    if (type == FLOAT)
        return std::strtod(str.substr(0, str.size() - 1).c_str(), NULL);
    return std::strtod(str.c_str(), NULL);
}

void ScalarConverter::convert(std::string str)
{
    types type = detect_type(str);
    if (type == UNKNOWN_TYPE)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    double value = to_double(str, type);
    print_char(value);
    print_int(value);
    print_float(value);
    print_double(value);
}
