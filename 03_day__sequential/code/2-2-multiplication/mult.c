#include <stdio.h>

int main()
{
    int number;
    int result;

    printf("Ingresar un número entero:");
    scanf("%d", &number);

    result = number * 2;

    printf("El resultado de multiplicar %d por dos es: %d\n", 
    number, result);

    return 0;
}