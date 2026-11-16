#include <stdio.h>
#include <stdlib.h>
#include "pacote.h"

struct pacote 
{
    void *vetor;
    int tam;
    int soma;
    Type tipo; 
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar um pacote a ser transmitido
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tPacote* CriaPacote(Type type, int numElem)
{
    tPacote *pacote = (tPacote *)malloc (sizeof (tPacote));

    if (pacote == NULL)
        return NULL;

    pacote->tam = numElem;
    pacote->tipo = type;
    pacote->soma = 0;

    switch (type)
    {
        case CHAR:
            pacote->vetor = malloc (numElem * sizeof (char));
            break;
        
        case INT: 
            pacote->vetor = malloc (numElem * sizeof (int));
            break;
            
        default:
            break;
    }

    return pacote;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param pac - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiPacote(tPacote* pac)
{
    free (pac->vetor);
    free (pac);
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param pac - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LePacote(tPacote* pac)
{
    switch (pac->tipo)
    {
        case CHAR:
            for (int i = 0; i < pac->tam; i++)
                    scanf (" %c", (char *)pac->vetor + i);
            break;
        
        case INT:
            for (int i = 0; i < pac->tam; i++)
                scanf ("%d", (int *)pac->vetor + i);
            break;

        default:
            break;
    }
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param pac - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimePacote(tPacote* pac)
{
    switch (pac->tipo)
    {
        case CHAR:
            for (int i = 0; i < pac->tam; i++)
                printf ("%c\n", *((char *)pac->vetor + i));
            break;
        
        case INT: 
            for (int i = 0; i < pac->tam; i++)
                printf ("\n", *((int *)pac->vetor + i));
            break;
            
        default:
            break;
    }
}

/**
 * @brief Calcula a soma de verificacao de um pacote e a armazena internamente
 *
 * @param pac - O vetor genérico que terá sua soma de verificacao calculada
 */
void CalculaSomaVerificacaoPacote(tPacote* pac)
{
    switch (pac->tipo)
    {
        case CHAR:
            for (int i = 0; i < pac->tam; i++)
                pac->soma += ((char *)pac->vetor)[i];
            break;
        
        case INT:
            for (int i = 0; i < pac->tam; i++)
                pac->soma += ((int *)pac->vetor)[i];
            break;
            
        default:
            break;
    }
}
