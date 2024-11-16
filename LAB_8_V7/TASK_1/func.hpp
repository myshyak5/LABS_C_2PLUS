#pragma once
#include <iostream>
#include <string>
#include <fstream>

const int N_max = 2000;

bool Read(int& n, int& cnt, std::string words[N_max]);
void ClearElements(int cnt, std::string words[N_max]);
void IsTwoEqualLetters(std::string words[N_max], char sogli, int& k, int i);
bool IsEqualLetters(int cnt, std::string words[N_max], int i);
void NewWords(int& cnt, std::string words[N_max]);
void CountLettersInWord(int cnt, std::string words[N_max], int CountLetters[N_max]);
void Sort(int cnt, std::string words[N_max], int CountLetters[N_max]);
bool Write(int n, std::string words[N_max]);