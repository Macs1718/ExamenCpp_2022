#include <iostream>
#include "addition.hpp"
#include "multiplication.hpp"
#include "variable.hpp"
#include "constante.hpp"

int main()
{
    auto x = std::make_shared<Variable>();
    auto three = std::make_shared<Constante>(3.);
    auto two = std::make_shared<Constante>(2.);
    auto fonction = three * x * x + two * x;

    std::cout << "fonction f : " << fonction->to_string() << std::endl;
    std::cout << "fonction df: " << fonction->deriv()->to_string() << std::endl;
    std::cout << "f(3) = " << (*fonction)(3) << std::endl;
    std::cout << "df(3) = " << (*fonction->deriv())(3) << std::endl;

    return EXIT_SUCCESS;
}