#include <iostream>

int main()
{
    int A[100][100];
    int maxSum = 0;
    int numStr = -1;
    int i, j;
    std::cin >> i >> j;
    if (i <= 100 && j <= 100)
    {
        for (int m = 0; m < i; m++)
        {
            int sum = 0;
            
            for (int n = 0; n < j; n++)
            {
                std::cin >> A[m][n];
                sum += A[m][n];
            }
            if (sum > maxSum)
            {
                maxSum = sum;
                numStr = m;
            }
        }
        for (int n = 0; n < j; n++)
        {
            A[numStr][n]++;
        }
        for (int m = 0; m < i; m++)
        {
            for (int n = 0; n < j; n++)
            {
                std::cout << A[m][n] << " ";
            }
            std::cout << std::endl;
        }
    }
    
    return 0;
}