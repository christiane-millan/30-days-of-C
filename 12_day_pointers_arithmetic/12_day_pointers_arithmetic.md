# Día 12

[<< día 11](../11_day_pointers/11_day_pointers.md) | [Inicio](../README.md) | [día 13 >>](../13_day_dinamic_arrays/13_day_dinamic_arrays.md)

## Aritmética de apuntadores

La aritmética de apuntadores solo toma sentido en el contexto de arreglos.

## Comparación de apuntadores

Generalmente no es de interés conocer el valor específico de un apuntador. Sin embargo, se utilizan las operaciones de comparación sobre apuntadores para los siguiente:

- Es un apuntador igual o diferente a NULL

```c
if( p_dimension == NULL ) 
	printf( "p_dimension points to nothing!\n" );

if( p_dimension != NULL ) 
	printf( "p_dimension points to something!\n" );
```

- Es un apuntador igual o diferente a una posición nombrada

```c
if( p_dimension == &height ) 
  printf( "pDimension points to height.\n" );

if( p_dimension != &height ) 
  printf( "pDimension does not point to height!\n" );
```

- Es un apuntador igual o diferente a otro apuntador

```c
int* p_dim1 = NULL;
int* p_dim2 = NULL;
...
p_dim1 = &height;
p_dim1 = p_dim2;
...
p_dim2 = & weight;
...
if( p_dim1 == p_dim2 ) 
  printf( "pDim1 points to the same location as pDim2.\n" );
...
if( p_dim != p_dim2 ) 
  printf( "pDim1 and pDim2 are different locations.\n" );
```

Los apuntadores son operandos validos en expresiones aritméticas, expresiones de asignación y expresiones de comparación. Sin embargo, no todas las operaciones normalmente utilizadas en estas expresiones son validas en conjunciones con variables apuntadores. 

## Operadores permitidos para apuntadores

Un apuntador puede ser incrementado `++` o decrementado `--`, un entero puede ser sumado a un apuntador (`+` o `+=`), un entero puede ser sustraído de un apuntador (`-` o `-=`) o un apuntador puede ser sustraído de otro apuntador (esta operación tienen sentido solo cuando ambos apuntadores apuntan a elementos del mismo arreglo).

## Dirigiendo un apuntador a un arreglo

Un apuntador puede ser inicializado de dos formas para dirigirlo a un arreglo

```c
vPtr = v; 
vPtr = &v[0];
```

## Suma de un entero a un apuntador

En aritmética convencional, la suma de 3000 + 2 es igual a 3002. En el caso de apuntadores, cuando un entero es sumado o restado a un apuntador, el apuntador no incrementa o decrementa de acuerdo a los números enteros, si no que incrementa el entero multiplicado por el tamaño del objeto al cual apunta (el número de bytes depende del tipo de objeto)

```c
vPtr += 2;
```

## Sustracción de un entero a un apuntador

```c
vPtr -= 4;
```

## Incrementado y decrementado un apuntador

```c
++vPtr;
vPrt++;
--vPtr;
vPtr--;
```

## Sustracción de un apuntado a otro apuntador

```c
x = v3Ptr - vPtr;
```

Las  variables apuntador pueden ser restadas a otro apuntado. Si por ejemplo, vPtr contiene la locación 3000, y v2Ptr contiene la dirección 3008, la sentencia anterior asignara a x el número de elementos de un arreglo desde vPtr hasta v2Ptr, en este caso 2 (y no 8). La aritmética de apuntadores no esta definida a menos que se realice sobre un arreglo. No podemos asumir que dos variables de el mismo tipo estén almacenadas de manera contigua en la memoria a menos que sean elementos adyacentes de un arreglo

## Asignar un apuntador a otro apuntador

Un apuntador puede ser asignado a otro apuntador si ambos son del mismo tipo. La excepción a esta regla es el apuntador de tipo void., el cual es un apuntador genérico que puede representar un apuntador de cualquier tipo. Todos los tipos de apuntadores pueden ser asignados a un apuntador void, y un apuntador void puede ser asignado a cualquier tipo de apuntador (incluyendo el void). En ambos casos, una operación de cast no es necesaria.

