#include <stdio.h>

int main(){
    int n, f;
    int sumatoria = 0;

    printf("Ingresar el valor de n:");
    scanf("%d", &n );

    for ( int j = 1; j <= n - 1; j++)
    {
        f = 1;
        // Aquí empieza el calculo del factorial
        for (int i = j; i > 1; i--)
        {
            f *= i;
        }
        sumatoria = sumatoria + f;
    }
    printf("El resultado es: %d\n", sumatoria);

    return 0;
}