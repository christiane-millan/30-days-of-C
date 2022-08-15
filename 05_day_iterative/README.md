# Día 5

* [Estructuras Iterativas](#estructuras-iterativas)
  * [While](#while)
  * [Do While](#do--while)
  * [For](#for)
* [Ejercicios](#ejercicios)
* [Problemas](#problemas)

## Estructuras iterativas

Algunas operaciones necesitan ser repetidas más de una vez antes de mostrar un resultado. El código puede ser copiado el número de veces requerido, pero esto puede resultar muy complicado. En su lugar, para esto, se utilizan los ciclos —`for …`, `while …`, `do …while` . Los ciclos son sentencias que deben ser evaluados múltiples veces.

Existen dos tipos generales de expresiones de continuación utilizados para declaraciones de ciclos:

* Ciclado **controlado por contado**r, donde el número de iteraciones dependen de un contador de algún tipo. El número deseado de iteraciones es conocido de forma previa. El contador puede incrementarse o decrementarse.
* Ciclado por **condiciones** o controlado por un **centinela**, donde el número de iteraciones depende de alguna condición para mantener true en el ciclo para continuar. El número actual de iteraciones no es conocido. Un centinela es un valor que debe ser alcanzar un cierto estado antes de que el ciclo se complete.

## While

Un bucle `while()…` tiene una condición (expresión lógica) que controla la secuencia de repetición. La posición  de esta condición es delante del cuerpo del bucle y significa que un ciclo while()… es pretest, es decir, que cuando se ejecuta, se evalúa la condición antes de que se ejecute el cuerpo del bucle. La figura 6.1. representa el diagrama del bucle `while()…`.

La sintaxis para el `while()…`

```c
while (continuation_expression)
	statement_body
```

```c
while (continuation_expression)
{
	statement_body
}
```

`continuation_expresison` es evaluada. Si el resultado es `true`, `estatement_body` es ejecutado y el proceso se repite. Cuando la `continuation_expression` evalúa `false`, el ciclo termina. La ejecución se continua después del `statement_body`. Si continuatio`n`_expression inicialmente evalúa `false`, el ciclo del `statement_body`  nunca se ejecuta.

El `statemente_body` es (o puede ser) una sola declaración, o incluso una declaración `null` ( un `;` sin una expresión), pero frecuentemente, es una declaración compuesta. En la declaración del `while ()…` no existe punto y coma. Un punto y coma puede aparecer como única declaración de un `statement_body`, o puede estar ausente en el caso que el `statement_body` consista en un declaración compuesta `{…}`. 

Otro aspecto importante a considerar, es que debe existir un cambio en el `statement_body` de los valores que son usados en el `continuation_expression`. Si no, el ciclo nunca terminara de ejecutarse una vez que comience. Esta situación se le conoce como loop infinito. Por lo tanto, en un contador controlador de ciclo, el contador debe cambiar en alguna parte del cuerpo del ciclo.

En otras palabras el comportamiento o funcionamiento de la sentencia `while()…` es:

1. Se evalua `continuation_expression`
2. Si `continuation_expression` es `true` (o distinta de cero):
    1. La sentencia statement_body, denominada cuerpo se ejecuta.
    2. Devuelve el control al paso 1
3. En caso contrario:
    1. Se transfiere a la sentencia siguiente al ciclo o sentencia `while()…`

Ejemplo: Visualizar n asteriscos

```c
count = 0;
while (count < n)
{
	printf(" * ");
	count++;
}
```

Es importante considerar que la variable que representa continuation_expression también se denomina variable de control del bucle debido a que si valor determinar si el cuerpo del bucle se repite. La variable de control debe ser: 1. Inicializada. 2. Comprobada. 3. Actualizada para que el statement_body se ejecute adecuadamente. 

Cada etapa del ejemplo anterior se resume en:

1. Inicialización `count` se establece a un valor inicial (se inicializa en cero, aunque podría ser otro valor) antes de que se alcance la sentencia `while`.
2. Prueba/condición de `continuation_statement`. Se comprueba el valor del `count` antes de que comience la repetición de cada ciclo (denominada iteración).
3. Actualización. `count` se actualiza ( se valor se incrementa en 1, mediante el operador ++) durante cada iteración.

Si la variable de control no se actualiza el bucle se ejecutará “siempre”. A este tipo de ciclos se les conoce como ciclo infinito. En otras palabras, un ciclo infinito se produce cuando la condición del bucle permanece y no se hace falsa en ninguna iteración.

Ejemplo bucle infinito:

```c
count = 1;
while (count < 100)
{
	printf("%d \n", count);
	count--;
}
```

La variable `count` se inicializa a 1 (menor que 100) y como `count` se decrementa en 1 el valor de `count` nunca llegará a ser 100, valor necesario de `count` para que la condición del ciclo sea `false`. Por lo tanto, la condición `count < 100` siempre será `true`, resultando en un bucle infinito.

Ejemplo: Contar rangos (Gauss).

```c
int sum = 0;
int num = 0;

while( num < N ) // num: 0..99 (100 is not less than 100)  
{
	sum += (num+1); // Off-by-one: shift 0..99 to 1..100.
	num++;
}
```

El problema off-by-one, como el contador comienza en 0 y va hasta N-1, para alcanzar N iteraciones. Se puede comenzar en 1 y revisar si el contador es menor a N+1. O se puede comenzar también en 0 y revisar que el contador sea menor o igual a N ( En este caso ocurriría una iteración de más).

Existe una razón para comenzar un contador en 0 y no en uno, la cual será muy util para temas futuros.

Otra forma de realizar esto, es realizar una implementación en cuenta regresiva, comenzando de N hasta 1, y parar cuando lleguemos a 0. La `continuation_expression` evalúa si N es diferente de cero. Se podría utilizar `while (N > 0)`. Otra forma sería:

```c
int sum = 0;
	while( N )  {      // N: N down to 1 (stops at 0).
		sum += N;
    N--;
  }
```

¿Qué enfoque es mejor? En realidad son iguales, para este problema sencillo. Cuando del `statemente_body` se vuelva más complejo, un enfoque puede resultar más claro que el otro. El punto aquí es mostrar que existen diferentes formas de solucionar el problema y que esto puede facilitar la implementación o la claridad del código. La diferencia radica en la forma que se implementa el contador.

Otro ejemplo del uso de `while()…`

```c
/* El programa realiza un cálculo de calorías */
#include <stdio.h>

int main()
{
	int num_de_elementos, cuenta, calorias_por_alimento, calorias_total;
  printf("¿Cuántos alimentos ha comido hoy? ");
  scanf("%d", &num_de_elementos);
  
	calorias_total = 0;
	cuenta = 1;
    
	printf("Introducir el número de calorias de cada uno de los ");
  printf("%d %s", num_elementos, "alimentos tomados: \n");  
	while (cuenta++ <= num_de_elementos)
  {
		scanf("%d", &calorias_por_alimento);
    calorias_total += calorias_por_alimento;
	}

  printf("Las calorias totales consumidas hoy son = ");
  printf("%d \n", calorias_total);
  
	return 0;
}
```

### Diseño eficiente de bucles

Bucle while con cero iteraciones

```c
contador = 10;
while (contador > 100)
{
... 
}
```

Bucles controlados por centinelas

```c
/* entrada de datos numéricos, centinela −1 */
              
const int centinela = −1;              

printf("Introduzca primera nota:");              
scanf("%d",&nota);
              
while (nota != centinela)             
{                 
	cuenta++;                 
	suma += nota;                 
	printf("Introduzca siguiente nota: ");                 
	scanf("%d",&nota);              
} /* fin de while */
              
puts("Final");
```

Bucles controlados por indicadores (banderas)

```c
digito_leido = 0; /* no se ha leído ningún dato */

while (!digito_leido)
{
    printf("Introduzca un carácter: ");
    scanf("%c",&car);
    digito_leido = (('0' <= car) && (car <= '9'));
    ...
 } /* fin de while */
```

Ejemplo. Se desea leer un dato numérico x cuyo valor ha de ser mayor que cero para calcular la función $f(x) = x * log(x)$

```c
#include <stdio.h> 
#include <math.h> 
int main()
{
  float f,x;
  int x_positivo;
  x_positivo = 0; /* inicializado a falso */
  while (!x_positivo)
	{
		printf("\n Valor de x: ");        
		scanf("%f",&x);        
		x_positivo = (x > 0.0); /* asigna verdadero(1) si cumple la condición */      
	}
     
	f = x * log(x);
	printf(" f(%.1f) = %.3e",x,f);
	return 0;
}
```

## do … while()

La sentencia `do … while()` se utiliza para especificar que un bucle condicional se ejecute al menos una vez y tiene la siguiente sintaxis:

```c
do statement_body while( continuation_expression );
```

```c
do 
	statement_body 
while( continuation_expression );
```

La única diferencia entre esta sentencia de control y el `while()..` es que en el `do … while()`, el `statement_body` es ejecutado antes de que `continuation_expression` sea evaluado. Si la `continuation_expression` resulta `true`, el ciclo se repite.

Cuando `continuation_expression` evalúa `false`, el ciclo termina. Nótese también el punto y coma de terminación. Si `continuation_expression` inicialmente evalúa `false`, el `estatement_body` es ejecutado una sola vez.

La semántica del bucle `do…while()` se representa de la siguiente forma:

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/37894672-54b2-42c3-ae58-084559082307/Untitled.png)

Ejemplo para introducir un dígito

```c
do 
{           
	scanf("%c",&digito);         
} while ((digito < '0') || ('9' < digito));
```

Ejemplo para contar de 0 a  9

```c
int x = 0; 
do   
	printf("X: %d",x++);
while (x < 10);
```

Ejemplo: para imprimir las letras del alfabeto

```c
char car = 'a';
do
{
  printf("%d ",car);
  car++;
} while (car <= 'z');
```

Ejemplo: Problema Gauss

```c
int sum = 0;
int num = 0;
do 
{
	sum += (num+1);      // Off-by-one: shift 0..99 to 1..100.
	num++;
} while ( num < N );   // num: 0..99 (100 is not less than 100).
```

Nótese que, porque el `estatement_body` consiste en más de una declaración, un el bloque de declaración es requerido, de otro modo, la compilación resultaría en un error.

Otra forma de representar el problema Gauss es mediante un contador en decremento.

```c
int sum = 0;
do {
	sum += N;
	N--;
} while ( N );    // range: N down to 1 (stops at 0).
```

## For

El bucle for de C es más potente que los ciclos for de otros lenguajes de programación como Pascal o FORTRAN ya que ofrece más control sobre la inicialización y el incrementeo de las variables de control del bucle.

Sintaxis de la sentencia `for()…`:

```c
for(counter_initialization; continuation_expression; counter_increment)
	statement_body
```

La estructura de control `for()...` consiste en tres partes de expresión de control y un cuerpo de declaración. La expresión de control esta compuesta de una expresión `counter_inicialization`, `continuation_expression` y `counter_increment`, donde un punto y coma separa cada una de las partes de la expresión. Cada una de ellas tiene un propósito específico y su posición no puede ser intercambiada.

Antes de la ejecución del `for()...` la expresión `counter_inicialization` es evaluada. Esto se realiza solo una vez, después `continuation_expression` es evaluada. Si el resultado es `true`, el `statement_body` es ejecutado. Al finalizar el `statement_body`, la expresión `counter_increment` es evaluada. Después, el proceso se repite con la evaluación de `continuation_expression`.

El `statement_body` puede ser una sola declaración o incluso un declaración nula (un solo ; sin ninguna expresión), pero, frecuentemente, es una declaración compuesta. Nótese que no aparece un punto y coma  como parte de la declaración del `for()...`.Un punto y coma puede aparecer como parte de una declaración en el `statement_body` o esta ausente en el caso que `statement_body` consista de un declaración compuesta `{…}`.

Ejemplo. Problema de Gauss.

```c
int sum = 0;
	for( int num = 0 ; num < N ; num++ )  
	{
		sum += (num+1); // Off-by-one: shift 0..99 to 1..100.
	}
```

Ejemplo, programa que imprime 15 valores de la función $f(x)=e^{2x}-x$

```c
#include <math.h>
#include <stdio.h>
#define M 15
#define f(x) exp(2*x) − x
  
int main()
{
	int i;
  double x;
  for (i = 1; i <= M; i++)
  {
	  printf("Valor de x: ");
    scanf("%lf",&x);
    printf("f(%.1lf) = %.4g\n",x,f(x));
	}
	return 0; 
}
```

En el ejemplo anterior, se define una constante simbólica M y una función en línea (también llamada macro con argumentos.

El diagrama de la sintaxis de la sentencia for es:

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/f833f2f6-e842-43bf-ba01-eb7e5015077e/Untitled.png)

Existen dos formas de implementar la sentencia `for()…` que se utilizan en ciclos de conteo: **formato ascendente**, en el que la variable de control se incrementa y **formato descendente**, en el que la variable de control se decrementa.

Sintaxis

```c
// Formato ascendente
for(var_control = initial_value; var_control <= limit_value; exp_increment)
	statement;

// Formato descendente
for(var_control = initial_value; var_control >= limit_value; exp_decrement)
	statement;
```

Ejemplo:

Otra forma de resolver el problema Gauss

```c
int sum = 0;
	for( int i = N; 
			 i > 0; 
			 i--)
	{
		sum += i;       // No off-by-one.
  }
```

Se puede notar que cada parte de la expresión de control puede ser formateada para ocupar una línea, lo que da la posibilidad de crear expresiones más complejas y comentada cada una de estas.

Por ejemplo, asumir que se desea simultáneamente llevar un contador en incremento y otro en decremento. Se pueden inicializar más de un contador en la sección de la expresión del `counter_initialization` utilizando el operador de secuencia coma (`,`). Incluso se puede incrementar más de un contador en la sección de la expresión del counter_increment, nuevamente utilizando el operador `,`. La expresión luciría del siguiente modo.

```c
for( int i = 0 , int j = maxLen ;
     (i < maxLen ) && (j > 0 ) ;
     i++ , j-- )  
{
  ...
}
```

Sin embargo, la identación debe ser utilizada para mantener la expresión de control claramente identificable del cuerpo del ciclo. En este ejemplo sencillo, tal formato de código es innecesario y solamente debe ser utilizado cuando la expresión de control se vuelve más compleja.

Otra característica que puede ayudar a optimizar el uso de for es el uso de **intervalos de incremento y decremento**. 

```c
/* ejemplo 1 */
for (c = 'A'; c <= 'Z'; c++)
	printf("%c ",c);

/* ejemplo 2 */
for (i = 9; i >= 0; i -= 3)
	printf("%d ",( i * i));
  
/* ejemplo 3 */
for (i = 1; i < 100; i *= 2)
	printf("%d ",i);
  
/* ejemplo 4 */  
#define MAX 25
int i, j;
for (i = 0, j = MAX; i < j; i++, j−−)
	printf("%d ",(i + 2 * j));
```

Ejemplo: Suma de los primero 10 números pares:

```c
#include <stdio.h>

int main()
{      

	int n, suma = 0;
      
	for (n = 1; n <= 10; n++)        
		suma += 2*n;

	printf("La suma de los 10 primeros números pares: %d",suma);
	return 0;
}
```

### Usos de un ciclo `for()…`

- El valor de la variable de control se puede modificar en valores diferentes de 1
- Se puede utilizar más de una variable de control
- Las variables de control se pueden incrementar o decrementar en valores de tipo `int`, pero también es posible en valores de tipo `float` o `double` y en consecuencia incremeentaría o decrementaría en una cantidad decimal.

```c
int n;
for (n = 1; n <= 10; n = n + 2)      
	printf("n es ahora igual a %d ",n);
   
int n,v = 9;   
for (n = v; n >= 100; n = n - 5)      
	printf("n es ahora igual a %d ",n);
   
double p;   
for (p = 0.75; p <= 5; p += 0.25)      
	printf("Perímetro es ahora igual a %.2lf ",p);
```

### Precauciones del uso de for

- El `for()…` se debe construir para que en algún momento la condición se convierta en `false`.
- Considerar que si en el cuerpo del `for()…` se modifica el valor de cualquier variable de condición se pueden producir resultados imprevistos. Por ejemplo:

```c
int i,limite = 11;
for (i = 0; i <= limite; i++)   
{      
	printf("%d\n",i);
	limite++; 
}
```

- Otro ejemplo de un ciclo mal programado:

```c
int i,limite = 1;
for (i = 0; i <= limite; i++)
{
	printf("%d\n", i);
	i−−; 
}
```

Otro ejemplo donde la esta mal programado, porque la condición depende de la entrada.

```c
#define LIM 50

int iter,tope;
for (iter = 0; tope <= LIM; iter++)   
{      
	printf("%d\n", iter);      
	scanf("%d",&tope);   
}
```

### Ciclos `for()…` infinitos

Aquellos bucles que no tienen fin, y donde una sentencia se ejecuta indefinidamente a menos que se utilice una sentencia `return` o `break`.

```c
for (;;)
      printf("Forever...\n");
```

Para evitar esta situación se diseña el bucle de la siguiente manera

```c
for (;;)                      /* bucle */
{
	statements1
	if (expression) break; 
	statements2
} /* fin del bucle */ statements puede ser vacía, simple o compuesta.
```

Ejemplo de bucle infinito que termina al teclear una clave

```c
#define CLAVE -999
for (;;)
{		
	printf("Introduzca un número, (%d) para terminar",CLAVE);      
	scanf("%d ",&num);
      
	if (num == CLAVE) break;
      
	...
}
```

### Los bucles `for()…` vacíos

Cuidado de no utilizar un punto y coma después del paréntesis del ciclo `for()…`.

```c
for (i = 1; i <= 10; i++);
	puts("hello world");
```

## Equivalencia entre ciclos

```c
cuenta = valor_inicial;

while (cuenta < valor_parada)   
{
	...      
	cuenta++;   
} /* fin de while */
```

```c
for (cuenta = valor_inicial; cuenta < valor_parada; cuenta++)
{      
	...   
} /* fin de for */
```

```c
cuenta = valor_inicial;   

if (valor_inicial < valor_parada)
   do
   {
			...
      cuenta++;
   } while (cuenta < valor_parada);
```

## Bucles anidados

Es posible anidas bucles. Los bucles anidados constan de un bucle externo y uno o más bucles internos. Cada que se repite una vez el bucle externo, los bucles internos se repiten todas las iteraciones requeridas.

Ejemplo que visualiza las tablas de multiplicación

```c

```

Ejercicio 6.2 Escribir un programa que visualice un triángulo isóceles

```c
include <stdio.h>

/* constantes globales */
const int num_lineas = 5;
const char blanco = '';
const char asterisco = '*';
void main()
{
  int fila, blancos, cuenta_as;
	puts(" "); /* Deja una línea de separación */
                               
	/* bucle externo: dibuja cada línea */
	for (fila = 1; fila <= num_lineas; fila++)
	{
	  putchar('\t');     /*primer bucle interno: escribe espacios */
	  for (blancos = num_lineas–fila; blancos > 0; blancos−−)  
			putchar(blanco); 
		for (cuenta_as = 1; cuenta_as < 2 * fila; cuenta_as++)
			putchar(asterisco);
		puts(" ");
		/* terminar línea */
	} /* fin del bucle externo */
}
```

## Ejercicios

5.1. Escriba un programa que calcule y visualice $1! + 2! + 3! + ...+(n-1)! + n!$ donde $n$ es un valor de un dato.

5.2. Escribir un while que visualice todas las potencias de un número entero `n`, menores que un valor especificado `max_limite`. 

5.3.  Escribir un programa que visualice el siguiente dibujo

```bash
    *
   *** 
  ***** 
 *******
*********
 ******* 
  ***** 
   ***
    *
```

## Problemas

5.1. En una empresa de computadoras, los salarios de los empleados se van a aumentar según su contrato actual:

| Contrato | Aumento % |
| --- | --- |
| $0 a $9,000  | 20 |
| $9,001 a $15,000  | 10 |
| $15,001 a $20,000 | 5 |
| más de $20,000 | 0 |

Escribir un programa que solicite el salario actual del empleado y después calcule y visualice el nuevo salario.

5.2. La constante `pi` (3.141592…) es muy utilizada en matemáticas. Un método sencillo de calcular su valor es:

$pi = 4 * \big( \frac{2}{3} \big)  * \big( \frac{4}{5} \big) * \big( \frac{6}{5} \big) * \big( \frac{6}{7} \big) \ldots$ 

Escribir un programa que efectúe este cálculo con un número de términos especificados por el usuario.

5.3. Escribir un programa que calcule y visualice el más grande, el más pequeño y la media de N números. El valor de N se solicitará al principio del programa y los números serán introducidos por el usuario.

5.4. Escribir un programa que determine las descomposición factorial de los números enteros comprendidos entre 1900 y 2000.

5.5. Escribir un programa que determine todos los años que son bisiestos en el siglo XXII. Un año es bisiesto si es múltiplo de 4 (1988), excepto los múltiplos de 100 que son bisiestos salvo que a su vez también sean múltiplos de 400 (1800 no es bisiesto, pero 2000 sí).

5.6. Escribir un programa que visualice un cuadrado mágico de orden impar *n*, comprendido entre 3 y 11; el usuario elige el valor de *n*. Un cuadrado mágico se compone de números enteros comprendidos entre 1 y *n*2. La suma de los números que figuran en cada línea, cada
columna y cada diagonal son iguales. Un ejemplo es:

```bash
8 1 6 
3 5 7 
4 9 2
```

Un método de construcción del cuadrado consiste en situar el número 1 en el centro de la primera línea, el número siguiente en la casilla situada encima y a la derecha, y así sucesivamente. Es preciso considerar que el cuadrado se cierra sobre sí mismo: la línea encima de la primera es de hecho la última y la columna a la derecha de la última es la primera. Sin embargo, cuando la posición del número caiga en una casilla ocupada, se elige la casilla situada debajo del número que acaba de ser situado.

5.7. Escribir un programa que encuentre los tres primero números perfectos pares y los tres primeros números perfectos impares.

Un *número perfecto* es un entero positivo, que es igual a la suma de todos los enteros positivos (excluido el mismo) que son divisores del número. El primer número perfecto es 6, ya que los divisores de 6 son 1, 2, 3 y 1 + 2 + 3 = 6.

5.8. El valor de $e^x$ puede ser aproximado por la suma:

$1 + x + \frac{x^2}{2!} + \frac{x^3}{3!} + \ldots + \frac{x^n}{n!}$

Escribir un programa que tome un valor de *`x`* como entrada y visualice la suma para cada uno de los valores de 1 a 100.

5.9. El matemático italiano Leonardo Fibonacci propuso el siguiente problema. Suponga que un par de conejos tiene un par de crías cada mes y cada nueva pareja se hace fértil a la edad de un mes. Si se dispone de una pareja fértil y ninguno de los conejos muertos, ¿cuántas parejas habrá después de un año? Mejorar el problema calculando el número de meses necesarios para producir un número dado de parejas de conejos.

5.10. Para encontrar el máximo común divisor (*mcd*) de dos números se emplea el algoritmo de Euclides, que se puede describir así: dados los enteros *a* y *b* (*a* > *b*), se divide *a* entre *b*, obteniendo el cociente *q*1 y el resto *r*1.

Si *r*1 < > 0, se divide *r*1 entre *b*1, obteniendo el cociente *q*2 y el resto *r*2. Si *r*2 <> 0, se divide *r*1 entre *r*2 , para obtener *q*3 y *r*3, y así sucesivamente. Se continúa el proceso hasta que se obtiene un resto 0. El resto anterior es entonces el *mcd* de los números *a* y *b*. Escribir un programa que calcule el *mcd* de dos números.

5.11. Escribir un programa que encuentre el primer número primo introducido por teclado.

5.12. Visualizar en pantalla una figura similar a la siguiente:

```bash
*
**
***
****
*****
```

el número de líneas que se pueden introducir es variable.

5.13. Escribir un programa que visualice la siguiente salida.

```bash
1
1 2 
1 2 3 
1 2 3 4 
1 2 3 
1 2
1
```