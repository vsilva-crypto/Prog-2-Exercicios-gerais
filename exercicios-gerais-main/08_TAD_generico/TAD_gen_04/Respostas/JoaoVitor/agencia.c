#include <stdio.h>
#include <stdlib.h>
#include "agencia.h"
#include "conta.h"
#include "vector.h"

/**
 * @brief Estrutura para representar uma agência bancária.
 */
struct Agencia 
{
    int numAgencia;
    char nomeAgencia[51];
    Vector *contas;
};

/**
 * @brief Função para criar uma nova agência bancária.
 * @return Um ponteiro para a nova agência bancária criada. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tAgencia *CriaAgencia()
{
    tAgencia *agencia = malloc (sizeof(tAgencia));

    if (agencia == NULL)
        return NULL;

    agencia->contas = VectorConstruct();

    return agencia;
}

/**
 * @brief Função para destruir uma agência bancária.
 * @param agencia A agência bancária a ser destruída.
 */
void DestroiAgencia(DataType agencia)
{
    tAgencia *agen = (tAgencia *)agencia;
    VectorDestroy(agen->contas, DestroiConta);
    free(agen);
}

/**
 * @brief Função para ler uma agência bancária no formato "numero;nome".
 * @param agencia A agência bancária a ser lida.
 */
void LeAgencia(tAgencia *agencia)
{
    scanf (" %d;%50[^\n]", &agencia->numAgencia, agencia->nomeAgencia);
}

/**
 * @brief Função para adicionar uma conta bancária a uma agência bancária.
 * @param agencia A agência bancária.
 * @param conta A conta bancária a ser adicionada.
 */
void AdicionaConta(tAgencia *agencia, tConta *conta)
{
    VectorPushBack(agencia->contas, conta);
}

/**
 * @brief Função para comparar um número de agência bancária com uma agência bancária.
 * @param numAgencia O número da agência bancária.
 * @param agencia2 A agência bancária a ser comparada.
 * @return 1 se os números forem iguais, 0 caso contrário.
 */
int ComparaAgencia(int numAgencia, tAgencia *agencia2)
{
    return agencia2->numAgencia == numAgencia;
}

/**
 * @brief Função para obter o saldo médio das contas de uma agência bancária.
 * @param agencia A agência bancária.
 * @return O saldo médio das contas da agência.
 */
float GetSaldoMedioAgencia (tAgencia *agencia)
{
    int tam = VectorSize(agencia->contas);
    float saldo = 0;
    tConta *contaAtual;

    for (int i = 0; i < tam; i++)
    {
        contaAtual = VectorGet(agencia->contas, i);
        saldo += GetSaldoConta(contaAtual);
    }
    
    return saldo / tam;
}

/**
 * @brief Função para imprimir os dados de uma agência bancária (nome, número, número de contas cadastradas e saldo médio).
 * @param agencia A agência bancária.
 */
void ImprimeDadosAgencia(tAgencia *agencia)
{
    float saldo = GetSaldoMedioAgencia(agencia);
    int qtdContas = VectorSize(agencia->contas);

    printf ("    Nome: %s\n", agencia->nomeAgencia);
    printf ("    Numero: %d\n", agencia->numAgencia);
    printf ("    Numero de contas cadastradas: %d\n", qtdContas);
    printf ("    Saldo médio: R$%.2f\n\n", saldo);
}
