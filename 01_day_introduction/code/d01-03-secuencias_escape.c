/*
* Nombre del archivo: secuencias_escape.c
* Descripción: Uso de secuencias de escape más comunes en C.
* Autor: Christian Millán
* Fecha: 24/07/2022
*/
#include <stdio.h>

int main( void )  {
    printf( "Hola, mundo sin una nueva línea" );
    printf( "Hola, mundo con una nueva línea\n" );
    printf( "Una cadena con \"texto entre comillas\" dentro de esta misma\n\n" );
    printf( "Encabezados\tColumnas\tCabeceras\n" );
    printf( "The\tquick\tbrown\n" );
    printf( "fox\tjumps\tover\n" );
    printf( "the\tlazy\tdog.\n\n" );  
    printf( "Una línea de texto que\nseparada en tres líneas\ny completea la línea\n\n" );
    return 0;
}