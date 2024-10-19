#pragma once
#include <iostream>

const int N_max = 100;

void Read(int m[N_max][N_max], int& n);
void minmaxElem(int& min_elem, int& max_elem, int m[N_max][N_max], int n);
int sumDigits(int a);
int sumElements(int m[N_max][N_max], int n, int k);
void Sort(int m[N_max][N_max], int n);
void Write(int m[N_max][N_max], int n);