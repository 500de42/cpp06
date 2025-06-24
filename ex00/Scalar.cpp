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
        std::cout << "int: " << (int)nb[0] << std::endl;
        return ;
    }
    else if ((nb == "-inff" || nb == "+inff" || nb == "nanf" || nb == "nan" || nb == "+inf" || nb == "-inf" || nb == "inf" || nb == "inff"))
    {
        std::cout << "Int : impossible" << std::endl;
        return ;
    }
    long num = atol(nb.c_str());
    if (num < -2147483648 || num > 2147483647)
        std::cout << "limit of int exceeded\n";
    else if (!nuum(nb))
    {
        std::cout << nuum(nb) << "int: Impossible Convertion\n";
    }
    else
        std::cout << "Int: " << num << std::endl;
}

void PrintChar(std::string nb, int c)
{
    long num = atoi(nb.c_str());
    if ((nb[0] < 127 && nb[0] > 31) && (c == 1))
    {
        std::cout << "Char: " << nb[0] << std::endl;
        return ;
    }
    else if ((nb == "-inff" || nb == "+inff" || nb == "nanf" || nb == "nan" || nb == "+inf" || nb == "-inf" || nb == "inf" || nb == "inff"))
    {
        std::cout << "Char : impossible" << std::endl;
        return ;
    }
    else if (((num < 127 && num > 31)) && (c == 2))
    {
        std::cout << "Char: " << (char)num << std::endl;
        return ;
    }
    else if ((nb[0] > 31 && nb[0] < 127) && !nb[1] && !isdigit(nb[0]))//num 127 32
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
    if (*endptr == 'f' || *endptr == '\0')
        std::cout << "Double: " << std::fixed << std::setprecision(1) << d << std::endl;
    else if (*endptr != '\0')
        std::cout << "Impossible conversion for double\n";
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
    if (*endptr == 'f' || *endptr == '\0')
        std::cout << "Float: " << std::fixed << std::setprecision(1) << d << "f" << std::endl;
    else if (*endptr != '\0')
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
    PrintChar(nb, 2);
    PrintInt(nb, 0);
    PrintFloat(nb, 0);
    PrintDouble(nb, 0);
}

void PrintAllDoubleFLoat(std::string nb)
{
    PrintChar(nb,2);
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


int parse(std::string nb)
{
    int point = 0;
    int tiret = 0;
    int f = 0;
    if (((nb == "inff" || nb == "inf" ||nb == "-inff" || nb == "+inff" || nb == "nanf" || nb == "nan" || nb == "+inf" || nb == "-inf")))
        return 1;
    for(std::string::iterator i = nb.begin(); i < nb.end(); i++)
    {
        if (!(*i >= '0' && *i <= '9') && nb.length() > 1)
        {
            if (*i == '.')
            {
                point++;
                continue;
            }
            else if (*i == '-')
            {
                if (*i != nb[0])
                    return 0;
                tiret++;
                continue;
            }
            else if (*i == 'f')
            {
                if ((*i != nb[nb.length() - 1]))
                    return 0;
                f++;
            }
            else
            {
               return 0;
            }
        }
    }
    if (point > 1 || tiret > 1 || f > 1)
        return 0;
    return 1;
}

void ScalarConverter::Convert(std::string nb)
{
    if (nb.empty())
        return ;
    if (!parse(nb))
    {
        std::cout << "Char: impossible\nInt: impossible\nFloat: impossible\nDouble: impossible\n";
        return ;
    }
    if ((nb.length() == 1) && (nb[0] > 31 && nb[0] < 127) && !isdigit(nb[0]))
    { 
        PrintAllChar(nb);
    }
    else if (nb[nb.length() - 1] != 'f' && nb.find('.') == std::string::npos)//int
    {
        PrintAllInt(nb);
    }
    else if ((nb[nb.length() - 1] == 'f' && nb.find('.') != std::string::npos)//float
        || (nb == "-inff" || nb == "+inff" || nb == "nanf" || nb == "inff"))
    {
        PrintAllDoubleFLoat(nb);
    }
    else if (nb.find('.') != std::string::npos || (nb == "nan" || nb == "+inf" || nb == "-inf" || nb == "inf"))//double
    {
        PrintAllDoubleFLoat(nb);
    }
}

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
    (void)copy;
}

ScalarConverter::~ScalarConverter()
{

}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
    (void)src;
    return *this;
}
