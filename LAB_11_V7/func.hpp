#pragma once
#include <iostream>

struct Node
{
    int data;
    Node* prev;
    Node* next;
};
void Make(Node*& sent);
void PushBack(Node* sent, int data);
void Print(Node* sent);
void Clear(Node* sent);
bool IsEquals(Node* sent);
bool IsDigit(int data, int digit);
void Sort(Node* sent);
void Duplicate(Node* sent);
void Remove(Node* sent);