#include "func.hpp"

namespace mt
{
    void Make(Node*& head)
    {
        head = new Node {0, nullptr};
    }

    void PushBack(Node* head, int value)
    {
        Node* p = head;
        while (p->next != nullptr)
        {
            p = p->next;
        }
        Node* q = new Node;
        q->data = value;
        q->next = nullptr;
        p->next = q;
    }

    void Print(Node* head)
    {
        Node* p = head->next;
        while (p != nullptr)
        {
            std::cout << p->data << " ";
            p = p->next;
        }
    }

    void Remove(Node* head)
    {
        Node* p = head;
        while (p->next != nullptr)
        {
            if (((p->next->data % 3) == 0) && (p->next->data != 3))
            {
                Node* tmp = p->next;
                p->next = tmp->next;
                delete tmp;
            }
            else
            {
                p = p->next;
            }
        }
    }

    void Sort(Node* head)
    {
        for (Node* i = head; i != nullptr; i = i->next)
        {
            for (Node* p = head; p->next != nullptr; p = p->next)
            {
                if (p->data > p->next->data)
                {
                    std::swap(p->data, p->next->data);
                }
            }
        }
    }

    void Double(Node* head)
    {
        Node *p = head->next;
        while (p != nullptr)
        {
            if (IsPrime(p->data))
            {
                Node* q = new Node;
                q->data = p->data;
                q->next = p->next;
                p->next = q;
                p = q;
            }
            p = p->next;
        }
    }

    bool IsPrime(int n)
    {
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }

    bool IsOneFirstDigit(int elem)
    {
        while (elem > 9)
        {
            elem /= 10;
        }
        if (elem == 1)
        {
            return true;
        }
        return false;
    }
}