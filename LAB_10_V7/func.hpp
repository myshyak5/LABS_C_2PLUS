#pragma once
#include <iostream>
#include <fstream>

namespace mt
{
    #pragma pack(push, 1)
    struct Node
    {
        int data;
        Node* next;
    };
    #pragma pack(pop)
    void PushBack(Node* head, int value);
    void Print(Node* head);
    void Remove(Node* head);
    void Make(Node*& head);
    void Sort(Node* head);
    bool IsOneFirstDigit(int elem);
    bool IsPrime(int n);
    void Double(Node* head);
}