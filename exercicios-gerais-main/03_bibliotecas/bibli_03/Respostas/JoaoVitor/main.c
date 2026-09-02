#include <stdio.h>
#include "data.h"

typedef struct 
{
    int dia, mes, ano;
} Data;

int main ()
{
    int verificador;
    Data data1, data2;

    scanf ("%02d/%02d/%04d", &data1.dia, &data1.mes, &data1.ano);
    scanf ("%02d/%02d/%04d", &data2.dia, &data2.mes, &data2.ano);

    if (verificaDataValida(data1.dia, data1.mes, data1.ano) && verificaDataValida(data2.dia, data2.mes, data2.ano))
    {
        printf ("Primeira data: ");
        imprimeDataExtenso(data1.dia, data1.mes, data1.ano);
        printf ("\n");

        printf ("Segunda data: ");
        imprimeDataExtenso(data2.dia, data2.mes, data2.ano);
        printf ("\n");

        verificador = comparaData(data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.ano);

        if (verificador == -1)
            printf ("A primeira data eh mais antiga\n");
        
        else if (verificador == 1)
            printf ("A segunda data eh mais antiga\n");
        
        else 
            printf ("As datas sao iguais\n");

        verificador = calculaDiferencaDias(data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.ano);
        
        printf ("A diferenca em dias entre as datas eh: %02d dias\n", verificador);
    }

    else 
        printf ("A primeira e/ou segunda data(s) invalida(s)\n");
}