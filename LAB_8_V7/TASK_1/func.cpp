#include "func.hpp"

bool Read(int& n, int& cnt, std::string words[N_max])
{
    std::ifstream in("input.txt");
    if (!in.is_open())
    {
        return false;
    }
    in >> n;
    while (!in.eof())
    {
        in >> words[cnt];
        cnt++;
    }
    return true;
}
void ClearElements(int cnt, std::string words[N_max])
{
    for (int i = 0; i < cnt; i++)
    {
        for (int j = 0; j < words[i].length(); j++)
        {
            if (!std::isalpha(words[i][j]))
            {
                words[i].erase(j, 1);
                j--;
            }
        }
    }
}
void IsTwoEqualLetters(std::string words[N_max], char sogli, int& k, int i)
{
    std::size_t index = words[i].find(sogli);
    while ((k != 2) && (index != std::string::npos))
    {
        k += 1;
        index = words[i].find(sogli, index + 1);
    }
}
bool IsEqualLetters(int cnt, std::string words[N_max], int i)
{
    char sogl[20] {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'z'};
    for (int j = 0; j < 20; j++)
    {
        char sogli_low = sogl[j];
        char sogli_up = (char)((int)sogl[j] - 32);
        int k = 0;
        IsTwoEqualLetters(words, sogli_low, k, i);
        IsTwoEqualLetters(words, sogli_up, k, i);
        if (k == 2)
        {
            return true;
            break;
        }
    }
    return false;
}

void NewWords(int& cnt, std::string words[N_max])
{
    int g = 0;
    for (int i = 0; i < cnt; i++)
    {
        if (!IsEqualLetters(cnt, words, i))
        {
            words[g] = words[i];
            g++;
        }
    }
    cnt = g;
    for (int i = 0; i < cnt; i++)
    {
        for (int j = i + 1; j < cnt; j++)
        {
            if (words[i] == words[j])
            {
                for (int c = i; c < cnt - 1; c++)
                {
                    words[c] = words[c + 1];
                }
                cnt--;

            }
        }
    }
}

void CountLettersInWord(int cnt, std::string words[N_max], int CountLetters[N_max])
{
    for (int i = 0; i < cnt; i++)
    {
        CountLetters[i] = words[i].length();
    }
}

void Sort(int cnt, std::string words[N_max], int CountLetters[N_max])
{
    for (int i = 0; i < cnt - 1; i++)
    {
        for (int j = i + 1; j < cnt; j++)
        {
            if (CountLetters[i] < CountLetters[j])
            {
                std::swap(words[i], words[j]);
                std::swap(CountLetters[i], CountLetters[j]);
            }
        }
    }
}

bool Write(int n, std::string words[N_max])
{
    std::ofstream outt("output.txt");
    if (!outt.is_open())
    {
        return false;
    }
    for (int i = 0; i < n; i++)
    {
        outt << words[i] << std::endl;
    }
    return true;
}
