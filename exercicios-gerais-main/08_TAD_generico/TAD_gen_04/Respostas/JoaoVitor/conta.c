#include <stdio.h>
#include <stdlib.h>
#include "conta.h"
#include "vector.h"

/**
 * @brief Estrutura para representar uma conta bancária.
 */
struct Conta
{
    int numConta;
    char nomeCliente[51];
    float saldo;
};

/**
 * @brief Função para criar uma nova conta bancária.
 * @return Um ponteiro para a nova conta bancária criada. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tConta *CriaConta()
{
    tConta *conta = malloc(sizeof(tConta));

    if (conta == NULL)
        exit(1);

    return conta;
}

/**
 * @brief Função para destruir uma conta bancária.
 * @param conta A conta bancária a ser destruída.
 */
void DestroiConta(DataType conta)
{
    free((tConta *)conta);
}

/**
 * @brief Função para ler uma conta bancária no formato "numero;nome do cliente;saldo inicial".
 * @param conta A conta bancária a ser lida.
 */
void LeConta(tConta *conta)
{
    scanf ("%d;%50[^;];%f", &conta->numConta, conta->nomeCliente, &conta->saldo);
}

/**
 * @brief Função para obter o saldo de uma conta bancária.
 * @param conta A conta bancária.
 * @return O saldo da conta bancária.
 */
float GetSaldoConta(tConta *conta)
{
    return conta->saldo;
}
