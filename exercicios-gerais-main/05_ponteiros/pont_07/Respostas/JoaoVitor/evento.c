#include <stdio.h>
#include "string.h"
#include "evento.h"

#define MAX_EVENTOS 10

//Estrutura para representar um evento no calendário. 
//typedef struct {
//   char nome[50]; // Nome do evento.
//    int dia;       // Dia do evento.
//    int mes;       // Mês do evento.
//    int ano;       // Ano do evento.
//} Evento;

/**
 * Cadastra um novo evento no calendário e o insere na próxima posição do array.
 *
 * @param eventos Array de eventos onde o novo evento será cadastrado.
 * @param numEventos Ponteiro para o número atual de eventos cadastrados.
 */
void cadastrarEvento(Evento* eventos, int* numEventos)
{
    if (*numEventos >= MAX_EVENTOS)
    {
        printf ("Limite de eventos atingido!\n");
        return;
    }

    scanf (" %49[^\n]", eventos[*numEventos].nome);
    scanf ("%d %d %04d", &eventos[*numEventos].dia, &eventos[*numEventos].mes, &eventos[*numEventos].ano);
    printf ("Evento cadastrado com sucesso!\n");
    (*numEventos)++;
}


/**
 * Exibe todos os eventos cadastrados no calendário.
 *
 * @param eventos Array de eventos a serem exibidos.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void exibirEventos(Evento* eventos, int* numEventos)
{
    if (*numEventos == 0)
    {
        printf ("Nenhum evento cadastrado.\n");
        return;
    }

    printf ("Eventos cadastrados:\n");

    for (int i = 0; i < *numEventos; i++) 
    {
        printf("%d - %s - %d/%d/%04d\n", i, eventos[i].nome,
            eventos[i].dia, eventos[i].mes, 
            eventos[i].ano);
    }
}

/**
 * Troca a data de um evento específico no calendário.
 *
 * @param eventos Array de eventos onde o evento será modificado.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void trocarDataEvento(Evento* eventos, int* numEventos)
{
    int indice;

    
    scanf ("%d", &indice);
    
    if (indice < 0 || indice >= *numEventos)
    {
        printf("Indice invalido!\n");
        return;
    }

    scanf ("%d %d %04d", &eventos[indice].dia, &eventos[indice].mes, 
            &eventos[indice].ano);

    printf ("Data modificada com sucesso!\n");
}

/**
 * Troca a posição de dois eventos, a partir do índice, dentro do array de eventos.
 *
 * @param eventos Array de eventos onde a troca será realizada.
 * @param indiceA Ponteiro para o primeiro índice.
 * @param indiceB Ponteiro para o segundo índice.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void trocarIndicesEventos(Evento* eventos, int* indiceA, int* indiceB, int* numEventos)
{
    if ((*indiceA >= *numEventos|| *indiceB >= *numEventos) || (*indiceA < 0 || *indiceB < 0))
    {
        printf ("Indices invalidos!\n");
        return;
    }

    Evento temp = eventos[*indiceA];
    eventos[*indiceA] = eventos[*indiceB];
    eventos[*indiceB] = temp;

    printf ("Eventos trocados com sucesso!\n");
}
