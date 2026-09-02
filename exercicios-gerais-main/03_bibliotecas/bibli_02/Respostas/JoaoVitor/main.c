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
}

void executaMenu(int linhas1, int colunas1, int matriz1[linhas1][colunas1], int linhas2, int colunas2, int matriz2[linhas2][colunas2])
{
    int opcao = 0;
    int matrizFinal[linhas1][colunas1];
    int matrizFinalMultiplicacao[linhas1][colunas2];
    int escalar;

    while (opcao != 6)
    {
        imprimeMenu();
        scanf ("%d", &opcao);
        printf ("\n");

        if (opcao == 1)
        {
            if (possible_matrix_sum(linhas1, colunas1, linhas2, colunas2))
            {
                matrix_add(linhas1, colunas1, matriz1, linhas2, colunas2, matriz2, matrizFinal);
                matrix_print(linhas1, colunas1, matrizFinal);
            }

            else 
            {
                printf ("Erro: as dimensoes da matriz nao correspondem\n\n");
                continue;
            }
        }

        if (opcao == 2)
        {
            if (possible_matrix_sub(linhas1, colunas1, linhas2, colunas2))
            {
                matrix_sub(linhas1, colunas1, matriz1, linhas2, colunas2, matriz2, matrizFinal);
                matrix_print(linhas1, colunas1, matrizFinal);
            }

            else 
            {
                printf ("Erro: as dimensoes da matriz nao correspondem\n\n");
                continue;                
            }
        }

        if (opcao == 3)
        {
            if (possible_matrix_multiply(colunas1, linhas2))
            {
                matrix_multiply(linhas1, colunas1, matriz1, linhas2, colunas2, matriz2, matrizFinalMultiplicacao);
                matrix_print(linhas1, colunas2, matrizFinalMultiplicacao);
            }

            else 
            {
                printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n\n");
                continue;
            }
        }

        if (opcao == 4)
        {
            scanf ("%d", &escalar);
            scanf ("%d", &opcao);

            if (opcao == 1)
            {
                scalar_multiply(linhas1, colunas1, matriz1, escalar);
                matrix_print(linhas1, colunas1, matriz1);
            }

            else if (opcao == 2)
            {
                scalar_multiply(linhas2, colunas2, matriz2, escalar);
                matrix_print(linhas2, colunas2, matriz2);
            }
        }

        if (opcao == 5)
        {
            transpose_matrix(linhas1, colunas1, matriz1, matrizFinal);
            matrix_print(colunas1, linhas1, matrizFinal);

            transpose_matrix(linhas2, colunas2, matriz2, matrizFinal);
            matrix_print(colunas2, linhas2, matrizFinal);
        }

    }
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

    executaMenu(linhas1, colunas1, matriz1, linhas2, colunas2, matriz2);

    return 0;
}