#include "func.hpp"

int main()
{
    Node* sent;
    Make(sent);
    int n;
    std::cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        int data;
        std::cin >> data;
        PushBack(sent, data);
    }
    if (IsEquals(sent))
    {
        Sort(sent);
    }
    else
    {
        Remove(sent);
        Duplicate(sent);
    }
    Print(sent);
    Clear(sent);

    return 0;
}