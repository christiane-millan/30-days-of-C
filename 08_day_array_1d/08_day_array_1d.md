# Día 8. Arreglos unidimensionales

- [Día 8. Arreglos unidimensionales](#día-8-arreglos-unidimensionales)
  - [Inicialización de arreglos](#inicialización-de-arreglos)
    - [Almacenamiento en memoria de los arreglos](#almacenamiento-en-memoria-de-los-arreglos)
    - [El tamaño de los arreglos](#el-tamaño-de-los-arreglos)
  - [Acceso a los elementos de un arreglo](#acceso-a-los-elementos-de-un-arreglo)
  - [Asignación de valores a los elementos de un arreglo](#asignación-de-valores-a-los-elementos-de-un-arreglo)
  - [Operaciones en arreglos con loops](#operaciones-en-arreglos-con-loops)
  - [Arreglos como paso de parámetros](#arreglos-como-paso-de-parámetros)

Los arreglos permiten organizar un tipo de dato homogéneo que provee las bases de las cadenas o arreglos de caracteres.

Un arreglo es una colección de dos o más valores, los cuales todos ellos tienen el mismo tipo de dato y comparten un único nombre base en común.

Un arreglo puede contener, por ejemplo, las calificaciones de los alumnos de una clase, las temperaturas de cada día de un mes en una ciudad determinada, o el número de habitantes de cada uno de los 32 estados de México. Cada item del arreglo se denomina elemento.

Los elementos de un arreglo se enumeran consecutivamente a partir del 0: 0, 1, 2, 3, … Estos números se denominan valores índices o subíndices del arreglo. Estos números localizan la posición del elemento dentro del arreglo, proporcionando un acceso directo al arreglo.

No tiene sentido tener un arreglo de solo un valor, que puede ser simplemente una variable. La definición de un arreglo se realiza mediante la siguiente sintaxis:

```c
data_type array_identifier[number_of_elements];
```

`data_type` es un tipo de dato intrínseco o personalizado, `array_identifier` es el nombre base del arreglo, y `number_of_elements` especifica cuantos valores de `data_type` hay en el arreglo. `number_of_elements`, sin importar el tipo y valor que sea dado, este se especifica con un valor entero. Todos los elementos de el arreglo son continuos por lo que el tamaño del arreglo es el tamaño de cada elemento multiplicado por el número de elementos del arreglo.

Para declara un arreglo de enteros de 10 elementos, se utiliza la siguiente sentencia:

```c
int an_array[10];
```

`an_array` es el nombre base de nuestro arreglo de `10` enteros. Esta declaración crea `10` variables, cada una se accede a través de un índice en un rango de `0..9`.

Incluso se puede declarar el tamaño de un arreglo a partir del valor de una variable, una constante o una expresión. En el siguiente código se muestra el ejemplo del uso de una constante:

```c
const int l_array_size = 10;
int another_array[k_array_size];
```

`k_array_size` es un entero el cual su valor no cambia. Esta variable constante resultará muy conveniente cuando en el código se acceda a los elementos del arreglo. Si utilizamos una variable que puede cambiar su valor (no constante), al cambiar el valor de la variable el tamaño del arreglo no cambia. El tamaño del arreglo es fijado en el momento de su definición, el tamaño nu puede ser cambiado después de la definición del arreglo.

Si se desea dar seguimiento de la presión del aire y la profundidad de rodadura de las ruedas de varios vehículos. 

```c
double tire_tread[number_wheels];
double tire_pressure[number_wheels];

```

## Inicialización de arreglos

Como todas las variables es necesario que en algún momento reciban un valor inicial. La forma más básica de inicializar un arreglo es asignar a todos elementos el mismo valor en tiempo de definición. 

```c
int an_array[10] = {0};
double wheel_thread[number_of_wheels] = {1.5};
```

Todos los elementos del arreglo serán incializados con el mismo valor dado entre `{}`. En el ejemplo anterior an_array todos sus elementos serán inicializados con el valor 10. En wheel_thread todos los elementos recibirán el valor de 1.5. Sin embargo, se pueden inicializar con una constante, o con el resultado de una expresión. Se puede cambiar el valor de cada elemento como sea necesario en momentos posteriores.

Para fijar valores diferentes a cada elemento es necesario especificarlos entre paréntesis y separados por coma:

```c
int an_array[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
```

Se puede asignar de forma dinámica los valores a un arreglo, si no se especifica el número de elementos. Sin embargo, una vez que el tamaño es determinado, no puede ser cambiado:

```c
float length_array[] = {1.0, 2.0, 3.0, 4.0, 3.0, 2.0, 1.0};
```

En esta definición, `length_array` contiene siete valores de punto flotante. Cada uno de estos valores, puede cambiar, pero no se puede cambiar el tamaño de `legth_array`, siempre serán siete valores de tipo `float`.  

Otros ejemplos:

```c
int numbers[6] = {10, 20, 30, 40, 50, 60};
int n[ ] = {3, 4, 5};
int m[3];
char c[ ] = {'L','u','i','s'};
char s[ ] = "Puesta del Sol";
char s[] = {'P', 'u', ...};
```

Al dejar vacíos lo corchetes C  en la asignación, el compilador asigna automáticamente cinco elementos a la variable del arreglo.

<aside>
📌 Si de define un arreglo globalmente o un arreglo estático y no se proporciona ningún valor de inicialización, el compilador inicializará el arreglo con un valor en forma predeterminada (cero para arreglos de elementos enteros y reales, coma flotante, y carácter nulo para arreglos de caracteres).

</aside>

* [Video - Declaración y asignación (Enteros) ](https://www.youtube.com/watch?v=otakC4DMosM&list=PL3_qQRFomlqLXuL2ukPe0pTNKoVt3fuMJ&index=6)
* [Video - Asignación mediante conjuntos (Enteros)](https://www.youtube.com/watch?v=unQCciNBgAI&list=PL3_qQRFomlqLXuL2ukPe0pTNKoVt3fuMJ&index=7)
* [Video - Arreglos Unidimensionales - Decimales](https://www.youtube.com/watch?v=H82CCIQUNbA&list=PL3_qQRFomlqLXuL2ukPe0pTNKoVt3fuMJ&index=8)


### Almacenamiento en memoria de los arreglos

Los elementos de los arreglos se almacenan en bloques contiguos. Por ejemplo:

```c
int ages[5];
char codes[5];
```

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/6632a5fb-55d1-438e-9817-b5d16ace14d9/Untitled.png)

### El tamaño de los arreglos

Se puede determinar el tamaño de un arreglo (si se conoce su tipo) de la siguiente forma:

```c
#include <stdio.h>

int main()
{
    int an_array[10] = {0}; // Initialize the whole thing to 0.

    int type_size = sizeof(int);
    int array_size = sizeof(an_array);
    int element_num = array_size / type_size;

    printf("      sizeof(int) = %2d bytes\n", type_size);
    printf("  sizeof(an_array) = %2d bytes\n", array_size);
    printf("  an_array[] has %d elements\n\n", element_num);

    // Dynamically allocate array size via initialization.

    float length_array[] = {1.0, 2.0, 3.0, 4.0, 3.0, 2.0, 1.0};

    int float_size = sizeof(float);
    int array_size2 = sizeof(length_array);
    int element_num2 = array_size2 / float_size;

    printf("      sizeof(float) = %d bytes\n", float_size);
    printf("  sizeof(an_array) = %d bytes\n", array_size2);
    printf("an_array has %d elements\n", element_num2);
}
```

Salida

```bash
❯ gcc size_array.c -o size_array -Wall -Werror -std=c11
❯ ./size_array
       sizeof(int) =  4 bytes
  sizeof(an_array) = 40 bytes
  an_array[] has 10 elements

     sizeof(float) = 4 bytes
  sizeof(an_array) = 28 bytes
  an_array has 7 elements
```

El operador sizeof devuelve el número de bytes necesarios para contener su argumentos. Si se utiliza sizeof para solicitar el tamaño de un arreglo, esta función devuelve el número de bytes reservados para el arreglo completo.

## Acceso a los elementos de un arreglo

Cada elemento de un arreglo es accedido mediante el nombre base (nombre del arreglo) y el índice dentro del arreglo. Un índice también es conocido como subíndice. Cada elemento es accedido de la siguiente forma:

```c
array_name[index]
```

El `index` es un valor entre `0` y el tamaño del arreglo menos `1`. Se puede acceder a cualquier elemento del arreglo de esta forma. El índice puede ser un valor literal, una variable o el resultado de una llamada a una función o el resultado de una expresión:

```c
float an_rray[10] = {2.0};
int   counter = 9;
float a_float  = 0.0; 

a_float = an_array[9];             // Access last element.
a_float = an_array[counter];       // Access last element via value 
                                   // of counter.
a_float = an_array[exp(3, 2)]; // Access element at result of
                                   // function.
a_float = an_array[(sizeof(an_array)/sizeof(float) - 1 ]; // Access 
                                   // last element via expression.
```

Es importante considerar que los indices del arreglo comienzan en 0 y durante el momento que un elemento sea accesado no se utiliza un índice fuera del rango valido.

```c
arr[0] = 1;  // 0th offset, 1st element
arr[1] = 2;  // 1st offset, 2nd element
arr[2] = 3;  // 2nd offset, 3rd element
arr[3] = 4;  // 3rd offset, 4th element (last one)
arr[4] = 5;  // ERROR! there is no 5th element.
```

Errores comunes con un índice fuera del rango permitido

```c
int main( void )  
{
  int   anArray[10]  = {0}; // Initialize the whole thing to 0.
  int x, y , z;
  x = 11;
  y = 12;
  z = 13;

  anArray[ 11 ] = 7; // Compiler error!
  anArray[ x]  = 0;  // No compiler error, but runtime error!
}
```

Compilar

```bash
❯ gcc -Wall -Werror -Wextra -std=c11 error.c -o error.out
error.c:12:5: error: use of undeclared identifier 'an_rray'; did you mean 'an_array'?
    an_rray[x] = 0;  // No compiler error, but runtime error!
    ^~~~~~~
    an_array
error.c:5:9: note: 'an_array' declared here
    int an_array[10] = {0}; // Initialize the whole thing to 0.
        ^
error.c:11:5: error: array index 11 is past the end of the array (which contains 10 elements) [-Werror,-Warray-bounds]
    an_array[11] = 7; // Compiler error!
    ^        ~~
error.c:5:5: note: array 'an_array' declared here
    int an_array[10] = {0}; // Initialize the whole thing to 0.
    ^
2 errors generated.
```

El compilador encuentra que `an_array[11]` esta fuera del rango permitido y genera un error.

Si comentamos esta línea, y compilamos de nuevo

```bash
❯ gcc -Wall -Werror -Wextra -std=c11 error.c -o error.out
❯ ./error.out
[1]    9015 abort      ./error.out
```

El compilador no genera un error en `an_array[x]` pero si lo hará en tiempo de ejecución.

## Asignación de valores a los elementos de un arreglo

Para cambiar los valores de un arreglo, se puede utilizar una forma muy similar al acceso de un elemento. 

```c
float an_array[10] = {0.0};
int   counter = 9;
float a_float  = 2.5; 

an_array[9] = a_float;
an_array[counter] = getQuarterOf( 10.0 );
an_array[pow( 3 , 2 )] = 5.0 / 2.0;
an_array[(sizeof(anArray)/sizeof(float) - 1] = 2.5;
```

Cada elemento de un arreglo es una variable que puede tomar valores de un valor asignado a través de el nombre del arreglo y su índice.

## Operaciones en arreglos con loops

Cuando un arreglo es utilizado, una operación común es iterar sobre todos los elementos.  La forma más común es mediante un ciclo `for()…`.

```c
const int k_array_size = 25;
int an_array[k_array_size];

for(int i=0; i <k_array_size; i++)
{
    an_array[i] = i;
}
```

Ejemplo, rellena los elementos de un arreglo con números reales positivos procedentes del teclado.

```c
#include <stdio.h>
#define MAX 10

float elements[MAX];

void main()
{
    int i;
    printf("\nIntroduzca una lista de %d elementos positivos.\n", MAX);

    for (i = 0; i<MAX; elements[i]> 0 ? ++i : i)
        scanf("%f", &muestra[i]);
}
```

* [Video - Arreglos Unidimensionales - Ejemplo promedio de calificaciones ](https://www.youtube.com/watch?v=40DqUexx-Qc&list=PL3_qQRFomlqLXuL2ukPe0pTNKoVt3fuMJ&index=11)
* [Video - Arreglos Unidimensionales - Ejemplo número aleatorios](https://www.youtube.com/watch?v=RHmEDzzC4Nk&list=PL3_qQRFomlqLXuL2ukPe0pTNKoVt3fuMJ&index=12)

## Arreglos como paso de parámetros

Un arreglo es una colección de variables juntas agrupadas con un nombre en común y un índice. Se puede tratar a cada elemento del arreglo como cualquier otra variable. Incluso como parámetros de función, los elementos de un arreglo pueden pasar como una variable regular:

```c
#include <math.h>
int an_array[10] = {0};
an_array[3] = 5;
an_array[3] = pow(an_array[3] , 2);

for(int i = 0; i < 10; i++)
{
    an_array[i] = pow(an_array[i], 2);
}
```

Cuando se quiere crear funciones que operen sobre todos los elementos de un arreglo, indistintamente de su tamaño. Los arreglos de tamaño desconocido se pueden pasar como parámetro de la siguiente forma:

```c
int find_min(int size, int an_array[]);
int find_max(int size, int an_array[] );

double find_mean(int size , int an_array[]);
double find_std_dev(int size , int an_array[]);
```

El lenguaje C, no almacena el tamaño de un arreglo, el programador debe dar seguimiento a este valor para asegurar no acceder más allá de los límites de memoria de un arreglo. En el ejemplo anterior, se pasa como parámetro el tamaño del arreglo.

Podríamos asumir que C realiza una copia del arreglo en la llamada de una función, pero no lo hace. Los arreglos como parámetros violan esta regla.  El nombre de un arreglo es un nombre de referencia a una locación de memoria y el nombre de referencia será copiado dentro de la función.

Ejemplo: Función para encontrar el valor mínimo y función para encontrar el máximo.

```c
int find_min(int size , int a[])  
{
    int min = a[0];
    for(int i = 0 ; i < size ; i++)
        if(a[i] < min)  
            min = a[i]; 
    return min; 
}

int find_max(int size , int a[])  
{
    int max = a[0];
    for(int i = 0 ; i < size ; i++)
        if( a[i] > max ) 
            max = a[i];
    return max;
}
```

Ejemplo: Función para el calcular la media y función para calcular la desviación estándar

```c
double find_mean(int size, int a[])
{
    double sum  = 0.0;
    for(int i = 0 ; i < size ; i++)
        sum += a[i];
    double mean = sum / size;
    return mean;
}

double find_std_dev(int size, int a[])
{
    // Compute variance.
    double mean = find_mean(size, a);
    double sum = 0.0;
    double variance = 0.0;
    for(int i = 0; i < size; i++)
        sum += pow((a[i] - mean), 2);

    variance = sum / size;
    // Compute standard deviation from variance.
    double std_dev = sqrt(variance);
    
    return std_dev;
}
```

Para esta demostración crear un archivo `array.h` donde se colocan las declaraciones de las funciones. Y crear otro archivo `array.c` donde se agrega las definiciones de las funciones mas la función `main()`.

```c
// build with:
// cc array3.c -o array3 -lm -Wall -Werror -std=c11

#include <stdio.h>
#include <math.h>
#include "array3.h"
int main( void )
{
    int array1[] = { 3 , 4 , 6 , 8, 13 , 17 , 18 , 19 };
    int array2[] = { 34 , 88 , 32 , 12 , 10 };

    int size = sizeof(array1) / sizeof(int);
  
    printf("array1: range, mean, & standard deviation\n");
    printf("    range = [%d..%d]\n", 
        find_min(size , array1), 
        find_max(size , array1));
    printf("     mean = %g\n"   find_mean(size, array1));
    printf("  std dev = %g\n\n", find_std_dev(size, array1));

    size = sizeof(array2) / sizeof(int);
    printf( "array2: range, mean, & standard deviation\n" );
    printf( "    range = [%d..%d]\n",
        find_min(size, array2),
        find_max(size ,array2));
    printf( "     mean = %g\n", find_mean(size, array2));
    printf( "  std dev = %g\n\n", find_st_dev(size, array2));
}
```

Salida

```bash
> cc array3. c -o array3 -Wall -Werror -std=c11
> ./array3
array1: range, mean, & standard deviation
range = [3..19]
mean = 11
std dev = 6.12372

array2: range, mean, & standard deviation
range = [10..88]
mean = 35.2
std dev = 28.1879
```
