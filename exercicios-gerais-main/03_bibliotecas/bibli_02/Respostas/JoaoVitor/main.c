#include <stdio.h>
#include "matrix_utils.h"

int main ()
{
    int linhas1, linhas2;
    int colunas1, colunas2;

    scanf ("%d %d", &linhas1, &colunas1);
    int matriz1[linhas1][colunas1];
    matrix_read(linhas1, colunas1, matriz1);

    scanf ("%d %d", &linhas2, &colunas2);
    int matriz2[linhas2][colunas2];
    matrix_read(linhas2, colunas2, matriz2);

    return 0;
}