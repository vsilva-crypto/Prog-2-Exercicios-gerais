#include <stdio.h>
#include <stdlib.h>
#include "banco.h"
#include "agencia.h"
#include "conta.h"

int main ()
{
    tBanco *banco = CriaBanco();
    LeBanco(banco);
    char opcao;

    while(1)
    {
        scanf ("%c", &opcao);

        switch (opcao)
        {
            case 'A':
                tAgencia *agencia = CriaAgencia();
                LeAgencia(agencia);
                AdicionaAgencia(banco, agencia);
                break;
            
            case 'C':
                tConta *conta = CriaConta();
                LeConta(conta);
                int numAgencia;
                scanf ("%d", &numAgencia);
                InsereContaBanco(banco, numAgencia, conta);       

            default:
                break;
        }

        if (opcao == 'F')
            break;
    }

    ImprimeRelatorioBanco(banco);
    DestroiBanco(banco);

    return 0;
}