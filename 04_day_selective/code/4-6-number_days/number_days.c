#include <stdio.h>

int main(){
    int m;

    printf("Ingrese el número del mes:");
    scanf("%d", &m);

    switch (m)
    {
    case 1:/* constant-expression */
    case 3:/* constant-expression */
    case 5:/* constant-expression */
    case 7:/* constant-expression */
    case 8:/* constant-expression */
    case 10:/* constant-expression */
    case 12:/* constant-expression */
            puts("31");
            break;
    case 2:/* constant-expression */
            puts("28");
            break;
    case 4:/* constant-expression */
    case 6:/* constant-expression */
    case 9:/* constant-expression */
    case 11:/* constant-expression */
            puts("30");
            break;
    
    default:
            puts("No es un número de mes valido...");
       
    }
    return 0;
}