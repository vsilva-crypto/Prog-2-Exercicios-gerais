#include <stdio.h>
#include <string.h>
#include "tDepartamento.h"

#define STRING_MAX 50

//typedef struct departamento {
//    char curso1[STRING_MAX];
//    char curso2[STRING_MAX];
//    char curso3[STRING_MAX];
//    char diretor[STRING_MAX];
//    char nome[STRING_MAX];
//    int m1, m2, m3;
//} tDepartamento;

/**
 * @brief Cria um departamento com os dados passados via parâmetro
 *
 *
 * @param *curso1 Ponteiro para string que contém o nome do primeiro curso do departamento
 * @param *curso2 Ponteiro para string que contém o nome do segundo curso do departamento
 * @param *curso3 Ponteiro para string que contém o nome do terceiro curso do departamento
 * @param *nome Ponteiro para string que contém o nome do departamento
 * @param m1 Nota do primeiro curso (curso1)
 * @param m2 Nota do segundo curso (curso2)
 * @param m3 Nota do terceiro curso (curso3)
 * @param *diretor Ponteiro para string que contém o nome do diretor/chefe do departamento
 */
tDepartamento CriaDepartamento( char *curso1, char *curso2, char *curso3,
                                char *nome, int m1, int m2, int m3, char *diretor )
{
    tDepartamento departamento;

    strcpy(departamento.curso1, curso1);
    strcpy(departamento.curso2, curso2);
    strcpy(departamento.curso3, curso3);
    strcpy(departamento.nome, nome);
    strcpy(departamento.diretor, diretor);

    departamento.m1 = m1;
    departamento.m2 = m2;
    departamento.m3 = m3;

    return departamento;
}

/**
 * @brief Imprime os atributos de um departamento em tela
 *
 * @param depto - Um departamento que terá seus dados impressos em tela
 */

void ImprimeAtributosDepartamento(tDepartamento depto)
{
    printf ("\nDepartamento: %s\n", depto.nome);
    printf ("    Diretor: %s\n", depto.diretor);
    printf ("    1o curso: %s\n", depto.curso1);
    printf ("    Media do 1o curso: %d\n", depto.m1);   
    printf ("    2o curso: %s\n", depto.curso2);
    printf ("    Media do 2o curso: %d\n", depto.m2);
    printf ("    3o curso: %s\n",depto.curso3);
    printf ("    Media do 3o curso: %d\n", depto.m3); 
}

/**
 * @brief Ordena os departamentos de acordo com as médias das notas de cada um dos seus três cursos (da maior para a menor).
 *
 * @param *vetor_deptos - Ponteiro para um vetor de departamentos
 * @param num_deptos - O número de departamentos contidos no vetor_deptos
 */
void OrdenaDepartamentosPorMedia(tDepartamento *vetor_deptos, int num_deptos)
{
    float soma = 0.0; 
    int maior = 0;
    tDepartamento temp;

    for (int i = 0; i < num_deptos; i++)
    {
        maior = i;

        for (int j = i + 1; j < num_deptos; j++)
        {
            if (((vetor_deptos[j].m1 + vetor_deptos[j].m2 + vetor_deptos[j].m3) / 3.0) >
            ((vetor_deptos[maior].m1 + vetor_deptos[maior].m2 + vetor_deptos[maior].m3) / 3.0))
            {
                maior = j;
            }
        }

        if (maior != i)
        {
            temp = vetor_deptos[i];
            vetor_deptos[i] = vetor_deptos[maior];
            vetor_deptos[maior] = temp;
        }
    }
    
    for (int i = 0; i < num_deptos; i++)
    {
        soma += (vetor_deptos[i].m1 + vetor_deptos[i].m2 + vetor_deptos[i].m3) / 3.0;
        ImprimeAtributosDepartamento(vetor_deptos[i]);
        printf ("    Media dos cursos: %.2f", soma);
        soma = 0;
    }
}
