#include <stdio.h>

int main(){
    int number;
    printf("Ingresar un número entero:");
    scanf("%d", &number);

    if (number < 0)
    {
        puts("bajo");
    }
    else
    {
        if (number > 100)
        {
            puts("alto");
        }
        else
        {
            puts("medio");
        }
        
    }
    
    return 0;
}