#include "Scalar.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        try
        {
            ScalarConverter::Convert(av[1]);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}
