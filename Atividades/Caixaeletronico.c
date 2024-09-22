#include <stdio.h>

double CalculoSalario(double x)
{
    double imposto;

    if (x >= 0 && x <= 2000)
    {
        printf("Isento\n");
        imposto = 0.0;
    }
    else if (x > 2000.01 && x <= 3000)
    {
        imposto = (x - 2000.01) * 0.08;
        printf("R$ %.2lf\n", imposto);
    }
    else if (x > 3000 && x <= 4500)
    {
        imposto = 1000.00 * 0.08 + (x - 3000) * 0.18;
        printf("R$ %.2lf\n", imposto);
    }
    else
    {
        imposto = 1000.00 * 0.08 + 1500.00 * 0.18 + (x - 4500.01) * 0.28;
        printf("R$ %.2lf\n", imposto);
    }

    return imposto;
}

int main()
{
    char primeironome[50];
    char segundonome[50];
    int idade, opcao = 0;
    int senha; // Alterado para um inteiro
    char pais[50];
    double saldo = 0, sacar;
    double salario = 0;

    printf("Escreva o primeiro nome: ");
    fgets(primeironome, sizeof(primeironome), stdin);

    printf("Escreva o sobrenome: ");
    fgets(segundonome, sizeof(segundonome), stdin);

    printf("Escreva sua Idade: ");
    scanf("%d", &idade);

    // Limpar o buffer de entrada
    while (getchar() != '\n');

    printf("Digite uma nova senha (até 4 dígitos): ");
    scanf("%d", &senha);

    // Limpar o buffer de entrada
    while (getchar() != '\n');

    printf("Qual sua nacionalidade: ");
    fgets(pais, sizeof(pais), stdin);

    printf("Digite o seu salario: ");
    scanf("%lf", &salario);

    CalculoSalario(salario);

    printf("Escolha uma das opcoes(1-Sacar 2-Depositar 3-Saldo): ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        printf("Quanto deseja sacar? ");
        scanf("%lf", &sacar);
        if (sacar > saldo)
        {
            printf("Saldo insuficiente\n");
        }
        else
        {
            saldo -= sacar;
            printf("Saque realizado com sucesso. Novo saldo: R$ %.2lf\n", saldo);
        }
        break;

    case 2:
        // Implementar lógica para depositar
        break;

    case 3:
        printf("Saldo atual: R$ %.2lf\n", saldo);
        break;

    default:
        printf("Opção inválida\n");
        break;
    }

    printf("\n---------------------------\n\n");

    // Usando printf para formatar a saída diretamente
    printf("Nome Completo: %s %s\n", primeironome, segundonome);
    printf("Idade: %d\n", idade);
    printf("Senha: %d\n", senha);
    printf("Nacionalidade: %s\n", pais);
     printf("Seu salario e: %2lf", salario);

    return 0;
}
