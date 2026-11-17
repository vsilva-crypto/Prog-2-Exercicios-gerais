#include <stdio.h>
#include "vector.h"
#include "aluno.h"
#include "relatorio.h"

/**
 * @brief Imprime o relatorio de uma coleção de alunos.
 * O relatorio deve possuir a media das notas, porcentagem de alunos aprovados e porcentagem de cada gênero.
 * 
 * @param alunos Ponteiro para o vetor de alunos.
*/
void ImprimeRelatorio(Vector *alunos)
{
    int qtdMas = 0, qtdFem = 0, outro = 0;
    int qtd = VectorSize(alunos); 
    float soma = 0, media, aprovados = 0;

    for (int i = 0; i < qtd; i++)
    {
        tAluno *alunoAtual = VectorGet(alunos, i);

        soma += GetNotaAluno(alunoAtual);

        if (GetNotaAluno(alunoAtual) >= 6)
            aprovados++;

        if (GetGeneroAluno(alunoAtual) == 'M' || GetGeneroAluno(alunoAtual) == 'm')
            qtdMas++;

        else if (GetGeneroAluno(alunoAtual) == 'F' || GetGeneroAluno(alunoAtual) == 'f')
            qtdFem++;     

        else if (GetGeneroAluno(alunoAtual) == 'O' || GetGeneroAluno(alunoAtual) == 'o')
            outro++;
    }

    media = soma / qtd;
    float porcentagemApv = ((float)aprovados / qtd) * 100;
    float porcentagemMas = ((float)qtdMas / qtd) * 100;
    float porcentagemFem = ((float)qtdFem / qtd) * 100;
    float porcentagemOutro = ((float)outro / qtd) * 100;

    printf ("Media das notas: %.2f\n", media);
    printf ("Porcentagem de alunos aprovados: %.2f%%\n", porcentagemApv);
    printf ("Porcentagem de cada genero:\n");
    printf ("Masculino: %.2f%%\n", porcentagemMas);
    printf ("Feminino: %.2f%%\n", porcentagemFem);
    printf ("Outro: %.2f%%\n", porcentagemOutro);
}