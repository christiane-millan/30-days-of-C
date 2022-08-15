#include <stdio.h>

int main()
{
    float note;
  
    printf("Introduzca la nota obtenida (0-10): ");
    scanf("%f", &note);
    /* compara Nota con 6 */
    if (note >= 6.0)
        printf("Aprobado\n");
    
    if (note < 6.0)
        printf("Reprobado\n");

    return 0;
}