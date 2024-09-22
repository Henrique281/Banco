#include <stdio.h>

int restodadivisao(int n)
{
    for (int i = 1; i <= 10000; i++)
    {
        int resto = i % n;
        if (resto == 2)
        {
            printf("%d\n", i);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    restodadivisao(n);
    return 0;
}