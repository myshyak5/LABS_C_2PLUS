#include <iostream> 
#include <typeinfo>

int main() 
{ 
    int integerType; 
    char charType; 
    float floatType; 
    double doubleType;
	bool boolType;

	std::cout << "Type of int: " << typeid(integerType).name() << std::endl;
	std::cout << "Type of char: " << typeid(charType).name() << std::endl;
	std::cout << "Type of float: " << typeid(floatType).name() << std::endl;
	std::cout << "Type of double: " << typeid(doubleType).name() << std::endl;
	std::cout << "Type of bool: " << typeid(boolType).name() << std::endl;

    std::cout << "Size of int: " << sizeof(integerType) << std::endl; 
    std::cout << "Size of char: " << sizeof(charType) << std::endl; 
    std::cout << "Size of float: " << sizeof(floatType) << std::endl;
    std::cout << "Size of double: " << sizeof(doubleType) << std::endl;
    std::cout << "Size of bool: " << sizeof(boolType) << std::endl;

    std::cout << "Minimum int: " << INT_MIN << std::endl;
    std::cout << "Maximum int: " << INT_MAX << std::endl;
    std::cout << "Minimum char: " << CHAR_MIN<< std::endl;
    std::cout << "Maximum char: " << CHAR_MAX << std::endl;
    std::cout << "Minimum float: " << INT_MIN << std::endl;
    std::cout << "Maximum float: " << INT_MAX << std::endl;
    std::cout << "Minimum double: " << DBL_MIN << std::endl;
    std::cout << "Maximum double: " << DBL_MAX << std::endl;
    std::cout << "Minimum bool: " << "0" << std::endl;
    std::cout << "Maximum bool: " << "1" << std::endl;
    
    int xi = 1, yi = 4;
    char xc = 201, yc = 200;
    float xf = 1.1, yf = 2.2;
    double xd = 1.2546, yd = 2.2567;
    bool xb = 1 > 0, yb = 0 > 1;

    std::cout << "Int: " << xi << " + " << yi << " = " << xi - yi << std::endl;
    std::cout << "Char: " << xc << " + " << yc << " = " << char(xc - yc) << std::endl;
    std::cout << "Float: " << xf << " + " << yf << " = " << xf - yf << std::endl;
    std::cout << "Double: " << xd << " + " << yd << " = " << xd - yd << std::endl;
    std::cout << "Bool: " << xb << " + " << yb << " = " << xb - yb << std::endl;

    return 0;
}