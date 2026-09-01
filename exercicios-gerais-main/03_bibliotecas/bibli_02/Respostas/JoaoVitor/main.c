#include <stdio.h>
#include "matrix_utils.h"

void imprimeMenu()
{
    printf ("1 - Somar matrizes\n");
    printf ("2 - Subtrair matrizes\n");
    printf ("3 - Multiplicar matrizes\n");    
    printf ("4 - Multiplicacao de uma matriz por escalar\n");
    printf ("5 - Transposta de uma matriz\n");
    printf ("6 - Encerrar o programa\n");
    printf ("Opcao escolhida: ");
    printf ("\n");
}

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