Un apuntador void no puede ser de-referenciado, porque el compilador no sabe a que tipo de dato apunta.

## Comparación de apuntadores

Los apuntadores pueden ser comparados utilizando los operadores de igualdad y relacionales, pero tales comparaciones no tienen significado a menos que los apuntadores apunten al mismo arreglo. Las comparaciones de apuntadores comparan la dirección almacenada en el apuntador, Una comparación de dos apuntadores que apuntan a elementos en el mismo arreglo, puede mostrar, por ejemplo, que un apuntador apunta a un elemento con una numeración mayor en el arreglo que otro apuntador. Un uso común de la comparación de apuntadores es para conocer si apunta a NULL.

# Apuntadores y arreglos

Los apuntadores y los arreglos están relacionados en C y frecuentemente son intercambiables. Un nombre de arreglo puede ser visto com un apuntador constante. Los apuntadores pueden se utilizados para realizar cualquier operación que este relacionada con el indexado de arreglos.

Considerando las siguientes declaraciones 

```c
int b[5]; 
int *bPtr;
```

El nombre del arreglo `b` (sin un índice) es un apuntador al primer elemento del arreglo, por lo tanto se puede inicializar el apuntador con la dirección de `b`.

```c
bPtr = b;
```

o

```c
bPtr = &b[0];
```

## Notación de pointer/offset

El elemento `b[3]` puede ser referenciado de manera alterna con una expresión de apuntadores:

```c
*(bPtr + 3)
```

El `3` en la expresión es el índice para el apuntador. El paréntesis es necesario porque la precedencia del operador `*` es mayor que `+`.

Los apuntadores pueden ser indexados como arreglos. Si bPtr tiene el valor de b, la expresión

```c
bPtr[1] 
```

se refiere al elemento b[1] del arreglo.  Esta notación es referida como **pointer/index**.

<aside>
📌 El nombre de un arreglo siempre apunta al principio de un arreglo, por lo que el nombre del arreglo es como un apuntador constante. 
La expresión `b += 3` es inválida porque intente modificar el valor del nombre con un apuntador aritmético.

</aside>

Ejemplo de uso de index y offset:

```c
// Fig. 7.20: fig07_20.cpp
// Using indexing and pointer notations with arrays.
#include <stdio.h>
#define ARRAY_SIZE 4

int main(void) 
{
	int b[] = {10, 20, 30, 40}; // create and initialize array b
	int *bPtr = b; // create bPtr and point it to array b
	// output array b using array index notation
	puts("Array b printed with:\nArray index notation");
	// loop through array b
	for (size_t i = 0; i < ARRAY_SIZE; ++i) 
	{
		printf("b[%u] = %d\n", i, b[i]);
	}

	// output array b using array name and pointer/offset notation
	puts("\nPointer/offset notation where\n"
	"the pointer is the array name");
	// loop through array b
	for (size_t offset = 0; offset < ARRAY_SIZE; ++offset) 
	{
		printf("*(b + %u) = %d\n", offset, *(b + offset));
	}
	// output array b using bPtr and array index notation
	puts("\nPointer index notation");
	// loop through array b
	for (size_t i = 0; i < ARRAY_SIZE; ++i) 
	{
		printf("bPtr[%u] = %d\n", i, bPtr[i]);
	}
	// output array b using bPtr and pointer/offset notation
	puts("\nPointer/offset notation");
	// loop through array b
	for (size_t offset = 0; offset < ARRAY_SIZE; ++offset) 
	{
		printf("*(bPtr + %u) = %d\n", offset, *(bPtr + offset));
	}
}
```

Salida

```c
Array b printed with:
Array index notation
b[0] = 10
b[1] = 20
b[2] = 30
b[3] = 40
Pointer/offset notation where
the pointer is the array name
*(b + 0) = 10
*(b + 1) = 20
*(b + 2) = 30
*(b + 3) = 40
Pointer index notation
bPtr[0] = 10
bPtr[1] = 20
bPtr[2] = 30
bPtr[3] = 40
Pointer/offset notation
*(bPtr + 0) = 10
*(bPtr + 1) = 20
*(bPtr + 2) = 30
*(bPtr + 3) = 40
```

