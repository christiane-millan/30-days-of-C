# Día 11

[<< día 10](../10_day_array_strings/10_day_strings.md) | [Inicio](../README.md) | [día 12 >>](../12_day_pointers_arithmetic/12_day_pointers_arithmetic.md)

- [Día 11](#día-11)
  - [Apuntadores](#apuntadores)
    - [Declaración de un apuntador](#declaración-de-un-apuntador)
    - [Nombrado de apuntadores](#nombrado-de-apuntadores)
    - [Asignación de valores apuntador (direcciones)](#asignación-de-valores-apuntador-direcciones)
  - [Operadores de apuntadores](#operadores-de-apuntadores)
    - [Asignación de valores apuntador `&`](#asignación-de-valores-apuntador-)
    - [Verificación de tipos](#verificación-de-tipos)
    - [Diferencia entre apuntar a NULL o void*](#diferencia-entre-apuntar-a-null-o-void)
    - [El tipo void*](#el-tipo-void)
    - [Acceso al objetivo apuntado `*`](#acceso-al-objetivo-apuntado-)

## Apuntadores

Los apuntadores tienen más mala fama que complejidad, tanto en aprendizaje como en su uso no son más difíciles de aprender que cualquier otra herramienta de programación.

Un apuntador es una variable que almacena un valor que es la localización (dirección de memoria) de otra variable. El tipo apuntador no solo identifica la variable como un apuntador, si no que también específica que tipo de valor será accesado en la localización guardada por el apuntador.

Los apuntadores en C son una de las características más poderosas en C. Grandes poderes vienen con grandes responsabilidades.  Esa responsabilidad no es más que conocer cómo utilizarlos correctamente y usar ese poder que ha sido dado apropiadamente. Esta responsabilidad involucra conocer cuándo utilizar ese poder y entender sus limites.

**Usos principales de apuntadores:**

- Para resolver las **restricciones de las llamadas por valor de los parámetros de una función**
- Como una **alternativa a los índices de los arreglos**
- Para el **manejo de cadenas**
- Para el **uso de datos estructurados dinámicos**

### Declaración de un apuntador

```c
type *identifier
```

Ejemplos:

```c
int height;
int width;
int length;

int *p_dimension;
```

`p_dimension` puede almacenar la dirección de cualquier variable de tipo entero. No puede almacenar la dirección de variables de otro tipo( `float`, `double`, `char`). El tipo de `p_dimension` es `int*`.

### Nombrado de apuntadores

Como los apuntadores guardan direcciones de valores y no el valor deseado en si mismo, es una buena idea diferenciar entre ellos mediante el nombrado de los apuntadores. Existen diferentes convenciones:

```c
int an_integer;

int *ptr_an_integer;  // prefix ptr-
int *p_an_integer;    // prefix p- (shorthand)
int *an_integer_ptr;  // suffix -Ptr
int *an_integer_p;    // suffix -P (shorthand)
```

La recomendación es elegir un solo estilo y utilizarlo de manera uniforme en todo el programa.

### Asignación de valores apuntador (direcciones)

Una variable apuntador almacena la dirección de otra posición nombrada (variable). Ese es el objetivo de una apuntador. Un apuntador apunta a otra posición de una variable. Ese valor de la variable es su objetivo. La forma de asignar un valor de dirección a un apuntador es usar el operador `&` y el identificador de la variable:

```c
int height;
int *p_dimension;

p_dimension = &height;
```

Otros ejemplos

```c
int edad = 50;
int *p_edad = &edad;

char *p;
char alfa = 'A';
p = &alfa;

char cd[ ] = "Compacto";
char *c;
c = cd;
```

## Operadores de apuntadores

Las operaciones que trabajan con operadores son:

- Asignación
- Acceso al objetivo apuntado
- Aritméticas de apuntador limitadas
- La comparación de apuntadores

### Asignación de valores apuntador `&`

```c
int height;
int width;
int length;
int* p_dimension;

p_dimension = &height;
```

Después se puede reasignar el valor de `p_dimension`

```c
p_dimension = &width;
```

<aside>
📌 Es un error asignar un valor a un contenido de una variable puntero si previamente no se ha inicializado con la dirección de una variable.

</aside>

Por ejemplo:

```c

float* px; 
*px = 23.5;
```

### Verificación de tipos

Los apuntadores se enlazan a tipos de datos específicos, es decir, que C verifica que se asigna la dirección de un tipo de dato al tipo correcto de un apuntador. Así, por ejemplo, si se define un apuntador a float, no se puede le puede asignar la dirección de un char o un int. Por ejemplo: este segmento de código no funcionará.

```c
float *fp;
char c;
fp = &c;
```

### Diferencia entre apuntar a NULL o void*

Una variable apuntador siempre debe tener una valor asignado. Su valor nunca debe ser desconocido. Sin embargo, algunas ocasiones un apuntador no tienen asignada una dirección o aun no es conocida. En este caso, se utiliza la constante `NULL`. Este valor esta definido en `stddef.h`, `stdio.h`, `stdlib.h` y `string.h` ; y representa un valor de `0`. Se define como:

```c
#define NULL ((void*)0)
```

Aquí, `(void*)` especifica un apuntador del tipo `void`. El tipo `void` representa no tipo- un tipo desconocido o un valor no existente. No se puede asignar a una variable para tener el tipo `void`, pero una función puede retornar `void` (nada). Esta función lo que retorna es `void`. 

### El tipo void*

El tipo apuntador `void*` representa un genérico, en otras palabras un apuntador donde en su declaración se desconoce su tipo. Entonces, cualquier tipo de apuntador puede ser asignado a un apuntador de tipo `void*`. Sin embargo, antes de que la variable apuntador sea accesada, el tipo de dato a ser accesado debe ser especificado a través de un operador de casting.

```c
void* a_ptr = NULL;  // we don't yet know what it points to.
...
a_ptr = &height;     // it has the address of height, but no type yet.
...
int h = (int) *a_ptr; // with casting, we can now go to that address
                    // and fetch an integer value.
```

Para asignar `NULL`

```c
int* pDimension = NULL;
...
pDimension = &height;
...
pDimenions = NULL;
```

### Acceso al objetivo apuntado `*`

Un apuntador debe conocer el tipo de valor que apunta para que pueda ser correctamente tomado el número de bytes de ese valor. Sin un tipo de dato asociado, el acceso del apuntador no sabría cuántos bytes usar cuando retorne un valor. Por ejemplo, un valor `int` es 4 bytes. Un apuntador entero (8 bytes) entonces iría a su dirección y tomaría 4 bytes a retornar un valor `int` en el rango correcto.

Para acceder a un valor de forma indirecta a través de un apuntador, se debe dereferenciar el apuntador. Es decir, se debe usar la dirección almacenada en la variable apuntador para tomar el valor que apunta. Para asignar un valor a el objetivo del apuntador, se utilizar el operador `*`:

```c
int  height;
...
int *p_dimension = &height;
...
height = 10;
...
*p_dimension = 15;
```

<aside>
📌 Nótese que el operador `*` es utilizado en la declaración del apuntador y en la de-referencia del apuntador.

</aside>

La de-referencia puede ser utilizada para acceder a valores:

```c
p_dimension = &height;
int a_measure;
...
a_measure = height;
...
a_measure = *p_dimension;
```

Con la finalidad de imprimir la dirección y el valor objetivo de `p_dimension`:

```c
#include <stdio.h>
int main( void )
{
  int height = 10;
  int width  = 20;
  int length = 40;
  int* p_dimension;
  
  printf( "  sizeof(int) = %2lu\n" , sizeof(int) );
  printf( "  sizeof(int*) = %2lu\n" , sizeof(int*) );
  printf( "  [height, width, length] = [%2d,%2d,%2d]\n\n" ,
             height , width , length );
  printf( "  address of p_dimension = %#lx\n" ,
             (unsigned long)&p_dimension  );

  p_dimension = &height;
  printf( "  address of height = %#lx, value at address = %2d\n" ,
             (unsigned long)p_dimension , *p_dimension );
  p_dimension = &width;
  printf( "  address of width  = %#lx, value at address = %2d\n" ,
             (unsigned long)p_dimension , *p_dimension );
  p_dimension = &length;
  printf( "  address of length = %#lx, value at address = %2d\n" ,
             (unsigned long)p_dimension , *p_dimension );
}
```

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/f20bd494-e0cf-461a-b6ee-c7ca53748903/Untitled.png)

Las direcciones de memoria están especificadas en hexadecimal. Un diagrama de memoria luce de la siguiente manera:

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/8016408c-ba61-4321-b0db-e5c014e238a6/Untitled.png)

Otro ejemplo, con la demostración del uso de los operadores `&` y `*` 

```c
// Fig. 7.4: fig07_04.c
// Using the & and * pointer operators.
#include <stdio.h>

int main(void) 
{
	int a = 7;
	int *aPtr = &a; // set aPtr to the address of a10

	printf("The address of a is %p"
					"\nThe value of aPtr is %p", &a, aPtr);
	printf("\n\nThe value of a is %d"
					"\nThe value of *aPtr is %d", a, *aPtr);
	printf("\n\n The address of aPtr is %p", &aPtr);
	printf("\n\nShowing that * and & are complements of " 
	        "each other\n&*aPtr = %p"
					"\n*&aPtr = %p\n", &*aPtr, *&aPtr);
}
```

Resultado de la ejecución

```c
The address of a is 0028FEC0
The value of aPtr is 0028FEC0
The value of a is 7
The value of *aPtr is 7
Showing that * and & are complements of each other
&*aPtr = 0028FEC0
*&aPtr = 0028FEC0
```

[<< día 10](../10_day_array_strings/10_day_strings.md) | [Inicio](../README.md) | [día 11](#día-11) | [día 12 >>](../12_day_pointers_arithmetic/12_day_pointers_arithmetic.md)