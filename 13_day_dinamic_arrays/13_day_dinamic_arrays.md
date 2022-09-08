# Día 13

[<< día 12](../12_day_pointers_arithmetic/12_day_pointers_arithmetic.md) | [Inicio](../README.md) | [día 14 >>](../14_day_recursion/14_day_recursion.md)

# Asignación dinámica de la memoria

En muchas situaciones no se conoce la memoria necesaria hasta el momento de la ejecución. Por ejemplo, para almacenar una cadena de caracteres ingresada por el teclado, no se puede prever a priori, el tamaño del arreglo necesario, a menos que se reserve un arreglo de gran dimensión y se malgaste memoria cuando no se utilice. El método para resolver este inconveniente es recurrir a los apuntadores y a las técnicas de asignación dinámica de memoria.

Es espacio de la variable asignada dinámicamente se crea durante la ejecución del programa, y se tiene un control directo sobre los requisitos de memoria del programa. El programa puede crear o destruir la asignación dinámica en cualquier momento de la ejecución. Se puede determinar la cantidad de memoria necesaria en el momento en que se haga la asignación. 

El código de programa compilado se sitúa en un área denominada segmentos de código. Los datos del programa, como variables globales, se sitúan en un área denominada pila. La memoria que queda se denomina memoria de montículo o almacén libre Cuando el programa solicita memoria para una variable dinámica, se asigna el espacio de memoria deseado desde el montículo.

## Almacén libre (free store)

El almacén libre (heap) se refiere al área de memoria que existe dentro de la pila del programa, y el almacén libre es, esencialmente, toda la memoria que queda libre después de que se carga el programa.

En C las funciones `malloc()`, `realloc()`, `calloc()` y `free()` asignan y liberan memoria de un bloque de memoria denominado montículo del sistema. Las funciones `malloc()`, `calloc()` y `realloc()` asignan memoria utilizando asignación dinámica debido a que pueden gestionar la memoria durante la ejecución de un programa; estas funciones requieren, moldeado (conversión de tipos).

### Asignación de memoria con `malloc()`

La función `malloc()` asigna un bloque de memoria que es el número de bytes pasados como argumento, `malloc()` devuelve un apuntador, que es la dirección del bloque asignado de memoria. El apuntador se utiliza para referenciar el bloque de memoria; devuelve un apuntador de tipo `void*`. La forma de llamar a la función `malloc()` es:

```c
puntero = malloc(tamaño_en_bytes);
```

Generalmente se hará una conversión al tipo del apuntador:

```c
tipo *puntero;
puntero = (tipo *) malloc(tamaño_en_bytes);
```

Por ejemplo;

```c
long *p;
p = (long *) malloc(32);
```

El operador `sizeof` se utiliza con mucha frecuencia en las funciones de asignación de memoria. El operador se aplica a un tipo de dato( o una variable), el valor resultante es el número de bytes que ocupa. Así, si se quiere reservar memoria para un buffer de 10 enteros:

```c
int *r;
r = (int *)malloc(10 * sizeof(int));
```

Al llamar a la función `malloc()` puede ocurrir que no haya memoria disponible, en ese caso `malloc()` devuelve `NULL`.

<aside>
📌 **A recordar**

Sintaxis de llamada a `malloc( )`

`tipo *puntero;`
`puntero =(tipo*)malloc(tamaño);`

La función devuelve la dirección de la variable asignada dinámicamente, el tipo que devuelve es `void*`.

Prototipo que incluye `malloc( )`

```c
void* malloc(size_t n);
```

</aside>

En la sintaxis de llamada, apuntador es el nombre de la variable apuntador a la que se le asigna la dirección del objeto dato, o se le asigna la dirección de memoria de un bloque suficientemente grande para contener un arreglo de n elementos, o `NULL` si falla la operación de asignación de memoria. El siguiente código utiliza `malloc()` para asignar espacio para un valor entero:

```c
int *p_int;
...
p_int = (int*) malloc (sizeof(int));
```

