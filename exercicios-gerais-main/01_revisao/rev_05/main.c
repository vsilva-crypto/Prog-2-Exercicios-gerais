#include <stdio.h>
#define TAM_MAX 50
#define PRIORIDADE_MOV 4

typedef struct 
{
    int linhas, colunas;
    int mapa[TAM_MAX][TAM_MAX];
} mapa;

typedef struct
{
    int linhaInicial, linhaFinal;
    int colunaInicial, colunaFinal;
    int linhaAtual, colunaAtual;
    char prioridadeMovimento[PRIORIDADE_MOV];
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

jogador lePosicoesIniciaisFinais()
{
    jogador jogador;

    scanf ("%d %d", &jogador.linhaInicial, &jogador.colunaInicial);
    scanf ("%d %d", &jogador.linhaFinal, &jogador.colunaFinal);

    jogador.linhaAtual = jogador.linhaInicial - 1;
    jogador.colunaAtual = jogador.colunaInicial - 1;
    jogador.linhaFinal--;
    jogador.colunaFinal--;

    return jogador;
}

jogador lePrioridadeDeMovimento(jogador jogador)
{
    int i;

    for (i = 0; i < PRIORIDADE_MOV; i++)
        scanf (" %c", &jogador.prioridadeMovimento[i]);
    
    return jogador;
}

void moveJogador(jogador jogador, mapa mapa)
{
    int i, andou, chegouAoFim = 0, conseguiuAndar;

    printf ("(%d,%d) ", jogador.linhaAtual + 1, jogador.colunaAtual + 1);

    while (!chegouAoFim)
    {   

        conseguiuAndar = 0;

        for (i = 0; i < PRIORIDADE_MOV; i++)
        {
            andou = 0;

            if ((jogador.prioridadeMovimento[i] == 'c' || jogador.prioridadeMovimento[i] == 'C') &&   
                jogador.linhaAtual > 0 && mapa.mapa[jogador.linhaAtual - 1][jogador.colunaAtual] == 0)
            {
                mapa.mapa[jogador.linhaAtual][jogador.colunaAtual] = 2;
                jogador.linhaAtual--;
                andou = 1;
            }    

            else if ((jogador.prioridadeMovimento[i] == 'b' || jogador.prioridadeMovimento[i] == 'B') && 
                jogador.linhaAtual < mapa.linhas - 1 && mapa.mapa[jogador.linhaAtual + 1][jogador.colunaAtual] == 0)
            {
                mapa.mapa[jogador.linhaAtual][jogador.colunaAtual] = 2;
                jogador.linhaAtual++;
                andou = 1;
            }

            else if ((jogador.prioridadeMovimento[i] == 'd' || jogador.prioridadeMovimento[i] == 'D') &&
                jogador.colunaAtual < mapa.colunas - 1 && mapa.mapa[jogador.linhaAtual][jogador.colunaAtual + 1] == 0)
            {
                mapa.mapa[jogador.linhaAtual][jogador.colunaAtual] = 2;
                jogador.colunaAtual++;
                andou = 1;
            }

            else if ((jogador.prioridadeMovimento[i] == 'e' || jogador.prioridadeMovimento[i] == 'E') && 
                jogador.colunaAtual > 0 && mapa.mapa[jogador.linhaAtual][jogador.colunaAtual - 1] == 0)
            {
                mapa.mapa[jogador.linhaAtual][jogador.colunaAtual] = 2;
                jogador.colunaAtual--;
                andou = 1;
            }

            if (andou)
            {
                printf ("(%d,%d) ", jogador.linhaAtual + 1, jogador.colunaAtual + 1);

                conseguiuAndar = 1;

                if (jogador.linhaAtual == jogador.linhaFinal && jogador.colunaAtual == jogador.colunaFinal)
                    chegouAoFim = 1;
                
                break;
            }
        }

        if (!conseguiuAndar)
            break;
    }

    printf ("\n");
}

void imprimeTeste(jogador jogador, mapa mapa)
{
    int i, j;

    printf ("TAMANHO DO VETOR - linhas: %d | colunas: %d", mapa.linhas, mapa.colunas);

    printf ("\n\n");

    printf ("MAPA:\n\n");

    for (i = 0; i < mapa.linhas; i++)
    {
        for (j = 0; j < mapa.colunas; j++)
        {
            printf ("%d ", mapa.mapa[i][j]);
        }

        printf("\n");
    }

    printf ("\n\n");

    printf ("PRIORIDADES DE MOVIMENTO:\n");

    for (i = 0; i < PRIORIDADE_MOV; i++)
        printf ("%c", jogador.prioridadeMovimento[i]);

    printf ("\n\n");

    printf ("posição inicial: %d %d\n\n", jogador.linhaInicial, jogador.colunaInicial);
    printf ("posicão final: %d %d\n\n", jogador.linhaFinal, jogador.colunaFinal);
}

int main ()
{
    mapa mapa;
    jogador jogador;

    mapa = leDadosDoMapa();
    mapa = inicializaMapa(mapa);
    jogador = lePosicoesIniciaisFinais();
    jogador = lePrioridadeDeMovimento(jogador);
    moveJogador(jogador, mapa);

    return 0;
}