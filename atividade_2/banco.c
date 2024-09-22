#include <stdio.h>
#include <string.h>
// funções
double Saque(double saldo, double saque)
{
    if (saldo == 0)
    {
        printf("Seu saldo está em 0\n");
    }
    else
    {
        printf("Quanto você quer sacar: ");
        scanf("%lf", &saque);
        if (saque <= saldo)
        {
            saldo -= saque;
        }
        else
        {
            printf("Saldo insuficiente\n");
        }
    }
    return saldo;
}

double Deposito(double saldo, double valor_deposito)
{
    printf("Digite o valor do depósito: ");
    scanf("%lf", &valor_deposito);
    saldo += valor_deposito;
    return saldo;
}

struct Pessoa
{
    char nome[50];
    int senha;
    int numero;
    int tipo_conta;
};

int main(int argc, char const *argv[])
{
    double saldo = 0, sacar = 0, depositar = 0;
    int escolha;
    char continuar;

    struct Pessoa pessoa1;
    strcpy(pessoa1.nome, "Jeferson");
    pessoa1.senha = 123942;
    pessoa1.numero = 58219904;
    pessoa1.tipo_conta = 13;

    do
    {
        printf("\n");
        printf("Escolha uma das opcoes:\n 1- sacar\n 2- depositar\n 3- saldo\n 4- informacoes pessoais\n");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            saldo = Saque(saldo, sacar);
            break; 
        case 2:
            saldo = Deposito(saldo, depositar);
            break;
        case 3:
            printf("saldo: %.2lf\n", saldo);
            break;
        case 4:
            printf("Nome:%s\nSenha:%d\nNumero:%d\nTipo de conta:", pessoa1.nome, pessoa1.senha);
            break;
        default:
            printf("Escolha inválida\n");
            break;
        }

        printf("\n");
        printf("Deseja continuar: Digite S para continuar ou E para sair\n");
        scanf(" %c", &continuar);

    } while (continuar == 'S' || continuar == 's');

    return 0;
}
