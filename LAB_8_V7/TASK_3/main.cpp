#include "func.hpp"

//char gl[6] = {'A', 'E', 'I', 'O', 'U', 'Y'};
int main()
{
    int cnt = 0;
    std::string words[N_max];
    if (!Read(cnt, words))
    {
        std::cerr << "Input File Error" << std::endl;
        return -1;
    }
    std::ofstream out("output.txt");
    if (!out.is_open())
    {
        std::cerr << "Output File Error" << std::endl;
        return -1;
    }
    for (int i = 0; i < cnt; i++)
    {
        int let_a = 0;
        int let_e = 0;
        int let_i = 0;
        int let_o = 0;
        int let_u = 0;
        int let_y = 0;
        std::string result = "";
        std::string word = "";
        std::string signs = "";
        std::string glasnie = "";
        for (int j = 0; j < words[i].length(); j++)
        {
            char wordsij = words[i][j];
            if (std::isalpha(wordsij))
            {
                word += wordsij;
                char wordsij_up = std::toupper(wordsij);
                Glas(wordsij_up, glasnie, let_a, let_e, let_i, let_o, let_u, let_y);
            }
            else
            {
                if ((wordsij != ' ') && (wordsij != '-') && (!std::isdigit(wordsij)))
                {
                    signs += wordsij;
                }
                else
                {
                    FourDiffLet(word, glasnie, let_a, let_e, let_i, let_o, let_u, let_y);
                    result += word + signs + wordsij;
                    Null(word, signs, glasnie, let_a, let_e, let_i, let_o, let_u, let_y);
                }
            }
        }
        ClearEmpty(result);
        out << result << std::endl;
    }
    out.close();

    return 0;
}
