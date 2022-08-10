#include <stdio.h>

int main(){
    int number_one, number_two;
    int aux;

    printf("Ingresar primer número entero:");
    scanf("%d", &number_one);
    printf("Ingresar segundo número entero:");
    scanf("%d", &number_two);

    aux = number_one;
    number_one = number_two;
    number_two = aux;

    printf("Primer valor ingresado: %d", number_two);
    printf("Segudo valor ingresado: %d", number_one);


    return 0;
}