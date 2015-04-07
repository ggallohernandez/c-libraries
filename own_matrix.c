#include "own_matrix.h"

int sum_matrix_upper_triangle(int m[][TAM])
{
    int i, j, r = 0;

    for (i = 0; i < TAM; i++)
        for (j = i + 1; j < TAM; j++)
            r += m[i][j];

    return r;
}
