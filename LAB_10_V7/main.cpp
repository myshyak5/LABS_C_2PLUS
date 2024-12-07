#include "func.hpp"

int main()
{
    mt::Node* head;
    mt::Make(head);
    bool one = false;
    int n;
    std::cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        int value;
        std::cin >> value;
        if ((mt::IsOneFirstDigit(value) == true) && (one != true))
        {
            one = true;
        }
        mt::PushBack(head, value);
    }
    if (one == true)
    {
        mt::Sort(head);
    }
    else
    {
        mt::Remove(head);
        mt::Double(head);
    }
    mt::Print(head);

    return 0;
}