La llamada a `malloc()` asigna espacio para un `int` y almacena la dirección de la asignación en `p_int`. `p_int` apunta ahora a la posición en el almacén libre (montículo) donde se establece la memoria. 

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/60d93196-87a9-4f75-a076-e6a565e4681c/Untitled.png)

Para reservar memoria para un arreglo de 100 números reales:

```c
float *p_mem;
p_mem = (float *) malloc (100 * sizeof(float));
```

En el ejemplo anterior se declara un apuntador denominado `p_mem` y se inicializa a la dirección devuelta por `malloc()`. Si un bloque del tamaño solicitado está disponible, `malloc()` devuelve el apuntador al principio del bloque de memoria de tamaño especificado. Si no hay bastante espacio de almacenamiento dinámico para cumplir la petición, `malloc()` devuelve cero o `NULL`. La reserva de $n$ caracteres se puede escribir así:

```c
int n;
char *s;
...
scanf("%d", &n);
s = (char *) malloc(n * sizeof(char));
```

La función malloc() esta declarada en el archivo de cabecera `stdlib.h`.

Ejemplo. Leer una línea de caracteres, reserva memoria para un buffer de tantos caracteres como los caracteres leídos y copiar en el buffer de la cadena.

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main( ) 
{
	char cad[121], *ptr;
  int lon;

	puts("\nIntroducir una línea de texto\n");
	gets(cad);
	lon = strlen(cad);

	ptr = (char*) malloc((lon+1) * sizeof(char));
	strcpy(ptr, cad);
  printf("ptr = %s",ptr);
  free(ptr);
}
```

Es responsabilidad del programador comprobar que el apuntador es válido, ejemplo:

```c
#define TOPE 1999
  
double *ptr_lista;  
int i;
  
ptr_lista = (double*) malloc(1000*sizeof(double));  
if (ptr_lista==NULL)  
{
    puts("Error en la asignación de memoria");
    return −1; /* Intentar recuperar memoria */  
}
  
for ( i = 0; i < 1000; i ++)
    ptr_lista [i] = (double) *random (TOPE);
```

<aside>
📌 **A recordar**

Si no existe espacio de almacenamiento suficiente, la función `malloc( )` devuelve `NULL`. La escritura de un programa totalmente seguro, exige comprobar el valor devuelto por `malloc( )` para asegurar que no es `NULL`. `NULL` es una constante predefinida en C. Se debe incluir el archivo de cabecera `<stdlib.h>` para obtener la definición de `NULL`.

</aside>

Ejemplo. Este programa comprueba la cantidad de memoria que se puede asignar dinámicamente (disponible). Para ello se llama a `malloc()`, solicitando en cada llamada 1000 bytes.

```c
/*
    programa para determinar memoria libre.
  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    void *p;
    int i;
    long m = 0;
    for (i = 1;; i++)
    {
        p = malloc(1000);
        if (p == NULL)
            break;
        m += 1000;
    }
    printf("\nTotal de memoria asignada  %d\n", m);
```

## Asignación de memoria de un tamaño desconocido

Para obtener memoria para un arreglo se invoca a `malloc()` en tiempo de ejecución, pasando como argumento el número de elementos del arreglo multiplicado por el tamaño del tipo del arreglo. El número de elementos se puede solicitar al usuario y leerse en tiempo de ejecución. Por ejemplo, el siguiente segmento de código se asigna memoria para un arreglo de `n` elementos de tipo double, el valor de `n` se conoce en tiempo de ejecución:

```c
double *ad;
int n;

printf("Número de elementos del array:"); 
scanf("%d",&n);

ad = (double*)malloc(n*sizeof(double));
```

# Arreglos dinámicos de dos dimensiones

Un arreglo bidimensional es, en realidad, un arreglo cuyos elementos son arreglos. Al ser el nombre de un arreglo unidimensional un apuntador constante, una arreglo bidimensional será un apuntador a apuntador constante `(tipo **)`. Para asignar memoria a un arreglo bidimensional. 

En el siguiente ejemplo se reserva memoria en tiempo de ejecución para una matriz de n filas y m elementos en cada fila.

El siguiente programa crea una matriz de n x m y leer los elementos del dispositivo de entrada (teclado)

```c
/* matriz de n filas y cada fila de un número variable de elementos */ 
#include <stdio.h>
#include <stdlib.h>
int main( )
{
	int **p;
  int n,m,i;
      
	do {        
		printf("\n Numero de filas: "); scanf("%d",&n);      
	} while (n <= 0);
      
	p = (int**) malloc(n*sizeof(int*));    
	for (i = 0; i < n; i++)      
	{        
		int j;    
		printf("Número de elementos de fila %d ",i+1);        
		scanf("%d",&m);        
		p[i] = (int*)malloc(m*sizeof(int));        
		for (j = 0; j < m; j++)        
			scanf("%d",&p[i][j]);
	}
	return 0; 
}
```

## La función `free()`

Al terminar de utilizar un bloque de memoria que fue asignado previamente por malloc(), o alguna otra función de asignación, se puede liberar el espacio de memoria y dejarlo disponible nuevamente,  mediante la función `free()`. 

```c
int *ad;
ad = (int*)malloc(sizeof(int));

