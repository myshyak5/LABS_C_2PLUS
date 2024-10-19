#include <iostream>

bool Palindrom(int p)
{
    int p_orig = p;
    int mirror = 0;

    while (p > 0)
    {
        mirror = (mirror * 10) + (p % 10);
        p /= 10;
    }

    return mirror == p_orig;
}

int sumDigits(int s)
{
    int sum_digits = 0;

    while (s > 0)
    {
        sum_digits += s % 10;
        s /= 10;
    }

    return sum_digits;
}

int main()
{
    int A[20000];
    int j;
    std::cin >> j;

    if (j <= 10000)
    {
        int g = 0;

        for (int i = 0; i < j; i++)
        {
            std::cin >> A[i];
        }
        for (int i = 0; i < j; i++)
        {
            if (sumDigits(A[i]) != 10)
            {
                A[g] = A[i];
                g++;
            }
        }
        j = g;
        
        for (int i = 0; i < j; i++)
        {
            if (Palindrom(A[i]))
            {
                for (int u = j; u > i; u--)
                {
                    A[u] = A[u - 1];
                }
                i++;
                j++;
            }
        }
        for (int i = 0; i < j; i++)
        {
            std::cout << A[i] << " ";
        }
    }

    return 0;
}