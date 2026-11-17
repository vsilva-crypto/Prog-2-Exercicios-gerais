#include <stdlib.h>
#include "vector.h"

typedef void *data_type; // void pointer

struct Vector
{
    data_type *vetor;
    int qtd;
};

/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct()
{
    Vector *vetor = malloc(sizeof(Vector));

    if (vetor == NULL)
        exit(1);

    vetor->vetor = NULL;
    vetor->qtd = 0;

    return vetor;
}

/**
 * @brief Adiciona um elemento no final do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, data_type val)
{
    v->vetor = realloc (v->vetor, (v->qtd + 1) * sizeof(data_type));
    v->vetor[v->qtd] = val;
    v->qtd++;
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return data_type Elemento do vetor
*/
data_type VectorGet(Vector *v, int i)
{
    return v->vetor[i];
}

/**
 * @brief Retorna o tamanho do vetor
 * 
 * @param v Ponteiro para o vetor
 * @return int Tamanho do vetor
*/
int VectorSize(Vector *v)
{
    return v->qtd;
}

/**
 * @brief Libera a memória alocada para o vetor
 * 
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
*/
void VectorDestroy(Vector *v, void (*destroy)(data_type))
{
    for (int i = 0; i < v->qtd; i++)
        destroy(v->vetor[i]);

    free(v->vetor);
    free(v);
}