/**
 * @file banco.h
 * @brief Este arquivo contém a declaração da estrutura tBanco e suas funções relacionadas.
 */

#include <stdio.h>
#include <stdlib.h>
#include "banco.h"
#include "agencia.h"
#include "vector.h"

/**
 * @brief Estrutura para representar um banco.
 */
struct Banco
{
    char nomeBanco[51];
    Vector *agencias;     
};

/**
 * @brief Função para criar um novo banco.
 * @return Um ponteiro para o novo banco criado. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tBanco *CriaBanco()
{
    tBanco *banco = malloc (sizeof(tBanco));

    if (banco == NULL)
        exit(1);

    banco->agencias = VectorConstruct();

    return banco;
}

/**
 * @brief Função para destruir um banco.
 * @param banco O banco a ser destruído.
 */
void DestroiBanco(tBanco *banco)
{
    VectorDestroy(banco->agencias, DestroiAgencia);
    free(banco);
}

/**
 * @brief Função para ler o nome de um banco.
 * @param banco O banco a ser lido.
 */
void LeBanco(tBanco *banco)
{
    scanf ("%50[^\n]", banco->nomeBanco);
}

/**
 * @brief Função para adicionar uma agência a um banco.
 * @param banco O banco.
 * @param agencia A agência a ser adicionada.
 */
void AdicionaAgencia(tBanco *banco, tAgencia *agencia)
{
    VectorPushBack(banco->agencias, agencia);
}

/**
 * @brief Função para inserir uma conta em uma agência pertencente ao banco.
 * @param banco O banco.
 * @param numAgencia O número da agência.
 * @param cliente A conta a ser inserida.
 * @pre A agência deve pertencer ao banco.
*/
void InsereContaBanco(tBanco *banco, int numAgencia, tConta *cliente)
{
    int qtd = VectorSize(banco->agencias);
    tAgencia *agenciaAtual;

    for (int i = 0; i < qtd; i++)
    {
        agenciaAtual = VectorGet(banco->agencias, i);

        if (ComparaAgencia(numAgencia, agenciaAtual))
        {
            AdicionaConta(agenciaAtual, cliente);
            break;
        }
    }
}

/**
 * @brief Função para imprimir o relatório de um banco, com o nome do banco e a lista de agências.
 * @param banco O banco.
 */
void ImprimeRelatorioBanco(tBanco *banco)
{
    int qtdAgen = VectorSize(banco->agencias);
    tAgencia *agenciaAtual;

    printf ("%s\n", banco->nomeBanco);
    printf ("Lista de agencias:\n");

    for (int i = 0; i < qtdAgen; i++)
    {
        agenciaAtual = VectorGet(banco->agencias, i);
        ImprimeDadosAgencia(agenciaAtual);
    }
}