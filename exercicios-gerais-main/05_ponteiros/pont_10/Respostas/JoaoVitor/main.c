#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"

int main ()
{
    int qtdPessoas;

    scanf ("%d", &qtdPessoas);
    tPessoa pessoas[qtdPessoas];

    for (int i = 0; i < qtdPessoas; i++)
    {
        pessoas[i] = CriaPessoa();
        LePessoa(&pessoas[i]);
    }

    AssociaFamiliasGruposPessoas(pessoas, qtdPessoas);

    for (int i = 0; i < qtdPessoas; i++)
        ImprimePessoa(&pessoas[i]);

    return 0;
}