#include "func.hpp"

int main()
{
    int n;
    int cnt = 0;
    std::string words[N_max];
    
    if (!Read(n, cnt, words))
    {
        std::cerr << "Input File Error" << std::endl;
        return -1;
    }
    ClearElements(cnt, words);
    NewWords(cnt, words);
    Sort(cnt, words);
    if (n <= cnt)
    {
        if (!Write(n, words))
        { 
            std::cerr << "Output File Error" <<std::endl;
            return -1;
        }
    }
    else
    {
        std::cerr << "Error: N more then words";
        return -1;
    }

    return 0;
}
