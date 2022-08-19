#include <stdio.h>
#include <math.h>
#define MAX_LIMIT 100

int main()
{
    int n;
    int result;
    int count = 0;
    const int max_limit = 1000;

    printf("Ingresar el valor de n:");
    scanf("%d", &n);

    result = pow(n, count);
    while(result <= max_limit)
    {
        printf("La potencia: %d\n", result);
        count++;
        result = pow(n, count);
    }
    return 0;
}