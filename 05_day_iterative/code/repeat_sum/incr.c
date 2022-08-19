#include <stdio.h>

int main(){
    int n, m;

    n = 8;
    m = ++n; /* incrementa n en 1, 9, y lo asigna a m */
    printf(" n = %d",n);
    printf(" m = %d",m); 

    printf(" n = %d",--n); /* decrementa n en 1, 8, y lo pasa a printf() */

    m = n++; /* asigna n(8) a m, después incrementa n en 1 (9) */
    printf(" n = %d",n);
    printf(" m = %d",m); 

    printf(" n = %d",n--);
    printf(" n = %d",n); 

    return 0;
}