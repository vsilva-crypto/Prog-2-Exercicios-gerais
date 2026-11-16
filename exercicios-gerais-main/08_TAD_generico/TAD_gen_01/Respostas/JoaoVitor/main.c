#include <stdio.h>
#include "tadgen.h"

int main ()
{
    int tipo, quantidade; 
    tGeneric *generico;
    
    printf ("tad_gen_01\n");
    printf ("Digite o tipo e numero de elementos:");
    scanf ("%d %d", &tipo, &quantidade);

    generico = CriaGenerico (tipo, quantidade);

    LeGenerico(generico);
    ImprimeGenerico(generico);

    DestroiGenerico(generico);

    return 0;
}