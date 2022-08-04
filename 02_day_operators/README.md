# Día 2

## Operadores I

Los operadores fundamentales son:

- Aritméticos, lógicos y relacionales.
- Condicionales
- Especiales

### Expresiones

Una expresión es una forma de calcular un valor. El conjunto de operaciones básicas de C  (aritméticas) para suma, resta, multiplicación y división, las cuales son las más comunes en la mayoría de los lenguajes de programación.

Las **expresiones** son componentes de declaraciones complejas. Los operadores trabajan en una o mas expresiones, donde una expresión puede ser simple o compleja:

- `5` es una expresión literal que evalúa el valor de `5`.
- `5 + 8` es una expresión aritmética  de dos simples expresiones (constantes literales), los cuales, con el operador de adición, evalúa a `13`.
- Una expresión más compleja, `5 + 8 - 10`, son en realidad dos operaciones aritméticas binarias donde `5` y `8` son evaluados primero para obtener un resultado intermedio, después el `10` es restado a este resultado intermedio.
- 5; es una sentencia de expresión que evalúa a 5 y entonces se mueve a la siguiente sentencia. Una versión más util de esta sería `a_value = 5;` la cual es realmente dos expresiones: la evaluación del 5 y después la asignación del valor a la variable `a_value`.

Un programa simple calc_length.c que aplica cada método de utilizar expresiones simples y complejas, es la siguiente:

```c
#include <stdio.h>

int feet_to_inches( double feet ) 
{
  int inches = feet * 12;
  return inches;
}

int main( void )
{
  int value   = 8; 
  int length  = 0;

  length = 5 + value + feet_to_inches( 3.5 );
  printf( "Calculated length = %d\n" , length );

  length = 5;
  length = length + value;
	length = length + feet_to_inches(3.5);
	print("Calculated length = %d\n", length );
}
```

Compilar el programa y ejecutar para validar

```bash
gcc calc_length.c -o calc_length
./calc_length
```

### Operador de asignación

El operador de asignación =, asigna el valor de la expresión derecha a la variable situada a la izquierda.

```c
code = 3467;
fahrenheit = 123.456;
x_axes = 525;
y_axes = 725; 
```
Este operador es asociativo por la derecha, esto permite realizar asignaciones múltiples, de la siguiente forma:

```c
a = b = c = 45;
// Equivale a 
a = (b = (c = 45));
```

Esto permite inicializar varias variables con una sola sentencia.

```c
int a, b, c;
a = b = c 5;
```

### Operadores aritméticos

Las operaciones aritméticas básicas son:

- Suma `+`
- Resta `-`
- Multiplicación `*`
- División `/`
- Modulo `%`

### Precedencia de operadores

| Operador | Operación | Nivel de procedencia |
| --- | --- | --- |
| () | (5 + 4) * 3 | 1 |
| +, - | +25, -6.745 | 2 |
| *, /, % | 5*5, 25/5 | 3 |
| +, - | 2+3 | 4 |

📌  Determinar el resultado de las siguientes expresiones:

a. `6 + 2 * 3 -4 /2`

b. `5 * ( 5 + (6-2) + 1`

c. `7 - 6 / 3 + 2 * 3 / 2 - 4 / 2`

d. `7 * 10 - 5 % 3 * 4 + 9`

## Instrucciones de entrada y salida

En C la entrada y salida de dos dispositivos estándar de entrada y salida, se denominan `stdin` y `stdout`, respectivamente. La salida normalmente es la pantalla de la computadora, la entrada se capta del teclado.

En el archivo de cabecera `stdio.h` están definidas macros, constantes, variables y funciones que permiten intercambiar datos con el exterior. A continuación se muestran las más habituales y fáciles de utilizar.

### Salida

La salida de los datos de un programa se pueden dirigir a varios dispositivos: pantalla, impresora, archivos. La función printf()  visualiza en pantalla datos del programa, transforma los datos, que están en una representación binaria a ASCII según los códigos transmitidos.

```c
suma = 0;
suma = suma + 10;
printf("%s %d","Suma = ",suma);
```

El número de argumentos en `printf()` es indefinido, por lo que se pueden transmitir cuantos datos se desee. Así, suponiendo que

```c
i = 5;
j = 12; 
c = 'A'; 
n = 40.791512;

printf("%d %d %c %f",i,j,c,n);
```

La forma general que tiene `printf()` es :

```c
printf("control_string", data1, data2, data3, ... );
```

`“control_string”` contiene los tipos de datos y la forma de mostrarlos; `data1`, `data2`, … son variables, constantes, datos de salida. printf() convierte, da forma de salida a los datos y los escribe en pantalla. La cadena de control contiene códigos de formato que se asocian a cada uno con los datos. Cada código comienza con el carácter %, a continuación puede especificarse el ancho mínimo del dato y termina con el carácter de conversión. Así, suponiendo que:

```c
i = 11; 
j = 12; 
c = 'A'; 
n = 40.791512;
printf( "%x %3d %c %.3f",i,j,c,n);
```

Visualizará en pantalla:

