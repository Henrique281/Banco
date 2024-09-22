#include <stdio.h>

void Transformar(int totalsegundos) {
    int horas, minutos, segundos; 

    horas = totalsegundos / 3600;
    minutos = (totalsegundos % 3600) / 60;
    segundos = totalsegundos % 60;

    printf("%d:%d:%d\n", horas, minutos, segundos);
}

int main() {
    int totalsegundos;

    scanf("%d", &totalsegundos);

    Transformar(totalsegundos);

    return 0;
}
