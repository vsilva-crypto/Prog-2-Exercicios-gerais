#include <stdio.h>
#include "string_utils.h"

#define TAM_MAX_STRING 50

void imprimeMenu ()
{
    printf ("1 - Tamanho da string\n");
    printf ("2 - Copiar string\n");
    printf ("3 - Converter string para letras maiusculas\n");
    printf ("4 - Converter string para letras minusculas\n");
    printf ("5 - Imprimir string ao contrario\n");
    printf ("6 - Encerrar o programa\n");
    printf ("Opcao escolhida: \n");
}

void executaMenu (char string[])
{
    int opcao = 0;
    char destString[TAM_MAX_STRING];
    
    while (opcao != 6)
    {
        imprimeMenu();
        scanf ("%d", &opcao);

        switch (opcao)
        {
            case 1:
            printf ("Tamanho da string: %d\n\n", string_length (string));
            break;
        
            case 2:
            string_copy (string, destString);
            printf ("String copiada: %s\n\n", destString);
            break;

            case 3:
            string_upper (string);
            printf ("String convertida para maiusculas: %s\n\n", string);
            break;

            case 4: 
            string_lower (string);
            printf ("String convertida para minusculas: %s\n\n", string);
            break;

            case 5:
            string_reverse (string);
            printf ("String invertida: %s\n\n", string);
            break;
        }
    }
}

int main ()
{
    char string[TAM_MAX_STRING];
    scanf ("%[^\n]", string);

    executaMenu(string);

    return 0;
}