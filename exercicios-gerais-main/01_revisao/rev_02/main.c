#include <stdio.h> 

int main ()
{
    int qtdLinhas, i, j, valorAtual = 1;
    
    scanf ("%d", &qtdLinhas);

    for (i = 0; i < qtdLinhas; i++)
    {
        for (j = 0; j <= i; j++)
        {
            printf ("%d ", valorAtual);
            valorAtual++;
        }

        printf ("\n");
    }

    return 0;
}