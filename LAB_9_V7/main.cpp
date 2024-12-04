#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    
    int* p = &n;
    

    unsigned char* c = reinterpret_cast<unsigned char*>(p);
    for (int i = 0; i < 4; i++) std::cout << static_cast<int>(*(c + i)) << std::endl;

    return 0;
}