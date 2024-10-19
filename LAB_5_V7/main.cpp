#include <iostream>

int main()
{
//1 задание
    int j;
    int a;
    int min_37 = INT_MAX;
    int sum = 0;
    int num_min_37 = 0;

    std::cin >> j;
    for (int i = 0; i < j; i++)
    {
        std::cin >> a;

        if (((a % 7) == 0) || ((a % 3) == 0))
        {
            sum += a;
            if (a < min_37)
            {   
                min_37 = a;
                num_min_37 = i;
            }
        }
    }
    
    if (min_37 == INT_MAX)
    {
        std::cout << "0" << std::endl;
    }
    else
    {
        std::cout << sum << std::endl;
        std::cout << min_37 << std::endl;
        std::cout << num_min_37 << std::endl;
    }

//2 задание
    unsigned int N;
    int mult = 1;

    std::cin >> N;
    while (N > 0)
    {
        int c = N % 10;
        if ((c % 2) == 0)
        {
            mult *= c;
        }
        N /= 10;
    }
    if (mult == 1)
    {
        std::cout << "0" << std::endl;
    }
    else
    {
        std::cout << mult << std::endl;
    }

    return 0;
}