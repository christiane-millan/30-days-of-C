#include <stdio.h>
 
long factorial_iterativo(int);
long factorial_recursivo(int);

int main()
{
    int n;
    scanf("%d", &n);
    long r = factorial_iterativo(n);
    printf("Factorial (iterativo) de %d: %ld\n", n, r);
    printf("Factorial (recursivo) de %d: %ld\n", n, factorial_recursivo(n));

    return 0;
}

long factorial_iterativo(int x)
{
    long f = 1;
    for (int i = 2; i <= x; i++)
    {
        f *= i;
    }
    return f;
}

long factorial_recursivo(int x)
{
    if(x == 0 || x == 1)
        return 1;
    else
        return x * factorial_recursivo(x - 1);
}