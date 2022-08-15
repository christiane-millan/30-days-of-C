#include <stdio.h>

int main()
{
  int numerator, divider;
  
	printf("Introduzca dos enteros:");
    scanf("%d %d",&numerator,&divider);
  
	if ((numerator % divider) == 0) 
    {
		printf(" %d es divisible entre %d\n",numerator, divider);
        printf("La condición fue verdadera\n");
    }
	return 0;
}