```bash
B 12 A 40.792    
```

El primer datos es un `11` en hexadecimal `%x`, el segundo es el número entero `12` en un ancho de `3`, le sigue el carácter `A` y, por último, el número real `n` redondeado de `3` cifras decimales (`%.3f`). Un signo menos a continuación de % indica que el dato se ajuste en forma predeterminada a la izquierda en vez del ajuste a la derecha.

```c
printf("%15s","Hola utemita");
printf("%-15s","Hola utemita");
```

Visualizará en pantalla:

```c
   Hola utemita
Hola utemita
```

los códigos de formato más utilizados y su significado:

| Código | Descripción |
| --- | --- |
| %d | El dato se convierte en entero decimal |
| %o | El dato entero se convierte a octal |
| %x | El dato entero se converte a hexadecimal |
| %u | El dato entero se convierte a entero sin signo |
| %c | El dato se considera de tipo carácter |
| %e | El dato se considera de tipo float. Se convierte a notación científica, de la forma {-}n.mmmmmmE{-|+}dd. |
| %f | El dato se considera del tipo float. Se convierte a notación decimal, con parte entera y los dígitos de precisión. |
| %g | El dato se considera de tipo float. Se convierte según el código %e o %f dependiendo de cual sea la representación más corta |
| %s | El dato ha de ser una cadena de caracteres |
| %lf | El datos se considera de tipo double |

C utiliza las secuencias de escape para visualizar caracteres que no están representados por símbolos tradicionales, como \a, \b, etc. Las secuencias de caracteres se muestran con anterioridad

### Entrada

La entrada de datos a un programa puede tener diversas fuentes, teclado, archivos en disco, etc. La entrada que se considera por el momento es la entrada por teclado, asociado al archivo estándar de entrada `stdin`. La función más utilizada, por su versatilidad, para entrada formateada es `scanf()`.

El archivo de cabecera stdio.h de la biblioteca de C proporciona la definición (el prototipo) de `scanf()`, así como de otras funciones de entrada o salida. La forma general que tiene la función `scanf()`:

```c
scanf(control_string, var1, var2, var3, …)
```

`control_string` contiene los tipos de datos y se desea su anchura. `var1, var2, …` variables del tipo de los códigos de control.

Los códigos de formato más comunes son los ya indicados en la salida. Se puede añadir, como sufijo del código, ciertos modificadores como `l` o `L`. El significado es “large”, aplicado a `float` (`%lf`) indica tipo `double`, aplicado a `int` (`%ld`) indica entero largo.

```c
int n;
double x;
scanf("%d %lf", &n, &x); 
```

La entrada tiene que ser de la forma

134 -1.4E-4

En este caso la función `scanf()` devuelve n=134 x=-1.4E-4 (en doble precisión). Los argumentos `var1, var2 …` de la función `scanf()` se pasan por dirección o referencia pues va a ser modificados por la función para devolver datos. Por esta razón requieren del operador de dirección, el prefijo `&`. 

## Salida de cadenas de caracteres

Con la función `printf()` se puede dar salida a cualquier tipo de dato, asociando el código que le corresponde. En particular, para dar salida a una cadena de caracteres se utiliza el código `%s,` Así:

```c
char tree[] = "Sauce"
printf("%s\n", tree);
```

Para la salida de cadenas, la biblioteca C proporciona la función específica `puts()`. Tienen un solo argumento, que es una cadena de caracteres. Escribe la cadena en la salida estándar (pantalla) y añade el fin de línea, de la siguiente forma:

```c
char tree[] = "Sauce"
puts(tree);
```

## Entrada de cadenas de caracteres

La entrada de cadena de caracteres se puede hacer con la función scanf() y el código %s. así, por ejemplo:

```c
char name[50];
printf("Nombre del atleta: ");
scanf("%s", name);
printf("Nombre del atleta: %s", nombre);
```

Si la entrada por teclado es el nombre:

```c
Lebron Jame
```

La salida será:

```c
Nombre del atleta: Lebron
```

La razón es porque `scanf()` con el código `%s` capta palabras, el criterio utilizado para terminación es el espacio en blanco, o bien fin de línea. Otro detalle es que la variable `name` no es precedida por `%`. En C el identificador de un arreglo, tiene la dirección del array, por lo que en `scanf()` se pone simplemente `name`.

La biblioteca de C tienen una función específica para captar cadenas de caracteres, la función `gets()`. Esta función capta del dispositivo estándar de entrada  una cadena de caracteres, termina con la captación con un retorno de carro. 

```c
char line[81];
puts("Nombre y dirección:");
gets(line);
```

La función gets() tiene un solo argumento, una variable de tipo cadena. Capta la cadena de entrada y la de vuelve en la variable pasada como argumento.

```c
gets(string_var);
```

Tanto `scanf()` como `gets()`, el programa inserta al final de la cadena el carácter que indica el final de la cadena, el carácter nulo `\0`. Siempre hay que definir las cadenas con un espacio demás de lo previsto como máxima longitud para el carácter fin de cadena.
