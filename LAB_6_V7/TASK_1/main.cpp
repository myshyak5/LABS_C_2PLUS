#include <iostream>

bool checkDigits(int n)
{
    int digit = n % 10;

    while (n > 0)
    {
        int current_digit = n % 10;

        n /= 10;
        if (current_digit != digit)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int a[10000];
    bool sort = true;
    int j;
    std::cin >> j;

    if (j <= 10000)
    {
        for (int i = 0; i < j; i++)
        {
            std::cin >> a[i];
        }
        for (int i = 0; i < j; i++)
        {
            if (checkDigits(a[i]))
            {
                sort = false;
                break;
            }
        }
        if (sort)
        {
            for (int i = 0; i < j - 1; i++)
            {
                for (int ii = i + 1; ii < j; ii++)
                {
                    if (a[i] < a[ii])
                    {
                        std::swap(a[i], a[ii]);
                    }
                }
            }
        }
        for (int i = 0; i < j; i++)
        {
            std::cout << a[i] << " ";
        }
    }

    return 0;
}