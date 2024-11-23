#pragma once
#include <iostream>
#include <string>
#include <fstream>

const int N_max = 10248;

bool Read(int& cnt, std::string words[N_max]);
void ClearElements(int cnt, std::string words[N_max]);
void ClearGl(int cnt, std::string words[N_max]);
void ClearEmpty(int& cnt, std::string words[N_max]);
bool IsPalindromMoreOneLetter(int cnt, std::string words[N_max]);
void CountOfSogl(int cnt, std::string words[N_max], int CountSogl[N_max]);
void SortPalindrom(int cnt, std::string words[N_max], int CountSogl[N_max]);
void SortNotPalindrom(int cnt, std::string words[N_max], int CountSogl[N_max]);
bool Write(int cnt, std::string words[N_max]);
