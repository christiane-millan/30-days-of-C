#include <stdio.h>

int main() {

    int num_1, num_2, num_3;

    printf("Ingresar tres números enteros:");
    scanf("%d %d %d", &num_1, &num_2, &num_3);

    if(num_1 > num_2)
        if (num_1 > num_3)
            printf("%d es el mayor\n", num_1);
        else
            printf("%d es el mayor\n", num_3);
    else
        if(num_2 > num_3)
            printf("%d es el mayor\n", num_2);
        else
            printf("%d es el mayor\n", num_3);

}