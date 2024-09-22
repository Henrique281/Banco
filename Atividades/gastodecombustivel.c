#include <stdio.h>

int main()
{
    int tempogasto = 0, velocidademedia = 0;
    int consumo = 12;
    

    scanf("%d %d", &tempogasto, &velocidademedia);

    int horas = tempogasto / 3600;
    int distancia = tempogasto * velocidademedia;
    int litros = distancia / consumo;

    printf("%d", litros);


}



