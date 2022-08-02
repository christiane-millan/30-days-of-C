# Día 1. Introducción

## Primer programa en C

Es recomendable crear una carpeta para cada programa, los primeros programas se escribiran en un solo archivo, pero en futuras prácticas será necesario dividir el programa en varios archivos.

1. Crear una carpeta: `dia_1_hola_mundo`
2. Iniciar el editor de codigo VSC con el comando: `code .`
3. Crear el archivo `hello.c`
4. Copiar el siguiente código

```c
#include <stdio.h>

int main()
{
    printf("Hello, world!\n");
    return 0;
}
```

5. Guardar el código

## Compilar el primer programa en C

1. Abri la terminal, linea de comandos o ventana de consola. Escribir el siguiente comando.

```bash
gcc hello.c
```

2. Una vez terminada la compilación, verificar la creación del archivo `a.out`.

Si el compilador muestra algun mensaje, es neceario leer lo que indica y tratar de arreglar tales errores.

## Ejecutar el primer programa en C

1. Abri la terminal, linea de comandos o ventana de consola.
2. Ejecutar con el programa con: `./a.out`
3. Se mostará en pantalla la salida de la ejecuación del programa.

```bash
Hello, world!
```

4. Verificar la ejecución del programa

## Comentarios al primer programa en C

Los comentarios en el código permiten agregar explicaciones a partes especificas de código.

Existen diferentes formas de agrega comentarios en C, como se muestra en el siguiente código.

```c
/* (1) Un comentario de una línea estilo C. */

/* (2) Un comentario de múltiples líneas estilo C. */

/*
 * (3) Una forma muy comun de 
 * formato de un comentario de
 * múltiples líneas estilo C.
 */

/* (4) Los comentarios estilo C  pueden aparecer casi en cualquier lado. */

/*(5)*/ printf( /* Hola hola. */ "Hello, world!\n" ); 

/*(6)*/ printf( "Hello, world!\n" ); /* yay! */

// (7) Un comentario estilo C++  (termina con fin de línea).

   printf( "Hello, world!\n" ); // (8) hola; yay!

//
// (9) Una manera más común  
// de comentar con múltiples líneas
// estilo C++ 
// 

// (10) cualquier cosa puede aparecer despues de //,  incluso /* ... */ e
// e incluso más // después del primer // pero serán  
// ignorados porque todos son parte del comentario.
```

### Recomendaciones

Al momento de escribir comentarios es importante tomar en cuenta las siguientes recomendaciones:

- Asumir que el lector conoce el lenguaje de programación
- Escrbir sentencias completas con capitalización y puntuación apropiada
- Comentar usos poco comunes del lenguaje
- Comentar de manera resilente a los cambios
- Comentar en alto nivel
- Transmitir la intención del código

Vamos a realizar una modificación a nuestro primer programa, para agregar comentarios al código, pero en partícular estos comentarios tienen el objetivo de identificar el programa y proporcionar otras datos adicionales como la fecha de creación y el autor.

```c
/*
* Nobre del archivo: hello2.c
* Descripción: Mi primer programa en C .
* Autor: Homer J Simpson
* Fecha: 24/07/2022
*/

#include <stdio.h>

int main()
{
    printf("Hello, world!\n");
    return 0;
}
```

## Estructura de un programa

Los elementos que definen la estructura de un programa en C, son:

- Declaraciones
- Bloques de instrucciones
- Delimitadores
- Espacios en blanco

### Secuencias de escape

Las secuencias de escape son un tipo de puntuación en los programas que modifican el significado del símbolo que les precede.

```c
/*
* Nombre del archivo: secuencias_escape.c
* Descripción: Uso de secuencias de escape en C .
* Autor: Christian Millán
* Fecha: 24/07/2022
*/
#include <stdio.h>

int main( void )  {
    printf( "Hola, mundo sin una nueva línea" );
    printf( "Hola, mundo con una nueva línea\n" );
    printf( "Ana cadena con \"texto entre comillas\" dentro de esta misma\n\n" );
    printf( "Encabezados\tColumnas\tCabeceras\n" );
    printf( "The\tquick\tbrown\n" );
    printf( "fox\tjumps\tover\n" );
    printf( "the\tlazy\tdog.\n\n" );  
    printf( "Una línea de texto que\nseparada en tres líneas\ny completea la línea\n\n" );
    return 0;
}
```

## Tipos de datos

```c
#include <stdint.h>
#include <stdbool.h>

 // function prototypes
void printSizes( void );

int main( void )
{
  printSizes();
}

// function to print the # of bytes for each of C11's data types
//
void printSizes( void ) {
  printf( "Size of C data types\n\n" );
  printf( "Type             Bytes\n\n" );
  printf( "char               %lu\n" , sizeof( char ) );
  printf( "int8_t             %lu\n" , sizeof( int8_t ) );
  printf( "unsigned char      %lu\n" , sizeof( unsigned char ) );
  printf( "uint8_t            %lu\n" , sizeof( uint8_t ) );
  printf( "short              %lu\n" , sizeof( short ) );
  printf( "int16_t            %lu\n" , sizeof( int16_t ) );
  printf( "uint16t            %lu\n" , sizeof( uint16_t ) );
  printf( "int                %lu\n" , sizeof( int ) );
  printf( "unsigned           %lu\n" , sizeof( unsigned ) );
  printf( "long               %lu\n" , sizeof( long ) );
  printf( "unsigned long      %lu\n" , sizeof( unsigned long ) );
  printf( "int32_t            %lu\n" , sizeof( int32_t ) );
  printf( "uint32_t           %lu\n" , sizeof( uint32_t ) );
  printf( "long long          %lu\n" , sizeof( long long ) );
  printf( "int64_t            %lu\n" , sizeof( int64_t ) );
  printf( "unsigned long long %lu\n" , sizeof( unsigned long long ) );
  printf( "uint64_t           %lu\n" , sizeof( uint64_t ) );
  printf( "\n" );
  printf( "float              %lu\n" , sizeof( float ) );
  printf( "double             %lu\n" , sizeof( double ) );
  printf( "long double        %lu\n" , sizeof( long double ) );
  printf( "\n" );
  printf( "bool              %lu\n" , sizeof( bool ) );
  printf( "\n" );
}
```

## Ejercicios

1.1. Salida en pantalla

Escribir un programa que imprima su nombre y dirección.

Ejemplo:

```Bash
Nombre: Homero J. Simpson
Dirección: Av. Evergreen 742. Sprinfield, NT 48007. USA.
```

1.2. Salida en texto largo en pantalla

Escribir un programa que imprima una página de texto con no más de 40 caracteres por línea.

Ejemplo:

```Bash
Pass
```

1.3. Letrero

Escribir un programa que imprima las letras UTM con asteriscos.

Ejemplo:

```Bash
*       *   ***********   *           *
*       *        *        * *       * * 
*       *        *        *  *     *  *
*       *        *        *   *   *   *
*       *        *        *    * *    *
*       *        *        *     *     *
*       *        *        *           *  
*       *        *        *           *
  *****          *        *           *
```
