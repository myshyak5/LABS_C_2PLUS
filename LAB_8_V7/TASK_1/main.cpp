#include "func.hpp"

int main()
{
    int n;
    int cnt = 0;
    std::string words[N_max];
    int CountLetters[N_max];
    
    if (!Read(n, cnt, words))
    {
        std::cerr << "Input File Error" << std::endl;
        return -1;
    }
    ClearElements(cnt, words);
    NewWords(cnt, words);
    CountLettersInWord(cnt, words, CountLetters);
    Sort(cnt, words, CountLetters);
    if (n <= cnt)
    {
        Write(n, words);
    }
    else
    {
        std::cerr << "Error: N more then words";
    }

    return 0;
}