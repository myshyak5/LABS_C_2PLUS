#include "func.hpp"

void Make(Node*& sent)
{
    sent = new Node;
    sent->next = sent;
    sent->prev = sent;
}
void PushBack(Node* sent, int data)
{
    Node* p = new Node;
    p->data = data;
    p->next = sent;
    p->prev = sent->prev;
    sent->prev->next = p;
    sent->prev = p;
}
void Print(Node* sent)
{
    Node *p = sent->next;
    while (p != sent)
    {
        std::cout << p->data << " ";
        p = p->next;
    }
}
void Clear(Node* sent)
{
    Node *p = sent->next;
    while (p != sent)
    {
        Node* tmp = p;
        p = p->next;
        delete tmp;
    }
}
bool IsEquals(Node* sent)
{
    Node* p = sent;
    do {
        Node* q = p->next;
        while (q != sent)
        {
            if (p->data == q->data)
            {
                return true;
            }
            q = q->next;
        }
        p = p->next;
    } while (p != sent);
    return false;
}
bool IsDigit(int data, int digit)
{
    while (data > 0)
    {
        if (data % 10 == digit)
        {
            return true;
        }
        data /= 10;
    }
    return false;
}
void Sort(Node* sent)
{
    bool swapped;
    do {
        swapped = false;
        Node* p = sent->next;
        while (p->next != sent)
        {
            if ((p->data % 10) < (p->next->data % 10))
            {
                std::swap(p->data, p->next->data);
                swapped = true;
            }
            p = p->next;
        }
    } while (swapped);
}
void Duplicate(Node* sent)
{
    Node *p = sent->next;
    while (p != sent)
    {
        if ((IsDigit(p->data, 7)) && !IsDigit(p->data, 3))
        {
            Node* q = new Node;
            q->data = p->data;
            q->prev = p;
            q->next = p->next;
            p->next->prev = q;
            p->next = q;
            p = q;
        }
        p = p->next;
    }
}
void Remove(Node* sent)
{
    Node *p = sent->next;
    while (p != sent)
    {
        Node* q = p->next;
        if (IsDigit(p->data, 3))
        {
            Node* tmp = p;
            p->prev->next = p->next;
            p->next->prev = p->prev;
            delete tmp;
        }
        p = q;
    }
}