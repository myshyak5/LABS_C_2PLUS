#pragma once
#include <iostream>
#include <string>
#include <fstream>

const int N_max = 10248;

bool Read(int& cnt, std::string words[N_max]);
void Glas(char wordsij_up, std::string& glasnie, int& let_a, int& let_e, int& let_i, int& let_o, int& let_u, int& let_y);
void FourDiffLet(std::string& word, std::string glasnie, int let_a, int let_e, int let_i, int let_o, int let_u, int let_y);
void ClearEmpty(std::string result);
void Null(std::string& word, std::string& signs, std::string& glasnie, int& let_a, int& let_e, int& let_i, int& let_o, int& let_u, int& let_y);
