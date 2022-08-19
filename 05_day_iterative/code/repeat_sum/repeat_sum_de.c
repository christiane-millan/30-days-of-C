#include <stdio.h>

int main(){
    int sum = 0;
    int count = 100;

    while(count > 0)
    {
        sum += count;
        printf("El valor de count = %d\n", count);
        count--;
        //count = count + 1
    }

    printf("El valor es: %d\n", sum);

    return 0;
}