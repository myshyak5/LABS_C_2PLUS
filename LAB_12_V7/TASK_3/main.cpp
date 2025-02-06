#include <iostream>
#include <fstream>

const int N_max = 100;

void Search(int i, int j, int step, int n, int m, char field[N_max][N_max], int table[N_max][N_max])
{
    if (step >= table[i][j])
    {
        return;
    }
    table[i][j] = step;

    if (field[i][j] == 'E')
    {
        return;
    }

    if ((i + 1) < n && field[i + 1][j] != '#')
        Search(i + 1, j, step + 1, n, m, field, table);
    if ((i - 1) >= 0 && field[i - 1][j] != '#')
        Search(i - 1, j, step + 1, n, m, field, table);
    if ((j + 1) < m && field[i][j + 1] != '#')
        Search(i, j + 1, step + 1, n, m, field, table);
    if ((j - 1) >= 0 && field[i][j - 1] != '#')
        Search(i, j - 1, step + 1, n, m, field, table);
    if ((j + 1) < m && (i + 1) < n && field[i + 1][j + 1] != '#') 
        Search(i + 1, j + 1, step + 1, n, m, field, table);
    if ((j - 1) >= 0 && (i - 1) >= 0 && field[i - 1][j - 1] != '#') 
        Search(i - 1, j - 1,step + 1, n, m, field, table);
    if ((j - 1) >= 0 && (i + 1) < n && field[i + 1][j - 1] != '#') 
        Search(i + 1, j - 1, step + 1, n, m, field, table);
    if ((j + 1) < m && (i - 1) >= 0 && field[i - 1][j + 1] != '#') 
        Search(i - 1, j + 1, step + 1, n, m, field, table);
}
int main()
{
    char field[N_max][N_max];
    int table[N_max][N_max];

    std::ifstream in("input.txt");
    int n, m;
    int is, js;
    int ie, je;
    in >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            table[i][j] = INT_MAX;
            in >> field[i][j];
            if (field[i][j] == 'S')
            {
                is = i;
                js = j;
            }
            else if (field[i][j] == 'E')
            {
                ie = i;
                je = j;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            std::cout << field[i][j] << " ";
        }
        std::cout << std::endl;
    }
    Search(is, js, 0, n, m, field, table);
    if (table[ie][je] == INT_MAX)
    {
        std::cout << -1 << std::endl;
    }
    else
    {
        std::cout << table[ie][je] << std::endl;
    }

    return 0;
}