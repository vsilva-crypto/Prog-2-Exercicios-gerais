#include <stdio.h>
#include "tDepartamento.h"

int main () 
{
    int qtdDept;
    char curso1[STRING_MAX], curso2[STRING_MAX], curso3[STRING_MAX];
    char diretor[STRING_MAX], nome[STRING_MAX];
    int m1, m2, m3;

    scanf ("%d", &qtdDept);

    tDepartamento departamentos[qtdDept];

    for (int i = 0; i < qtdDept; i++)
    {
        scanf (" %49[^\n]", nome);
        scanf (" %49[^\n]", diretor);
        scanf (" %49[^\n]", curso1);
        scanf (" %49[^\n]", curso2);
        scanf (" %49[^\n]", curso3);
        scanf ("%d %d %d", &m1, &m2, &m3);
        
        if (m1 < 0 || m2 < 0 || m3 < 0)
        {
            printf ("\nDigite um departamento com médias válidas");
            i--;
            continue;
        }

        departamentos[i] = CriaDepartamento(curso1, curso2, curso3, 
            nome, m1, m2, m3, diretor);
    }

    OrdenaDepartamentosPorMedia(departamentos, qtdDept);

    for (int i = 0; i < qtdDept; i++)
        ImprimeAtributosDepartamento(departamentos[i]);
}