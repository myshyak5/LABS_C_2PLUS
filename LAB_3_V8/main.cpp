#include <iostream>

int main()
{
	unsigned int x;
	short i;
	std::cin >> x >> i;
	std::cout << (x & ~(1 << i)) << std::endl;

	return 0;
}