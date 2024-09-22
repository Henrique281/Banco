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

}

int main()
{
    double salario = 0;

    scanf("%lf", &salario);

    CalculoSalario(salario);

    return 0;
}
