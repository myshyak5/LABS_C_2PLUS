#include <iostream>

int Max(int m, int k)
{
    if (m > k)
    {
        return m;
    }
    return k;
}
int f(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return Max(f(n / 10), n % 10);
}
int main()
{
    unsigned int n;
    std::cin >> n;
    if ((n > 0) && (n < pow(2, 31)))
    {
        std::cout << f(n);
    }

    return 0;
}
