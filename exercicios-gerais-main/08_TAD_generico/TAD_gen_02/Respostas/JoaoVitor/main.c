#include <stdio.h>
#include "gerenciadorpacotes.h"
#include "pacote.h"

void imprimeMenu()
{
    printf ("Escolha uma opcao:\n");
    printf ("	(1) Cadastrar um novo pacote\n");
    printf ("	(2) Imprimir um pacote especifico\n");
    printf ("	(3) Imprimir todos os pacotes e sair\n");
}

int main ()
{
    int opcao, tam, tipo, idx;
    tPacote *pacote;
    tGerenciador *geren;

    geren = CriaGerenciador();

    printf ("\n");

    while (1)
    {
        imprimeMenu();
        scanf ("%d", &opcao);

        switch (opcao)
        {
            case 1:
                printf ("Digite o tipo (0-char, 1-int) e o numero de elementos do pacote/mensagem:\n");
                scanf ("%d %d", &tipo, &tam);

                if (tipo != 1 && tipo != 0)
                {
                    printf ("Digite um tipo valido!\n");
                    continue;
                }

                pacote = CriaPacote(tipo, tam);
                LePacote(pacote);
                CalculaSomaVerificacaoPacote(pacote);
                AdicionaPacoteNoGerenciador(geren, pacote);
                break;
            
            case 2:
                scanf ("%d", &idx);
                ImprimirPacoteNoIndice(geren, idx);
                break;

            case 3:
                ImprimirTodosPacotes(geren);
                break;

            default:
                break;
        }
        
        if (opcao == 3)
            break;
    }

    DestroiGerenciador(geren);
    
    return 0;
}