#include "func.hpp"

int main()
{
    int min_elem = INT_MAX;
    int max_elem = INT_MIN;
    int A[N_max][N_max];
    int n;

    Read(A, n);
    minmaxElem(min_elem, max_elem, A, n);
    if (sumDigits(min_elem) == sumDigits(max_elem))
    {
        Sort(A, n);
    }
    Write(A, n);

    return 0;
}