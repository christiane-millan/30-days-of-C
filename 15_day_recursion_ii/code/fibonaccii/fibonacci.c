#include <stdio.h>

long fibonacci_iterativo(long n);
long fibonacci_recursivo(long n);

int main(){
    long n;
    printf("Ingrese el tamaño de la serie Fibonacci:");
    scanf("%ld", &n);

    printf("Algoritmo iterativo\n");
    fibonacci_iterativo(n);

    printf("Algoritmo recursivo\n");
    printf("%ld\n", fibonacci_recursivo(n));
    return 0;
}

long fibonacci_iterativo(long n){
    if ( n == 0 || n == 1){
        if (n == 1)
            printf("0, ");
        printf("%ld \n", n);
        return n;
    }
    else {
        long fibonacci_lower = 0;
        long fibonacci_upper = 1;
        printf("%ld, ", fibonacci_lower);
        printf("%ld, ", fibonacci_upper);

        for (long i = 2; i < n; i++){
            long temp = fibonacci_lower;
            fibonacci_lower = fibonacci_upper;
            fibonacci_upper = fibonacci_lower + temp;
            printf("%ld, ", fibonacci_upper);
        }
        printf("\n");
        return fibonacci_upper; 
    }
}

long fibonacci_recursivo(long n){
    if( n == 0 || n == 1 ){
        printf("Se aplicó caso base con %ld\n", n);
        return n;
    }
    else {
        printf("Se aplicó caso recursivo para: %ld\n", n-1);
        printf("Se aplicó caso recursivo para: %ld\n", n-2);
        return fibonacci_recursivo(n-1) + fibonacci_recursivo(n-2);
    }
}