#include <stdio.h>

int main(){
    int a, b, c;
    printf("Ingresar tres números enteros:");
    scanf("%d %d %d", &a, &b, &c);

    // if ((a <= b) && (b <= c))
    // {
    //     puts("Orden numérico correcto");
    // }
    // else 
    // {
    //     puts("No se cumple el orden numérico");
    // }

    ((a <= b) && (b <= c))? puts("Orden numérico correcto"): puts("No se cumple el orden numérico");  
    

    return 0;
}