char *adc;
adc = (char*) malloc(100*sizeof(char));

free(ad);
free(adc);
```

## Funciones de asignación `calloc()` y `realloc()`

Además de `malloc()` se puede obtener memoria con `calloc()` y `realloc()`. Con ambas funciones cambia la forma de transmitir el número de bytes de memoria requeridos. Ambas devuelven un apuntador al bloque asignado de memoria. 

Ejemplo de uso de `calloc()` donde se reserva memoria para `5` datos de tipo `double`.

```c
#define N 5

double* pd;
pd = (double*) calloc(N, sizeof(double));
```

En el siguiente ejemplo se reserva memoria para una cadena variable

```c
char *c, B[121];
puts("Introduce una línea de caracteres.");
gets(B);

/* Se reserva memoria para el número de caracteres + 1 para el carácter
       fin de cadena.*/
c = (char*) calloc(strlen(B)+1,sizeof(char));   
strcpy(c,B);
```

Ejemplo, en el siguiente programa se considera una secuencia de números reales con una variable apuntador a float se procesa un arreglo de longitud variable, de modo que se puede ajustar la cantidad de memoria necesaria para el número de valores durante la ejecución del programa. 

```c
#include <stdlib.h>
#include <stdio.h>
   
int main(void)   
{
	float *pf = NULL;
	int num, i;
      
	do
	{
		printf("Número de elementos del vector: ");
		scanf("%d",&num);
 	} while (num < 1);
        
	/* Asigna memoria: num*tamaño bytes */
	pf = (float *) calloc(num, sizeof(float));
	if (pf == NULL)
	{
		puts("Error en la asignación de memoria.");
		return 1; 
	}
	printf("\n Introduce %d valores ",num);
	for (i = 0; i < num; i++)
		scanf("%f",&pf[i]);
	/* proceso del vector */
	/* liberación de la memoria ocupada */

	free(pf);
	return 0;
}
```

La función realloc presenta una variante respecto a malloc() y calloc(), ya que permite ampliar un bloque de memoria reservado anteriormente. 

Ejemplo, se reserva memoria para una cadena y a continuación se incrementa para almacenar otra cadena más larga.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( )
{
	char *cadena;
	int tam;
	tam = (strlen("Primavera")+1)*sizeof(char);
	cadena = (char*)malloc(tam); 
	strcpy(cadena, "Primavera"); 
	puts(cadena);
        
	/* Amplía el bloque de memoria */
     
	tam += (strlen(" en Lupiana\n")+1)*sizeof(char);
	cadena = (char *) realloc(cadena, tam);
	strcat(cadena," en Lupiana\n");
	puts(cadena);
	/* Se libera memoria */
	free(cadena);
	return 0;
}
```

