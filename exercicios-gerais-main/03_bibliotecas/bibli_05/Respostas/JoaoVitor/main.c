#include <stdio.h>
#include "string_utils.h"

void imprimeMenu()
{
    printf ("1 - Tamanhon da string\n");
    printf ("2 - Copiar string\n");
    printf ("3 - Converter string para letras maiusculas\n");
    printf ("4 - Converter string para letras minusculas\n");
    printf ("5 - Imprimir string ao contrario\n");
    printf ("6 - Encerrar o programa\n");
    printf ("Opcao escolhida: ");
}

int main ()
{
    imprimeMenu();
    return 0;
}