#include <stdio.h>
#define TAM_MAX 50

typedef struct 
{
    int linhas, colunas;
    int mapa[TAM_MAX][TAM_MAX];
} mapa;

typedef struct
{
    int linhaInicial, linhaFinal;
    int colunaInicial, colunaFinal;
} jogador;

mapa leDadosDoMapa()
{
    mapa mapa;
    scanf ("%d %d", &mapa.linhas, &mapa.colunas);
    return mapa;
}

mapa inicializaMapa(mapa mapa)
{
    int i, j;
    for (i = 0; i < mapa.linhas; i++)
        for (j = 0; j < mapa.colunas; j++)
            scanf ("%d", &mapa.mapa[i][j]);

    return mapa;
}

int main ()
{
    
}