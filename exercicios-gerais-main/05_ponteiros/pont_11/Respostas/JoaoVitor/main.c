#include <stdio.h>
#include "calculadora.h"

float soma(float n1, float n2)
{
    return n1 + n2;
}

float subtracao(float n1, float n2)
{
    return n1 - n2;
}

float multiplicacao(float n1, float n2)
{
    return n1 * n2;
}

float divisao(float n1, float n2)
{
    return n1 / n2;
}

int main ()
{
    char operador;
    int num1, num2;
    float resultado;
    CalculatoraCallback operacao;

    while (1)
    {
        scanf ("%c", &operador);
        scanf ("%d %d", &num1, &num2);

        switch (operador)
        {
            case 'a':
                operacao = soma;
                resultado = Calcular((float)num1, (float)num2, operacao);
                printf ("%.2f + %.2f = %.2f\n", (float)num1, (float)num2, resultado);
                break;
            
            case 's':
                operacao = subtracao;
                resultado = Calcular((float)num1, (float)num2, operacao);
                printf ("%.2f - %.2f = %.2f\n", (float)num1, (float)num2, resultado);               
                break;
            
            case 'm':
                operacao = multiplicacao;
                resultado = Calcular((float)num1, (float)num2, operacao);
                printf ("%.2f x %.2f = %.2f\n", (float)num1, (float)num2, resultado);
                break;

            case 'd':
                operacao = divisao;
                resultado = Calcular((float)num1, (float)num2, operacao);
                printf ("%.2f / %.2f = %.2f\n", (float)num1, (float)num2, resultado);
                break;
        }

        if (operador == 'f')
            break;
    }

    return 0;
}