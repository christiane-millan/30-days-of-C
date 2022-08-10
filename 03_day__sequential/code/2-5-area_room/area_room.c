#include <stdio.h>

int main()
{
    float high, width, area;

    printf("Ingesar largo de la habitación:");
    scanf("%f", &high);
    printf("Ingesar ancho de la habitación:");
    scanf("%f", &width);

    area = high * width;

    printf("El area de la habitación es: %10.4f\n", area);

    return 0;
}