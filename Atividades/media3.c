#include <stdio.h>

#define N 4

float Calculodamedia(float *notas, float *pesos, int n) {
    double soma = 0;
    double somaPesos = 0;

    for (int i = 0; i < n; i++) {
        soma += notas[i] * pesos[i];
        somaPesos += pesos[i];
    }

    float media = soma / somaPesos;

    return media;
}

int main() {
    float notas[N];
    float pesos[N] = {2, 3, 4, 1};
    float exame = 0;

    for (int i = 0; i < N; i++) {
        scanf("%f", &notas[i]);
    }

    float media = Calculodamedia(notas, pesos, N);

    printf("Media: %.1f\n", media);

    if (media >= 7.0) {
        printf("Aluno aprovado.\n");
    } else if (media < 5.0) {
        printf("Aluno reprovado.\n");
    } else {
        printf("Aluno em exame.\n");
        scanf("%f", &exame);
        printf("Nota do exame: %.1f\n", exame);

        media = (media + exame) / 2;

        if (media >= 5.0) {
            printf("Aluno aprovado.\n");
        } else {
            printf("Aluno reprovado.\n");
        }
        printf("Media final: %.1f\n", media);
    }

    return 0;
}