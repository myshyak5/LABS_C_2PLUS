#include "func.hpp"

void Read(int m[N_max][N_max], int& n)
{
    std::cin >> n;

    if (n <= 100)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                std::cin >> m[i][j];
            }
        }
    }
}

void minmaxElem(int& min_elem, int& max_elem, int m[N_max][N_max], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int a = m[i][j];

            if (a < min_elem)
            {
                min_elem = a;
            }
            if (a > max_elem)
            {
                max_elem = a;
            }
        }
    }
}

int sumDigits(int a)
{
    int sum_a = 0;

    while (a > 0)
    {
        sum_a += a % 10;
        a /= 10;
    }

    return sum_a;
}

int sumElements(int m[N_max][N_max], int n, int k)
{
    int sum_elements = 0;

    for (int i = 0; i < n; i++)
    {
        sum_elements += m[k][i];
    }

    return sum_elements;
}

void Sort(int m[N_max][N_max], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (sumElements(m, i, n) > sumElements(m, i + 1, n))
        {
            for (int j = 0; j < n; j++)
            {
                std::swap(m[i][j], m[i + 1][j]);
            }
        }
    }
}

void Write(int m[N_max][N_max], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << m[i][j] << " ";
        }
    std::cout << std::endl;
    }
}