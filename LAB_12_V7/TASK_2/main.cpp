// swap O(n^2)
// quick O(n * logn)
#include <iostream>
#include <thread>

void QuickSort(int a, int b, int* arr)
{
    if (a >= b)
    {
        return;
    }
    int k = (rand() * rand()) % (b - a + 1) + a;
    int m = arr[k];
    
    int l = a - 1;
    int r = b + 1;
    while(true)
    {
        do l++; while(arr[l] < m);
        do r--; while(arr[r] > m);
        if (l >= r)
        {
            break;
        }
        std::swap(arr[l], arr[r]);
    }
    l = r;
    r++;
    QuickSort(a, l, arr);
    QuickSort(r, b, arr);
}
const int n = 5;
int arr[n] = {2, 3, 1, 6, 4};
int main()
{
    srand(time(0));
    QuickSort(0, n - 1, arr);
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}