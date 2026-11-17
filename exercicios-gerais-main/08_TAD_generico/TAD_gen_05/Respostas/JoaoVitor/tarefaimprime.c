#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tarefaimprime.h"

struct impr 
{
    char *msg;
};

/**
 * @brief Cria uma tarefa do tipo impressão em tela
 * 
 * @param msg - A mensagem que deve ser impressa em tela
 *
 * @return Um ponteiro para a tarefa criada
 */
tImpr* CriaTarefaImprimir(char *msg)
{
    tImpr *mensg = malloc(sizeof(tImpr));

    if (mensg == NULL)
        exit(1);

    mensg->msg = malloc((strlen(msg) + 1) * sizeof(char));

    if (mensg->msg == NULL)
        exit(1);

    strcpy(mensg->msg, msg);

    return mensg;
}

/**
 * @brief Função que executa uma tarefa de impressão em tela
 *
 * @param imp - Ponteiro para a tarefa a ser executada
 *
 */
void ExecutaTarefaImprimir(void *imp)
{
    tImpr *impr = (tImpr*) imp;
    printf ("\n%s\n", impr->msg);
}

/**
 * @brief Função que destrói (libera a memória) uma tarefa de impressão em tela
 *
 * @param imp - Ponteiro para a tarefa a ser destruída
 *
 */
void DestroiTarefaImprimir(void *imp)
{
    tImpr *impr = (tImpr *) imp;
    free(impr->msg);
    free(impr);
}