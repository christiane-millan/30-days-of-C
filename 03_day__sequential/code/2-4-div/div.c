#include <stdio.h>

int main() 
{
    int x, y, remain;
    float result;

    printf("Ingresar un número entero:");
    scanf("%d", &x);
    printf("Ingresar un número entero:");
    scanf("%d", &y);

    result = (float)x / (float)y;
    remain = x % y;

    printf("La división de %d / %d = %f\n", x, y, result);
    printf("El residuo de la división de %d / %d = %d\n", x, y, remain);

    return 0;
}