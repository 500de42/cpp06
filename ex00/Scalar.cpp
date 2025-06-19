#include "Scalar.hpp"

void PrintInt(std::string nb)
{
    long num = atol(nb.c_str());
    if (!(num > -2147483648 && num < 2147483647))
        std::cout << "limit of int exceeded\n";
    else
        std::cout << "Int: " << num << std::endl;
}

void PrintChar(std::string nb)
{
    if (isprint(atoi(nb.c_str())))
    {
        char c = atoi(nb.c_str());
        std::cout << "Char: " << c;
    }
    else 
        std::cout << "Char not printable\n"; 
}

void PrintDouble(std::string nb)
{
    char *endptr;
    double d = std::strtod(nb.c_str(), &endptr);
    if (*endptr != '\0')
        std::cout << "Impossible conversion for double\n";
    else
        std::cout << "Double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void PrintFloat(std::string nb)
{
    char *endptr;
    float d = std::strtof(nb.c_str(), &endptr);
    if (*endptr != '\0')
        std::cout << "Impossible conversion for float\n";
    else
        std::cout << "Float: " << std::fixed << std::setprecision(1) << d << "f" << std::endl;
}

void PrintAllChar(std::string nb)
{
    PrintChar(nb);
    PrintInt(nb);
    PrintFloat(nb);
    PrintDouble(nb);
}

void PrintAllInt(std::string nb)
{
    PrintInt(nb);
    PrintFloat(nb);
    PrintDouble(nb);
    PrintChar(nb);
}

void PrintAllFloat(std::string nb)
{
    PrintFloat(nb);
    PrintDouble(nb);
    PrintChar(nb);
    PrintInt(nb);
}

void PrintAllDouble(std::string nb)
{    
    PrintDouble(nb);
    PrintChar(nb);
    PrintInt(nb);
    PrintFloat(nb);
}

void ScalarConverter::Convert(std::string nb)
{
    if (nb.empty())
        return ;
    if ((nb.length() == 1))
    {
        PrintAllChar(nb);
    }
    else if (!(nb[nb.length() - 1] == 'f' && nb.find('.') != std::string::npos))
    {
        PrintAllInt(nb);
    }
    else if ((nb[nb.length() - 1] == 'f' && nb.find('.') != std::string::npos)
        || (nb == "-inff" || nb == "+inff" || nb == "nanf"))
    {
        PrintAllFloat(nb);
    }
    else if (nb.find('.') != std::string::npos || (nb == "nan" || nb == "+inf" || nb == "-inf"))
    {
        PrintAllDouble(nb);
    }
}
