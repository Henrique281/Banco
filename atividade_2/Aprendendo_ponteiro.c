#include <stdio.h>

// Correção do tipo de retorno para void, já que a função apenas imprime o vetor
void Mostrar_vetor(int *v)
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", v[i]);
    }
}

int main(int argc, char const *argv[])
{
    int vetor[5]; // Correção do tamanho do vetor para 5
    int *ponteiro = vetor;

    *ponteiro = 30;
    *(ponteiro + 1) = 40;
    *(ponteiro + 2) = 70;
    *(ponteiro + 3) = 10;
    *(ponteiro + 4) = 20;

    Mostrar_vetor(vetor); // Chamada correta da função Mostrar_vetor, passando o vetor como argumento
    printf("\n");

    int i = 5;

    // Usando o operador pós-incremento (i++)
    int j = i++; // j recebe o valor atual de i (5), depois i é incrementado para 6
    printf("Usando i++:\n");
    printf("j = %d\n", j);   // Saída: j = 5
    printf("i = %d\n\n", i); // Saída: i = 6

    // Reinicializando i para 5
    i = 5;

    // Usando o operador pré-incremento (++i)
    int k = ++i; // i é incrementado para 6 antes de ser atribuído a k
    printf("Usando ++i:\n");
    printf("k = %d\n", k); // Saída: k = 6
    printf("i = %d\n", i); // Saída: i = 6

    return 0;
}
