#include <iostream>
#include "fraction.hpp"

int main()
{
    Fraction f1 { 3, 4 };
    Fraction f2 { 1, 2 };

    std::cout << "f1 = ";
    //f1.display();
    std::cout << f1;
    std::cout << " f2 = ";
    //f2.display();
    std::cout << f2;
    std::cout << std::endl;

    Fraction f3 { operator+(f1, f2) };

    std::cout << "add(f1, f2) = ";
    //f3.display();
    std::cout << f3;

    std::cout << std::endl << "sub(f1, f2) = ";
    //(operator-(f1, f2)).display();
    std::cout  << operator-(f1, f2);

    std::cout << std::endl << "mul(f1, f2) = ";
    //(operator*(f1, f2)).display();
    std::cout  << operator*(f1, f2);

    std::cout << std::endl << "div(f1, f2) = ";
    //(operator/(f1, f2)).display();
    std::cout  << operator/(f1, f2);

    std::cout << std::endl << "add(1/6, 2/6) = ";
    //(operator+({1, 6}, {2, 6})).display();
    std::cout  << operator+({1, 6}, {2, 6});
    
    std::cout << std::boolalpha;
    std::cout << std::endl << "f1 et f2 sont egaux : ";
    std::cout << operator==(f1, f2);
    std::cout << std::endl << "f1 et f1 sont egaux : ";
    std::cout <<  operator==(f1, f1);
    std::cout << std::endl << "f1 et f2 sont differents : ";
    std::cout <<  operator!=(f1, f2);
    std::cout << std::endl << "f2 et f2 sont differents : ";
    std::cout <<  operator!=(f2, f2);

    std::cout << std::endl << "f1 est strictement inferieur a f2 : ";
    std::cout <<  operator<(f1, f2);
    std::cout << std::endl << "f1 est strictement superieur a f2 : ";
    std::cout <<  operator>(f1, f2);
    std::cout << std::endl << "f1 est inferieur ou egal a f2 : ";
    std::cout <<  operator<=(f1, f2);
    std::cout << std::endl << "f1 est inferieur ou egal a f1 : ";
    std::cout <<  operator<=(f1, f1);
    std::cout << std::endl << "f1 est superieur ou egal a f2 : ";
    std::cout <<  operator>=(f1, f2);
    std::cout << std::endl << "f2 est superieur ou egal a f2 : ";
    std::cout <<  operator>=(f2, f2);

    std::cout << std::endl << "f1 =";
    std::cout << Fraction::to_float(f1);
    std::cout << std::endl << "f2 =";
    std::cout << Fraction::to_float(f2);

    return 0;
}