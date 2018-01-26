#include <iostream>
using namespace std;

const int N = 9;
const int S = 3;
const int N2 = N * N;

unsigned short bd[N][N] = {
    {0, 0, 9, 0, 0, 0, 4, 5, 0},
    {0, 0, 3, 6, 0, 0, 0, 0, 8},
    {0, 0, 0, 0, 2, 0, 0, 6, 7},
    {0, 4, 0, 0, 0, 9, 0, 0, 0},
    {0, 0, 2, 0, 0, 0, 0, 0, 3},
    {0, 8, 6, 0, 0, 0, 5, 7, 0},
    {0, 0, 4, 0, 9, 0, 0, 0, 2},
    {2, 0, 0, 7, 0, 0, 8, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0}
};

void printbd()
{
    for (int r = 0; r < N; ++r)
    {
        for (int c = 0; c < N; ++c)
            cout << bd[r][c] << "  ";
        cout << endl;
    }
}

bool valid(int r, int c)
{
    int v = bd[r][c];
    int dr = r / S * S, dc = c / S * S;
    for (int i = 0; i < N; ++i)
    {
        if ((i != c && v == bd[r][i]) || (i != r && v == bd[i][c]))
        {
            return false;
        }
        int di = dr + i / S, dj = dc + i % S;
        if (!(di == r && dj == c) && v == bd[di][dj])
            return false;
    }
    
    return true;
}

bool sudoku(int m = 0)
{
    if (m >= N2)
        return true;
    
    int r = m/N, c = m%N;
    if (bd[r][c] > 0)
    {
        return sudoku(m+1);
    }
    
    for (int i = 1; i <= N; ++i)
    {
        bd[r][c] = i;
        if (valid(r,c) && sudoku(m+1))
            return true;
    }
    
    bd[r][c] = 0;
    return false;
}

int main(int argc, const char **argv)
{
    if (sudoku())
    {
        cout << "Yes" << endl;
        printbd();
    }
    else
    {
        cout << "No" << endl;
        printbd();
    }

    return EXIT_SUCCESS;
}

