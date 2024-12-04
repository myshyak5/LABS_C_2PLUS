#include "func.hpp"

bool Read(int& cnt, std::string words[N_max])
{
    std::ifstream in("input.txt");
    if (!in.is_open())
    {
        return false;
    }
    std::string string;
    while (std::getline(in, string))
    {
        words[cnt] = string + " ";
        cnt++;
    }
    return true;
}
void Glas(char wordsij_up, std::string& glasnie, int& let_a, int& let_e, int& let_i, int& let_o, int& let_u, int& let_y)
{
    if ((wordsij_up == 'A') && (let_a == 0))
    {
        let_a++;
        glasnie += 'A';
    }
    else if ((wordsij_up == 'E') && (let_e == 0))
    {
        let_e++;
        glasnie += 'E';
    }
    else if ((wordsij_up == 'I') && (let_i == 0))
    {
        let_i++;
        glasnie += 'I';
    }
    else if ((wordsij_up == 'O') && (let_o == 0))
    {
        let_o++;
        glasnie += 'O';
    }
    else if ((wordsij_up == 'U') && (let_u == 0))
    {
        let_u++;
        glasnie += 'U';
    }
    else if ((wordsij_up == 'Y') && (let_y == 0))
    {
        let_y++;
        glasnie += 'Y';
    }
}
void FourDiffLet(std::string& word, std::string glasnie, int let_a, int let_e, int let_i, int let_o, int let_u, int let_y)
{
    if ((let_a + let_e + let_i + let_o + let_u + let_y) >= 4)
    {
        for (int n = 0; n < word.length(); n++)
        {
            word[n] = std::toupper(word[n]);
        }
        word += '(' + glasnie + ')';
    }
}

void ClearEmpty(std::string result)
{
    if (result[result.length() - 1] == ' ')
    {
        result.erase(result.length() - 1, 1);
    }
}
void Null(std::string& word, std::string& signs, std::string& glasnie, int& let_a, int& let_e, int& let_i, int& let_o, int& let_u, int& let_y)
{
    word.erase();
    signs.erase();
    glasnie.erase();
    let_a = 0;
    let_e = 0;
    let_i = 0;
    let_o = 0;
    let_u = 0;
    let_y = 0;
}
