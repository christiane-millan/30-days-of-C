#include <stdio.h>

long sum_iterative(long n);
long sum_recursive(long n);

int main(){
    long n;
    printf("Ingresar número entero:");
    scanf("%ld", &n);
    printf("Suma iterativa %ld\n", sum_iterative(n));
    printf("Suma recursiva %ld\n", sum_recursive(n));
    //printf("Tamaño int %lu", sizeof(int));
    return 0;
}

long sum_iterative(long n){
    long sum = 0;
    for (long i = 1; i <= n; i++){
        sum += i;
    }
    return sum;
}

long sum_recursive(long n){
    if (n == 1)
        return 1;
    else
        return n + sum_recursive(n - 1);
} 