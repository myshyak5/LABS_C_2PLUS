#include "func.hpp"

int main()
{
    int cnt = 0;
    std::string words[N_max];
    int CountSogl[N_max];
    
    if (!Read(cnt, words))
    {
        std::cerr << "Input File Error" << std::endl;
        return -1;
    }
    ClearElements(cnt, words);
    if (!IsPalindromMoreOneLetter(cnt, words))
    {
        CountOfSogl(cnt, words, CountSogl);
        SortNotPalindrom(cnt, words, CountSogl);
    }
    else
    {
        ClearGl(cnt, words);
        SortPalindrom(cnt, words, CountSogl);
    }
    ClearEmpty(cnt, words);
    Write(cnt, words);
    
    return 0;
}
