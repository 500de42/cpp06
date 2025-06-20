#include "Scalar.hpp"

int nuum(std::string nb)
{
    int point = 0;

    for(std::string::iterator i = nb.begin(); i < nb.end(); i++)
    {
        if ((!(*i >= '0' && *i <= '9')) && (nb[*i] > 31 && nb[*i] < 127))
        {
            if (nb[*i] == '.')
            {
                point++;
                continue;
            }
            else if (nb[*nb.begin()] == '-')
                continue;
            return 0;
        }
    }
    if (point > 1)
        return 0;
    return 1;
}

void PrintInt(std::string nb, int c)
{
    if (c == 1)
    {
        std::cout << (int)nb[0] << std::endl;
        return ;
    }
    long num = atol(nb.c_str());
    if (!(num > -2147483648 && num < 2147483647))
        std::cout << "limit of int exceeded\n";
    else if (!nuum(nb))
    {
        std::cout << nuum(nb) << "Impossible Convertion\n";
    }
    else
        std::cout << "Int: " << num << std::endl;
}

void PrintChar(std::string nb, int c)
{
    if ((atoi(nb.c_str()) < 127 && atoi(nb.c_str()) > 31) && (c == 1 && atoi(nb.c_str()) != 0))
    {
        std::cout << "Char: " << (char)atoi(nb.c_str()) << std::endl;
        return ;
    }
    if (nb[0] > 31 && nb[0] < 127 && !nb[1])
    {
        std::cout << "Char: " << (char)nb[0] << std::endl;
    }
    else
        std::cout << "Char not printable\n"; 
}

void PrintDouble(std::string nb, int c)
{
    if (c == 1)
    {
        std::cout << "Double: " << std::fixed << std::setprecision(1) << (double)nb[0] << std::endl;
        return ;
    }
    char *endptr;
    double d = std::strtod(nb.c_str(), &endptr);
    if (*endptr != '\0')
        std::cout << "Impossible conversion for double\n";
    else
        std::cout << "Double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void PrintFloat(std::string nb, int c)
{
    if (c == 1)
    {
        std::cout << "Float: " << std::fixed << std::setprecision(1) << (float)nb[0] << "f" << std::endl;
        return ;
    }
    char *endptr;
    float d = std::strtof(nb.c_str(), &endptr);
    std::cout << *endptr << std::endl;
    // if (*endptr + 1 == '\0' && *endptr == 'f')
        std::cout << "Float: " << std::fixed << std::setprecision(1) << d << "f" << std::endl;
    if (*endptr != '\0')
        std::cout << "Impossible conversion for float\n";
}

void PrintAllChar(std::string nb)
{
    PrintChar(nb, 1);
    PrintInt(nb, 1);
    PrintFloat(nb, 1);
    PrintDouble(nb, 1);
}

void PrintAllInt(std::string nb)
{
    PrintChar(nb, 1);
    PrintInt(nb, 0);
    PrintFloat(nb, 0);
    PrintDouble(nb, 0);
}

void PrintAll(std::string nb)
{
    PrintChar(nb,1);
    PrintInt(nb, 0);
    PrintFloat(nb, 0);
    PrintDouble(nb, 0);
}

void PrintAllFloat(std::string nb)
{
    PrintChar(nb,1);
    PrintInt(nb, 0);
    PrintFloat(nb, 0);
    PrintDouble(nb, 0);
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
        PrintAll(nb);
    }
    else if ((nb[nb.length() - 1] == 'f' && nb.find('.') != std::string::npos)
        || (nb == "-inff" || nb == "+inff" || nb == "nanf"))
    {
        PrintAll(nb);
    }
    else if (nb.find('.') != std::string::npos || (nb == "nan" || nb == "+inf" || nb == "-inf"))
    {
        PrintAll(nb);
    }
}