Otro ejemplo que permite mostrar el intercambio entre arreglos y apuntadores, se realiza la copia de cadenas. 

```c
// Fig. 7.21: fig07_21.c
// Copying a string using array notation and pointer notation.
#include <stdio.h>
#define SIZE 10

void copy1(char * const s1, const char * const s2); // prototype
void copy2(char *s1, const char *s2); // prototype

int main(void)
{
	char string1[SIZE]; // create array string1
	char *string2 = "Hello"; // create a pointer to a string
	copy1(string1, string2);
	printf("string1 = %s\n", string1);
	char string3[SIZE]; // create array string3
	char string4[] = "Good Bye"; // create an array containing a string
	copy2(string3, string4);
	printf("string3 = %s\n", string3);
}

// copy s2 to s1 using array notation
void copy1(char * const s1, const char * const s2)
{
	// loop through strings
	for (size_t i = 0; (s1[i] = s2[i]) != '\0'; ++i) {
		; // do nothing in body
	}
}

// copy s2 to s1 using pointer notation
void copy2(char *s1, const char *s2)
{
	// loop through strings
	for (; (*s1 = *s2) != '\0'; ++s1, ++s2) {
	; // do nothing in body
	}
}
```

## Apuntadores y arreglos

Se pueden direccionar arreglos como si fueran apuntadores y apuntadores como si fueran arreglos. El uso de apuntadores hace posible almacenar cadenas en elementos de un arreglo (no existe el tipo de dato cadena en C. No existen variables de cadena, solo constantes de cadena.

### Nombres de arreglos como apuntadores

Un nombre de arreglo es simplemente un apuntador.  Por lo tanto, para visualizar, almacenar o calcular un elemento de un arreglo, se puede utilizar la notación de subíndices o notación de apuntadores. Dado que un nombre de un arreglo contiene la dirección del primer elemento del arreglo, se debe indireccionar el apuntador para obtener el valor del elemento.

El nombre de un arreglo es un apuntador, contiene la dirección en memoria de comienzo de la secuencia de elementos que forma el arreglo. Es un apuntador constante ya no no se puede modificar, solo se puede acceder a el par indexar a los elementos del arreglo. 

```c
float v[10];
float *p;
float x = 100.5;
int j;

for (j = 0; j < 10; j++)
  *(v+j) = j*10.0;

p = v+4; 
v = &x;
```

### Ventajas de los apuntadores

Un nombre de un arreglo es una constante apuntador, no una variable apuntador. No se puede cambiar el valor de un nombre de arreglo, como no se pueden cambiar constates. Esto explica porque no se puede asignar valores nuevos a un arreglo durante la ejecución de una programa. Por ejemplo, si `c_name` es un arreglo de caracteres, la siguiente sentencia no es válida en C

```c
c_name = "Brothers company";
```

Se puede asignar valores al nombre de un arreglo solo en el moment de la declaración, o bien utilizando funciones especiales de cadena (`strcpy`).

Se pueden cambiar apuntadores para hacerlos apuntar a valores diferentes en memoria. el siguiente programa muestra cómo cambiar apuntadores. 

```c
#include <stdio.h>
   int main()
   {
			float v1 = 756.423;
			float v2 = 900.545;
			float *p_v;
			p_v = &v1;
			printf("El primer valor es %f \n",*p_v); /* se imprime 756 423 */
      p_v = &v2;
      printf("El segundo valor es %f \n",*p_v);/* se imprime 900 545 */
      return 0;
}
```

Por esta facilidad se utilizan apuntadores en lugar de arreglos, como los arreglos son fáciles de declarar, después de que se declaran se utilizan apuntadores para referenciar los elementos de dicho arreglo.

[<< día 11](../11_day_pointers/11_day_pointers.md) | [Inicio](../README.md) | [Día 12](#día-12) | [día 13 >>](../13_day_dinamic_arrays/13_day_dinamic_arrays.md)