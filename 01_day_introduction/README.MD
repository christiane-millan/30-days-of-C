# Día 1

* [Introducción](https://github.com/christiane-millan/30-days-of-C/tree/main/01_day_introduction#introducci%C3%B3n)
* [Estructura de un progama](https://github.com/christiane-millan/30-days-of-C/tree/main/01_day_introduction#estructura-de-un-programa)
* [Tipos de datos](https://github.com/christiane-millan/30-days-of-C/tree/main/01_day_introduction#tipos-de-datos)

## Introducción

### Primer programa en C

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

### Compilar el primer programa en C

1. Abri la terminal, linea de comandos o ventana de consola. Escribir el siguiente comando.

```bash
gcc hello.c
```

2. Una vez terminada la compilación, verificar la creación del archivo `a.out`.

Si el compilador muestra algun mensaje, es neceario leer lo que indica y tratar de arreglar tales errores.

### Ejecutar el primer programa en C

1. Abri la terminal, linea de comandos o ventana de consola.
2. Ejecutar con el programa con: `./a.out`
3. Se mostará en pantalla la salida de la ejecuación del programa.

```bash
Hello, world!
```

4. Verificar la ejecución del programa

### Comentarios al primer programa en C

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
- Escribir sentencias completas con capitalización y puntuación apropiada
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
| Símbolo | Significado |
| --- | --- |
| `\a` | Alerta |
| `\b` | Espacio |
| `\f` | Form feed |
| `\n` | Nueva línea |
| `\r` | Retorno de carro |
| `\t` | Tabulador horizontal |
| `\v` | Tabular vertical |
|`\'` | comilla simple |
|`\"` | comilla doble |
|`\?` | marca de pregunta |
|`\\` | diagonal invertida |


Ejemplo del uso de las secuencias de escape
```c
/*
* Nombre del archivo: secuencias_escape.c
* Descripción: Uso de secuencias de escape en C.
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

En C existen cinco tipos de datos básicos e intrínsecos. Intrínsecos significa que estos tipos y todas las operaciones sobre ellos están construidas dentro del lenguaje.

- **Números enteros:** Estos pueden representar solamente un rango positivo de valores o un rango que incluye tanto valores positivos y negativos. Ejemplos: `4`, `2354`, `-2354` y `0`.
- **Números con fracciones o números decimales:** Estos son todos los números entre los números enteros, como con `1/2`, `3/4`, `0.79`, `1.125` y `3.14159` (un valor aproximado para $\pi$ o incluso `3.1415926535897932384626433`) o incluso un valor más preciso o más aproximado para $\pi$. Los números decimales pueden incluir valores negativos `-2.3`.
- **Caracteres:** Estos son la base de las cadenas en C. Algunos lenguajes tienen un tienen un tipo separado para las cadenas. En c, las cadenas son casos especiales de arreglos de caracteres (no son un tipo de dato pero si un arreglo especial de valores de caracteres continuos). Ejemplos: `'a'`, `'_'`, `'4'`.
- **Valores Booleanos:** Estos pueden ser de cualquier tipo  dependiendo de la preferencia del compilador y del tamaño de número entero preferido de la máquina. Es comun que Falso y Verdadero se representen por `0` y `1` (respectivamente).
- **Direcciones:** Estas son las localizaciones de bytes en una memoria de computadora. C provee de valores de dirección directa en memoria. Muchos lenguajes no permiten el direccionamiento directo

```c
/*
* Nombre del archivo: d01-04-datatype.c
* Descripción: Tipos de datos usados en C.
* Autor: Christian Millán
* Fecha: 24/07/2022
*/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int main( void )
{
  printf( "Tamaño de los tipos de datos en C\n\n" );
  printf( "Tipo             Bytes\n\n" );
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

Resultado de la ejecución

```bash
❯ gcc datatype.c
❯ ./a.out
Tamaño de los tipos de datos en C

Tipo             Bytes

char               1
int8_t             1
unsigned char      1
uint8_t            1
short              2
int16_t            2
uint16t            2
int                4
unsigned           4
long               8
unsigned long      8
int32_t            4
uint32_t           4
long long          8
int64_t            8
unsigned long long 8
uint64_t           8

float              4
double             8
long double        16

bool              1
```

### Rango de valores

```c
/*
* Nombre del archivo: d01-05-range_datatype.c
* Descripción: Rango de los tipos de datos usados en C.
* Autor: Christian Millán
* Fecha: 24/07/2022
*/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>

int main( void )  {
  printf( "Rangos para tipos de datos enteros en C\n\n" );
  printf( "int8_t %20d %20d\n" , SCHAR_MIN , SCHAR_MAX );
  printf( "int16_t %20d %20d\n" , SHRT_MIN , SHRT_MAX );
  printf( "int32_t %20d %20d\n" , INT_MIN , INT_MAX );
  printf( "int64_t %20lld %20lld\n" , LLONG_MIN , LLONG_MAX );
  printf( "uint8_t %20d %20d\n" , 0 , UCHAR_MAX );
  printf( "uint16_t %20d %20d\n" , 0 , USHRT_MAX );
  printf( "uint32_t %20d %20u\n" , 0 , UINT_MAX );
  printf( "uint64_t %20d %20llu\n" , 0 , ULLONG_MAX );
  printf( "\n" );
  printf( "Rangos para tipos de datos de números reales en C\n\n" );
  printf( "float %14.7g %14.7g\n" , FLT_MIN , FLT_MAX );
  printf( "double %14.7g %14.7g\n" , DBL_MIN , DBL_MAX );
  printf( "long double %14.7Lg %14.7Lg\n" , LDBL_MIN , LDBL_MAX );
  printf( "\n" );

  return 0;
}
```

Resultado de la ejecución

```bash
❯ gcc range_datatype.c
❯ ./a.out
Rangos para tipos de datos enteros en C

int8_t                  -128                  127
int16_t               -32768                32767
int32_t          -2147483648           2147483647
int64_t -9223372036854775808  9223372036854775807
uint8_t                    0                  255
uint16_t                   0                65535
uint32_t                   0           4294967295
uint64_t                   0 18446744073709551615

Rangos para tipos de datos de números reales en C

float   1.175494e-38   3.402823e+38
double  2.225074e-308  1.797693e+308
long double 3.362103e-4932 1.189731e+4932
```

## Variables

Los programas manipulan valores de datos. Si un programa ejecuta un solo calculo (como tal, convertir una valor de temperatura de Fahrenheit a Celsius) lee datos solo para mostrarlos, o realizar cálculos o interacciones mucho más complejos, los valores que un programa manipula deben ser **accesibles** y **asignables**.

- **Accesible** significa que un valor debe residir en algún lugar de la memoria de la computadora y debe ser recuperables.
- **Asignables** significa que un valor o el resultado de un cálculo debe ser almacenado en algún lugar de la memoria de la computadora para ser más tarde recuperado. 

Cada valor tienen un tipo de dato y una localización nombrada donde es almacenada. Estas pueden ser **variables** o **constantes**.

### Nombrar una variable

Cada variable tiene un identificador o nombre. Un nombre de variable es un identificador, los nombres de funciones son identificadores.

- Un **identificador** o nombre es una secuencia de letras mayúsculas (`A..Z`), letras minúsculas (`a..z`), dígitos (`0..9`) y el guión bajo (`_`). 
- Un identificador no puede comenzar con dígito, las letras minúsculas  y mayúsculas son diferentes unas de otras, por lo tanto `achar`, `AChar`, `ACHAR` identificarían a variables diferentes. 
- Un identificador no puede tener la misma escritura que una palabra reservada (revisar la lista de palabras reservadas en C).

Existen diferentes convenciones para nombrar variables. Dos métodos comunes para nombres descriptivos y fáciles de leer son el **camel-case** y **undersocre-separated**, también conocido como **snake-case**.

- All-lowercase: `inchesperminute`, `feetpersecond`, y `milesperhour`.
- Camel-case: `inchesPerMinute`, `feetPerSecond` y `milesPerHour`.
- Snake-case: `inches_per_minute`, `feet_per_second` y `miles_per_hour`.

Una vez que se elige una convención de nombrado, es necesario apegarse a ella y no mezclar los estilos.

- Tipos explícitos de variables
  
```c
#include <stdbool.h>   /* So we can use: bool, true, false */

int       a_number;
long      a_big_number;
long long a_really_big_number;
float     inches;
float     feed;
float     yards;
double    length, width, height;
bool      is_it_raining;
```

- Tipos explicitos de variables con inicialización

```c
#include <stdbool.h>   /* So we can use: bool, true, false */

int       a_number          = 10;
long      a_big_number       = 3211145;
long long a_really_big_number = 425632238789;
float     inches           = 33.0;
float     feet             = 2.5;
float     yards            = 1780;
double    length = 1 , width = 2 , height = 10;
bool      is_it_raining      = false;

int my_counter = 0;
int a_different_counter = my_counter;
```

## Constantes

En algún momento se requieren variables que no cambien su valor durante el tiempo de vida. Estas son las constantes y pueden ser definidas de distintas formas para diferentes usos.

### Constantes literales
  
  Considerar las siguientes secuencias de caracteres como literales:

```c
65
'A'
8.0
131072.0
"Hello, world!"
```

Cada una de estas secuencias (excepto la cadena) tiene una representación interno de bytes de `0000 0000 0100 0001`. Sin embargo, por la puntuación que rodea a estas valores, el compilador puede inferir que tipo de dato tienen a partir de su contexto:

```c
65  ---> int
'A' ---> unsigned char
8.0 ---> float
131072.0 ---> double
```

 Estos valores son literalmente escritos en el código fuente y sus tipos son determinados por la forma en la cual son escritos, o precisamente por cómo su puntuación especifica el contexto del tipo de dato.

### Constantes definidas por valores

```c
#define INCHES_PER_FOOT 12
#define FEET_PER_YARD 3

feet = inches / INCHES_PER_FOOT;
yards = feet / FEET_PER_YARD;
```

### Constantes de tipo explícito

```c
const float k_inches_per_foot = 12.0;
const float k_feet_per_yard   =  3.0;    

feet  = inches / k_inches_per_foot; 
yards = feet / k_feet_per_yard;
```
