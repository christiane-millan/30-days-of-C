#include <stdio.h>

int main(){
    int sum = 0;
    int count = 0;

    while(count < 100)
    {
        sum += (count + 1);
        //printf("El valor de count = %d\n", count);
        count++;
        //count = count + 1
    }

    printf("El valor es: %d\n", sum);

    return 0;
}