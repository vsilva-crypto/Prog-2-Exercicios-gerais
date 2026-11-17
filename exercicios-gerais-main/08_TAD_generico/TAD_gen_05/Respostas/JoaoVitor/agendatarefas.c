#include <stdio.h>
#include <stdlib.h>
#include "agendatarefas.h"

typedef struct
{
    int prioridade;
    void *tarefa;
    void (*executa)(void*);
    void (*destroi)(void*);
} tItem;

struct agendatarefas
{
    tItem *itens;
    int capacidade;
    int qtdAtual;
};

/**
 * @brief Cria uma variável para um tipo genérico que representa uma Agenda de Tarefas
 *
 * @param numElem A quantidade de tarefas que serão armazenadas no agendador
 *
 * @return Um ponteiro para a agenda de tarefas
 */
tAgendaTarefas* CriaAgendaDeTarefas(int numElem)
{
    tAgendaTarefas *tar = malloc(sizeof(tAgendaTarefas));

    if (tar == NULL)
        exit(1);

    tar->itens = malloc(numElem * sizeof(tItem));

    if (tar->itens == NULL)
        exit(1);

    tar->capacidade = numElem;
    tar->qtdAtual = 0;

    return tar;
}

/**
 * @brief Destroi a agenda de tarefas (libera a memória)
 *
 * @param tar - A agenda que terá seu conteúdo liberado/destruído
 */
void DestroiAgendaDeTarefas(tAgendaTarefas* tar)
{
    if (tar != NULL)
    {
        for (int i = 0; i < tar->qtdAtual; i++)
        {
            if (tar->itens[i].tarefa != NULL)
                tar->itens[i].destroi(tar->itens[i].tarefa);
        }

        free(tar->itens);
        free(tar);
    }
}

/**
 * @brief Cadastra uma tarefa em um agendador de tarefas
 *
 * @param tar - Pointeiro para a agenda de tarefas
 * @param prioridade - Prioridade de execução da nova tarefa
 * @param tarefa - Ponteiro para nova tarefa a ser executada
 * @param executa - Ponteiro para função (callback) que será chamada quando for a hora de executar a tarefa
 * @param destroi - Ponteiro para função (callback) que será chamada quando for a hora de destruir a tarefa (liberar a memória)
 *
 */
void CadastraTarefaNaAgenda(tAgendaTarefas* tar, int prioridade, void *tarefa, void (*executa)(void*), void (*destroi)(void*) )
{
    if (tar == NULL || tar->qtdAtual >= tar->capacidade)
        return;

    int pos = tar->qtdAtual;
    tar->itens[pos].prioridade = prioridade;
    tar->itens[pos].tarefa = tarefa;
    tar->itens[pos].executa = executa;
    tar->itens[pos].destroi = destroi;

    tar->qtdAtual++;
}   

/**
 * @brief Executa as tarefas que estão salvas na agenda de tarefas passada como parâmetro.
 *
 * @param tar Agenda de tarefas
 *
 */
void ExecutarTarefasDaAgenda(tAgendaTarefas* tar)
{
    if (tar == NULL)
        return;

    for (int i = 1; i < tar->qtdAtual; i++)
    {
        tItem chave = tar->itens[i];
        int j = i - 1;

        while (j >= 0 && tar->itens[j].prioridade < chave.prioridade)
        {
            tar->itens[j + 1] = tar->itens[j];
            j--;
        }
        tar->itens[j + 1] = chave;
    }

    for (int i = 0; i < tar->qtdAtual; i++)
    {
        tar->itens[i].executa(tar->itens[i].tarefa);
        tar->itens[i].destroi(tar->itens[i].tarefa);
        tar->itens[i].tarefa = NULL; // Evita double free em DestroiAgendaDeTarefas
    }
    tar->qtdAtual = 0;
}

