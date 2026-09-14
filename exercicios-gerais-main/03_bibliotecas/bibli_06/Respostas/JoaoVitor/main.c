#include <stdio.h>
#include "temperature_conversor.h"

int main ()
{
    float temperatura;
    char de, para;

    scanf ("%f %c %c", &temperatura, &de, &para);

    if (de == 'c')
    {
        if (para == 'k')
        {
            temperatura = convert_temperature(temperatura, convert_celsius_to_kelvin);
            printf ("Temperature: %.2fK", temperatura);
        }

        else if (para == 'f')
        {
            temperatura = convert_temperature(temperatura, convert_celsius_to_fahrenheit);
            printf ("Temperature: %.2fFº", temperatura);
        }
    }

    else if (de == 'k')
    {
        if (para == 'c')
        {
            temperatura = convert_temperature(temperatura, convert_kelvin_to_celsius);
            printf ("Temperature: %.2fCº", temperatura);
        }

        else if (para == 'f')
        {
            temperatura = convert_temperature(temperatura, convert_kelvin_to_fahrenheit);
            printf ("Temperature: %.2fFº", temperatura);
        }
    }

    else if (de == 'f')
    {
        if (para == 'c')
        {
            temperatura = convert_temperature(temperatura, convert_fahrenheit_to_celsius);
            printf ("Temperature: %.2fCº", temperatura);
        }

        if (para == 'k')
        {
            temperatura = convert_temperature(temperatura, convert_fahrenheit_to_kelvin);
            printf ("Temperature: %.2fK", temperatura);
        }
    }

    return 0;
}