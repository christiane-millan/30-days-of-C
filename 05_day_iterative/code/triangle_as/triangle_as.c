#include <stdio.h>

    /* constantes globales */
    const int num_lineas = 5;
const char blanco = ' ';
const char asterisco = '*';
int main()
{
    int fila, blancos, cuenta_as;
    puts(" "); /* Deja una línea de separación */

    /* bucle externo: dibuja cada línea */
    for (fila = 1; fila <= num_lineas; fila++)
    {
        // putchar('\t'); /*primer bucle interno: escribe espacios */
        for (blancos = num_lineas - fila; blancos > 0; blancos--)
            putchar(blanco);
        for (cuenta_as = 1; cuenta_as < 2 * fila; cuenta_as++)
            putchar(asterisco);
        puts(" ");
        /* terminar línea */
    } /* fin del bucle externo */

    return 0;
}