#include <stdio.h>
#include <math.h>

typedef struct
{
    float raio;
    float posX, posY;
} coordenada;

coordenada leCoordenadas()
{
    coordenada coordenadas;
    scanf ("%f %f %f", &coordenadas.posX, &coordenadas.posY, &coordenadas.raio);
    return coordenadas;
}

int verificaSeDisparoAcertou(coordenada alvo, coordenada mira)
{
    float distancia; 

    distancia = sqrt(pow(alvo.posX - mira.posX, 2) + pow(alvo.posY - mira.posY, 2));
    
    return distancia <= (alvo.raio + mira.raio);
}

int main ()
{
    coordenada alvo, mira;

    alvo = leCoordenadas();
    mira = leCoordenadas();
    
    if(verificaSeDisparoAcertou(alvo, mira))
        printf("ACERTOU\n");
    
    else 
        printf ("ERROU\n");

    return 0;
}