El segundo argumento de `realloc()` es el tamaño total que va a tener el bloque de memoria libre. Si se pasa `0` como tamaño se libera el bloque de memoria que esta apuntado el apuntador y la función devuelve `NULL`. 

Es necesario tener en cuenta que la expansión de memoria que realiza `realloc()` se puede hacer en una dirección de memoria diferente a la original, por lo que `realloc()` copia los datos referenciados por el apuntador en la nueva memoria expandida.

## Ejercicios

11.1. En el siguiente código se accede a los elementos de una matriz. Acceder a los mismos elementos con aritmética de aputadores

```c
#define N 4
#define M 5
int f,c;
double mt [N] [M];
.. .
for (f = 0; f < N; f++) {
	for (c = 0; c < M; c++)
		printf("%lf ", mt[f][c]);
		printf("\n");
}
```

11.2. Escribir una función con un argumento de tipo apuntador a `double` y otro argumento de tipo `int`. El primer argumento se debe de corresponder con un arreglo y el segundo con el número de elementos del arreglo. La función ha de ser de tipo apuntador a `double` para devolver la dirección del elemento menor.

## Problemas

En todos los problemas utilizar siempre que sea posible apuntadores para acceder a los elementos de los arreglos, tanto numéricos como cadenas de caracteres.

11.1. Escribir un programa en el que se lan 20 líneas de texto, cada línea con un máximo de 80 caracteres. Mostrar en pantalla el número de vocales que tiene cada línea.

11.2. Escribir un programa que encuentre una matriz de números reales simétrica. Para ello, una función entera con entrada a la matriz determinará si ésta es simétrica. En otra función se generá la matriz con números aleatorios de 1 a 9.

Utilizar la aritmética de apuntadores en la primera función, en la segunda indexación.

11.3. Se quiere evaluar las funciones $f(x)$, $g(x)$ y $z(x)$ para todos los valores de $x$ en el intervalo $0 \leq x < 3.5$ con incremento de $0.2$. Escribir un programa que evalué dichas funciones, utilizando arreglos de apuntadores a función. Las funciones son las siguiente:

$f(x) = 3 \times e^{x-1} -2x$

$g(x) = -x \times sin(x) + 1.5$

$z(x) = x^2 -2x + 3$

11.4. Se quieren sumar enteros largos, con un número de dígitos que superan el máximo de entero largo. Los enteros tienen un máximo de 40 dígitos. Para resolver el problema se utilizan cadenas de caracteres para guardar cada entero y realizar la suma. Escribir un programa que lea dos enteros largos y realice la suma.

11.5. Escribir una función que tenga como entrada una cadena y devuelva un número real. La cada contiene los caracteres de un número real en formato decimal (por ejemplo, la cadena “25.56” se ha de convertir en el correspondiente valor real).

11.6. Escribir un programa para generar una matriz de 4 x 5 elementos reales, multiplicar la primera columna por cualquier otra y mostrar la suma de los productos. El programa debe descomponerse en subproblemas y utilizar apuntadores para acceder a los elementos de la matriz.

11.7. Escribir un programa que permita calcular el área de diversas figuras: un triángulo rectángulo, un triángulo isósceles, un cuadrado, un trapecio y un círculo. Utilizar un arreglo de apuntadores de funciones; estas últimas son las que permiten calcular el área.

11.8.Se tiene una matriz de 20 × 20 elementos enteros. En la matriz hay un elemento repetido muchas veces. Se quiere generar otra matriz de 20 filas y que en cada fila estén sostenidos solo los elementos no repetidos. Escribir un programa que tenga como entrada la matriz de 20 × 20; genera la matriz dinámica perdida y que se muestre en pantalla.

11.9. Escribir un programa para generar una matriz simétrica con números aleatorios de 1 a 9. El usuario introduce el tamaño de cada dimensión de la matriz y el programa reserva memoria libre para el tamaño requerido.

[<< día 12](../12_day_pointers_arithmetic/12_day_pointers_arithmetic.md) | [Inicio](../README.md) | [día 13](#día-13) | [día 14 >>](../14_day_recursion/14_day_recursion.md)