#include <stdio.h>
#define QTD_MAX_LIVROS 1000

void leListaDeLivros(int lista[], int quantidade)
{
    int i; 
    for (i = 0; i < quantidade; i++)
        scanf ("%d", &lista[i]);
}

void verificaLivrosSemCopia(int lista[], int quantidade)
{
    int i, j, k = 0, livroAtual, achouLivro, qtdDeLivros = 0, listaDeCopias[QTD_MAX_LIVROS];

    for (i = 0; i < quantidade; i++)
    {
        livroAtual = lista[i];
        achouLivro = 0;

        for (j = 0; j < quantidade; j++)
        {
            if (livroAtual == lista[j] && j != i)
                achouLivro = 1;
        }

        if (!achouLivro)
        {
            qtdDeLivros++;
            listaDeCopias[k] = livroAtual;
            k++;
        }
    }

    if (qtdDeLivros)
    {
        for (i = 0; i < qtdDeLivros; i++)
            printf ("%d ", listaDeCopias[i]); 
        
        printf ("\n");
    }

    else 
        printf ("NENHUM\n");
}

int main ()
{
    int qtdLivros, listaLivros[QTD_MAX_LIVROS];
    
    scanf("%d", &qtdLivros);
    leListaDeLivros(listaLivros, qtdLivros);
    verificaLivrosSemCopia(listaLivros, qtdLivros);

    return 0;
}