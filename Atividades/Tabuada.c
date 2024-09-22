#include <stdio.h>

int main() {
    int numero = 0;

    scanf("%d", &numero);

    if (2 < numero && numero < 1000) {
        int resultado = 0;

        for (int i = 1; i <= 10; i++) {
            int mult = i;
            resultado = mult * numero;
            printf("%d x %d = %d\n", i, numero, resultado);
        }

}
}
