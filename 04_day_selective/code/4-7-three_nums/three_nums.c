#include <stdio.h>

int main() {

    int num_1, num_2, num_3;

    printf("Ingresar tres números enteros:");
    scanf("%d %d %d", &num_1, &num_2, &num_3);

    if((num_1 > num_2) && (num_1 > num_3))
        printf("%d es el mayor\n", num_1);
        
    if((num_2 > num_1) && (num_2 > num_3))
        printf("%d es el mayor\n", num_2);
    
    if((num_3 > num_2) && (num_3 > num_1))
        printf("%d es el mayor\n", num_3);

}