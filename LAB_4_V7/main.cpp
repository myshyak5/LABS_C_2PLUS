#include <iostream>


//1 задание
int main()
{
    unsigned int A;
    unsigned int B;
    unsigned int C;

    std::cin >> A >> B >> C;
    if (((A % B) == 0) && (B > C))
    {
        std::cout << int(A / B + C) << std::endl;
    }
    else if (((A % B) == 0) && (B < C))
    {
        std::cout << int(A / B - C) << std::endl;
    }
    else
    {
        std::cout << int((A + B) * C) << std::endl;
    }

//2 задание
    unsigned short N;

    std::cin >> N;
    switch(N)
    {
        case 1:
            std::cout << "Monday" << std::endl;
            break;
        case 2:
            std::cout << "Tuesday" << std::endl;
            break;
        case 3:
            std::cout << "Wednesday" << std::endl;
            break;
        case 4:
            std::cout << "Thursday" << std::endl;
            break;
        case 5:
            std::cout << "Friday" << std::endl;
            break;
        case 6:
            std::cout << "Saturday" << std::endl;
            break;
        case 7:
            std::cout << "Sunday" << std::endl;
            break;
        default:
            std::cout << "Error" << std::endl;
            break;
    }

//3 задание
    short x;

    std::cin >> x;
    switch(x)
    {
        case -1:
            std::cout << "Negative number" << std::endl;
            break;
        case 1:
            std::cout << "Positive number" << std::endl;
            break;
        default:
            std::cout << "Error" << std::endl;
            break;
    }
    
    return 0;
}