# Día 4

## Operadores II. Comparación y lógicos

Las primeras versiones de C no tienen un tipo de dato explícito booleano (`true` y `false`). Para manejar valores booleanos, C utiliza el tipo int para este propósito, implícitamente convierte cualquier valor cero en el booleano falso y cualquier valor diferente de cero en verdadero. 

Cuando se utiliza `#include <stdbool.h>`  los tipos true y false estan disponibles en el código fuente. 

### Operadores relacionales o de comparación

Los operadores relacionales comparan el resultado de una expresión con el resultado de una segunda expresión. Tienen la misma forma que los operadores lógicos  binarios revisados previamente. 

Los operadores relaciones se usan en sentencias de selección (`if`) o de iteración (`while`, `for`) que sirven para comparar una condición. Mediante los operadores relacionales se realizan operaciones de igualdad, desigualdad y diferencias relativas.

La siguiente tabla muestra los operadores relacionales que pueden aplicar a operandos de tipo estándar: `char`, `int`, `float`, `double`, etc.

| Operador | Significado | Ejemplo |
| --- | --- | --- |
| == | Igual a | a == b |
| != | No igual a  | a != b |
| > | Mayor que | a > b |
| < | Menor que | a < b |
| >= | Mayor o igual que | a >= b |
| <= | Menor o igual que | b <= b |

Cuando se utilizan los operadores en una expresión, el operador relacional produce un 0, o un 1, dependiendo del resultado de la condición. 0 se devuelve para un condición falsa, y 1 se devuelve para una condición verdadera. Por ejemplo:

```c
c = 3 < 7;
```

La variable `c` toma el valor de `1`, dado que `3` es menor que `7`, entonces la operación `<` devuelve un valor de `1`, que es asignado a `c`.

Ejemplos

📌 Si `x`, `a`, `b`, y `c` son del tipo `double`, `number` es `int` y `first` es `char`, las siguientes expresiones booleanas son válidas:


```c
x < 5.75
b * b >= 5.0 * a * c
number == 100
first != '5'
```

En datos numéricos, los operadores relacionales se utilizan normalmente para comparar

```c
x = 3.1
x < 7.5 // retorna un 1 (true)

number = 27
number == 100 // retorna un 0 (false)
```

Los caracteres se comparan utilizando su código numérico (ASCII).

```c
'A' < 'C' // es 1 (true) ya que el código de A es 65 y el de c 67
'a' < 'c' // es 1 (true) ya que el código de a es 97 y el de c 99
'b' < 'B' // es 0 (false) ya que el código de b es 98 y el de B 66
```

### Operadores lógicos

Existen tres operadores lógicos o booleanos, se utilizan con expresiones para devolver un valor verdadero o un valor falso.

Los operadores lógicos son:

| Operación lógica | Operador | Ejemplo |
| --- | --- | --- |
| ! | NOT | !(x >= y) |
| && | AND | m < n && i > j |
| \|\| | OR | m = 5 || n != 10 |

Estos operadores lógicos los cuales el resultado siempre será `true` (no cero) o `false` (exactamente cero). Para saber el resultado de estas operaciones es necesario utilizar las tablas de la verdad.

Ejemplos:

```c
!(x + 7 == 5)
(num > 5) && (answer == 'S')
(num > 3) || (answer == 'N')
```

Los operadores lógicos son utilizados en expresiones condicionales y mediante sentencias `if`, `while`, o `for`. 

### Operador condicional

También conocido como operador ternario. Este operador tiene tres expresiones `testExpression`, `ifTrueExpression` y `ifFalseExpression`.

Sintaxis

```c
tesExpression ? ifTreuExpression : ifFalseExpression
```

La expresión `testExpression` es  evaluada. Si la expresión `testExpression` es  verdad o no cero, entonces la expresión  `ifTrueExpression` es evaluada y su resultado se convierte en el resltado de la expresión. Si la expresión `testExpression` es  falsa o cero, entonces la expresión  `ifFalseExpression` es evaluada y su resultado se convierte en el resultado de la expresión. 

Esta operación es util para lugares simples, como por ejemplo configuraciones de swtiches, valores para construir cadenas o para imprimir varios mensajes. 

Ejemplo:

```c
printf( "Length = %d meter%c\n" , len, len == 1 ? '' : 's' );
```

o se pueden imprimir palabras completas

```c
printf( "Length = %d %s\n" , len, len == 1 ? "foot" : "feet" );
```

El siguiente programa utiliza estas declaraciones:

```c
#include <stdio.h>

void printLength( double meters );

int main( void ) {
 printLength( 0.0 );
 printLength( 1.0 );
 printLength( 12.0 / 39.67 ); // very nearly 1 foot
 printLength( 2.5 );
}

void printLength( double meters ) {
 double feet = meters * 39.67 / 12.0;
 printf( "Length = %f meter%c\n" , 
         meters, 
         meters == 1.0 ? ' ' : 's' );
 printf( "Length = %f %s\n" , 
         feet, 
         0.99995 < feet && feet < 1.00005 ? "foot" : "feet" );
}
```

### Precedencia de operadores

| Operador | Operación | Nivel de procedencia |
| --- | --- | --- |
| () | (5 + 4) * 3 | 1 |
| !,+, -, (type) | +25, -6.745 | 2 |
| *, /, % | 5*5, 25/5 | 3 |
| +, - | 2+3 | 4 |
| >, <, >=, <= | b * b >= 5.0 * a * c | 5 |
| ==, != | a == b | 6 |
| & |  | 7 |
| ^ |  | 8 |
| | |  | 9 |
| && |  | 10 |
| \|\| |  | 11 |
| ?: | (num < 3)? 1 : 0 | 12 |
| = | a = 7; | 13 |

## Estructuras selectivas

Existen problemas que requieren aplicar una solución con dos o más opciones a elegir en función del valor de una condición o expresión.

La sentencia `if` permite ejecutar o saltar alguna sentencia compleja de C. El flujo de ejecución estará determinado por la evaluación de una expresión condicional. Las expresiones condicionales pueden ser simples o complejas. Las sentencias condicionales complejas deben ser claras y no permitir ambigüedad.

Las expresiones condicionales aparecen encerradas entre paréntesis en una sentencia compleja. El resultado siempre será falso o verdadero, independientemente de la complejidad que tenga la expresión.

Algunos ejemplos de expresiones condicionales son:

```c
( b_result == true )
( b_result )                        /* A compact alternative. */

( status != 0 )
( status )                         /* A compact alternative where status is     */
                                   /* only ever false when it is 0 */
( count < 3 )
( count > 0 && count <= max_count ) /* Both must be true for overall expression  */
                                   /* to be true.                               */
```

## La sentencia `if`

La forma sintáctica de de las sentencias `if` simple es la siguiente:

```c
if (expression)
	statement1;

statement3; /* próxima sentencia a ser ejecutada*/

```

Al ser evaluada la expresión, si el resultado es `true`, la sentencia `statment1` es ejecutada. Para después ser ejecutada la sentencia `statement3` independientemente del resultado obtenido en la expresión.

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/e220fcd5-df64-4e67-bdd1-cd9510e83e94/Untitled.png)

<aside>
📌 Ejemplo 2.1. Prueba de divisibilidad.
Este programa lee dos números enteros y prueba cuál es el valor del resto de la división `numerator` entre `divider` (`numerator % divider`). Si el resto es cero, `numerator` es divisible entre `divider`. En un ejemplo, 36 es divisible entre 4, ya que $36 / 4 = 9$ y el resto es 0.

</aside>

```c
#include <stdio.h>

int main()
{
  int numerator, divider;
  
	printf("Introduzca dos enteros:");
  scanf("%d %d",&numerator,&divider);
  
	if (numerador % divider == 0) 
		printf(" %d es divisible entre %d\n",numerator, divider);
  
	return 0;
}
```

<aside>
📌 Ejemplo 2.2. Representar la superación de un examen cuando la nota es mayor o igual a 6, imprimir el mensaje: “Aprobado”.

</aside>

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/31da6449-5711-4907-a727-8b2d8ffe4d18/Untitled.png)

```c
#include <stdio.h>

void main()
{
	float note;
  printf("Introduzca la nota obtenida (0-10): ");
  scanf("%f", &note);
    /* compara Nota con 5 */
  if (note >= 6)
    puts("Aprobado");
}
```

Resultado de la ejecución del programa:

Otra ejecución del programa:

<aside>
📌 Ejemplo 2.3. Comparar números introducidos por el usuario para determinar si es un número positivo, negativo o cero.

</aside>

```c
#include <stdio.h>

void main() {
  
	float numero;
  printf("Introduzca un número positivo o negativo: ");
  scanf("%f",&numero);
  /* comparar número */
  if (numero > 0)
    printf("%f es mayor que cero\n",numero);
  if (numero < 0)
    printf("%f es menor que cero\n",numero);
  if (numero == 0)
    printf("%f es igual a cero\n",numero);
}
```

Resultado de la ejecución:

<aside>
🏋️‍♂️ Ejercicio 2.1. Visualizar la tarifa de la luz de acuerdo con el gasto de corriente eléctrica. Para un gasto menor de 1 000 kwh la tarifa es de 1.2, entre 1 000 es 1.0 y mayor de 1850 kwh de 0.9.

</aside>

```c
#include <stdio.h>
#define TARIFA1 1.2
#define TARIFA2 1.0
#define TARIFA3 0.9

int main() 
{
	float gasto, tasa;
  printf("\n Gasto de corriente: ");
  scanf("%f",&gasto);
  
	if (gasto < 1000.0)
	  tasa = TARIFA1;
  if (gasto >= 1000.0 && gasto <= 1850.0)
	  tasa = TARIFA2;
  if (gasto > 1850.0)
		tasa = TARIFA3;
  
	printf("\nTasa que le corresponde a %.1f kwxh es de %f\n", gasto,tasa);
	return 0; 
}
```

## La sentencia `if-else`

```c
if (expression)
	statement1
else
	statement2

statement3 /* próxima sentencia a ser ejecutada*/

```

Al ser evaluada la expresión, si el resultado es `true`, la sentencia `statment1` es ejecutada. en el caso contrario (que sea `false`) entonces la sentencia `statement2` es ejecutada.  Independientemente del resultado obtenido en la expresión,  la sentencia `statement3` Pes ejecutada.

Nótese que las sentencias no son indicadas con ; esto es porque `statement1` o `statement2` pueden ser sentencias simples (terminan en `;`) o sentencias compuestas (terminan en `{}`). En los dos casos las sentencias simples terminan en `;` pero no los bloques `{}`.

Ejemplo:

```c
is_even = false;

if( (num % 2) == 0 )
    is_even = true;
```

En el ejemplo anterior, con la ayuda de la inicialización de la variable `is_even` se asume que que el valor no es par, y con la prueba la sentencia del `if` simple se puede redefinir el valor a `true`, para indicar que si es par. La sentencia de la ramificación del `if` solo se ejecuta cuando `num % 2` es igual a 0.

Ejemplo, calcular si un año es bisiesto o no. En la civilización occidental de determino el uso de años bisiestos desde 1752. En aquel entonces se asumía que el año tenía 365.25 días o 265 + 1/4, por lo tanto se utiliza el modulo 4 para determinar si un año es bisiesto.

```c
bool isLeapYear( int year )  {
     // Leap years not part of Gregorian calendar until after 1752.
     // Is year before 1751? 
     // Yes: return false.
     // No: "fall through" to next condition.
     //
 if( year < 1751 ) return false;

    // Is year an multiple of 4? (remainder will be 0)
    // Yes: return true.
    // No: "fall through" and return false.
    //
  if( (year % 4) == 0 ) return true;
	return false;
}
```

¿Pero esto es correcto? No, esto es por los siglos bisiestos. El año 2000 es bisiesto, pero ell año 1900 no lo es. El año solar es ligeramente menor que 365.25 días; es aproximadamente de 365.2425 días o 365 + 1/4 + 1/100 + 1/400. Nótese que se deberá contar para 1/100 cada cien años y 1/400 para cada cuatrocientos años.  La solución se volverá un poco más complicada

La sentencia `if-else` tiene la siguiente sintaxis:

```c
if (expression)
	statement1
else
	statement2

statement3
	
```

En este formato una sentencia que termina en `;` o un bloque de sentencias encerrado entre llaves. Cuando se ejecuta la sentencia `if-else` se evaluar la expresión `expression`. si `expression` es `true` se ejecuta `statement1` y en caso contrario se ejecuta `statement2`.

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/1f7b70a9-dab1-4f89-bd0c-036dcf8d9ebe/Untitled.png)

```c
if (salary > 100000)
	final_salary = salary - taxes;
else
	final_salary = salary
```

Si (`if`) el salario es mayor que $10,000 se calcula el salario neto restándole los impuestos; en caso contrario (`else`) el salario neto es igual a salario bruto.

```c
if (note >= 6)
	puts("Aprobado");
else
	puts("Repprobado");
```

Si la nota es mayor que 6 se escribe “Aprobado”; en caso contrario, la nota que sea menor que 6, se escribe “Reprobado”.

<aside>
📌 Ejemplo 2.2.4. Prueba de divisibilidad

</aside>

```c
#include <stdio.h>

int main()
{
	int numerator, divider;

	printf( "Introduzca dos enteros: "); 
	scanf("%d %d",&numerator,&divider);
	
	if (numerator % divider == 0)
      printf("%d es divisible entre %d\n", numerator, divider);
	else
      printf("%d no es divisible entre %d\n", numerator, divider);
  
	return 0;
}
```

Ejecución

```c
Introduzca dos enteros: 36 5 
36 no es divisible entre 5
```

El número 36 no es divisible entre 5 ya que al realizar la división el residuo es 1, por lo tanto la expresión de relación `numerator % divider == 0` es falsa, y se ejecuta la cláusula `else`.

<aside>
📌 Ejercicio 2.2.5. Calcular el número mayor entre dos valores enteros leídos del teclado y visualizarlo en pantalla.

</aside>

```c
#include <stdio.h>

int main()
{
	int number_1, number_2;
  printf("Introduzca dos enteros: ");
  scanf("%d %d", &number_1, &number_2);
    
	if (number_1 > number_2)
	  printf("%6d\n", number_1);
	else
    printf("%6d\n", number_2);
  
	return 0;
}
```

Ejecución

```c
Introduzca dos enteros: 17   54
54
```

La condición es `(number_1 > number_2)`. Si el número uno es mayor que el número dos, la condición es verdadera (`true`) y se evalúa a 1; en caso contrario la condición es falsa (`false`) y se evalúa a 0. De este modo se imprime `number_1` (en un campo de ancho 6, `%6d`) cuando es mayor que `number_2`, en caso contrario se imprime `number_2`.

<aside>
📌 Ejercicio 2.2.6. Dada la función $f(x)$, calcular la función para un valor dado de $x$ y visualizar el resultado en pantalla. 
$f(x) = x^2 - x, si x \le 0.0 \, -x^2 + 3x para x>0$

</aside>

```c
#include <stdio.h>
#include <math.h>

int main()
{
    float f,x;
    
		printf("\n Elige un valor de x: ");
    scanf("%f",&x);
    
		/* selección del rango en que se encuentra x */
    if (x <= 0.0)
      f = pow(x,2) − x;
    else
      f = −pow(x,2) + 3*x;
    
		printf("f(%.1f) = %.3f",x,f);
	  
		return 0;
}
```

Ejecución

```c
Elige un valor de x: –1.5 
f (−1.5) = 3.750
```

Una vez introducido $x$, se evalúa la condición `x ≤ 0.0`, si es cierta se asigna a la variable `f`, $x^2-x$; en caso contrario se asigna a `f` el resultado de $-x^3+3x$.

## Sentencias `if-else` anidadas

La implementación de la sentencia `if` revisada hasta ahora solo permite resolver decisiones que implican una o dos opciones. Sin embargo, es posible realizar una implementación que permita considerar diferentes opciones.

La sentencia if es anidada cuando la sentencia de la rama verdadera o la rama falsa es a su ves un a sentencia if. Una sentencia if anidada se puede implementar para decisiones con varias alternativas o múltiples alternativas.

```c
if (expression)
	statement1
else 
	if (expression)
		statement2
		.
		.
		.
	else
		if (expression)
			statementn
		else
			statementn+1
```

<aside>
📌 2.2.7. Incrementar contadores de números positivos, números  negativos o cero

</aside>

```c
if (x > 0)
	num_pos = num_pos + 1;
else
	if (x < 0)
		num_neg = num_neg + 1;
	else
		num_zeros = num_zeros + 1;
```

La sentencia `if` anidada del ejemplo anterior tiene tres alternativas. Se incrementar una de las tres variables (`num_pos`, `num_neg` y `num_zeros`) en 1, dependiendo de que: `x` sea mayor que cero, menor que cero o igual a cero, respectivamente.

La ejecución de sentencia `if` anidada se realiza como sigue: se comprueba la primera condición `(x > 0)`; si es verdadera, `num_pos` se incrementa en 1 y salta el resto de la sentencia `if`. Si la primera condición es falsa, se comprueba la segunda condición `(x < 0)`; si es verdadera `num_neg` se incrementa en uno; en caso contrario se incrementa `num_ceros` en uno. Es importante considerar que la segunda condición se comprueba solo si la primera condición es falsa.

**Sangría en las sentencias `if` anidadas**

Formato 1:

```c
if (expression)
	statement1
else 
	if (expression)
		statement2
else
	if (expression)
		statement3
else
	if (expression)
		statement4
	else
		statement5
```

Formato 2:

```c
if (expression)
	statement1
else if (expression)
	statement2
else if (expression)
	statement3
else if (expression)
	statement4
else
	statement5

```

Ejemplos:

```c
if (x > 0)
	z = 2*log(x);
else
	if (y > 0)
     z = sqrt(x) + sqrt(y);

```

```c
if (x > 0)
	z = 2*log(x);
else if (y > 0)
  z = sqrt(x) + sqrt(y);
else
	puts( "\n *** Imposible calcular z");
```

Ejemplo:

```c
#include <stdio.h>

void main()
{
	float number;

	printf( " Introduzca un número positivo o negativo: ");
  scanf("%f",&number);
  
	/* comparar número con cero */
  if (number > 0)
  {
	  printf("%.2f %s", number, "es mayor que cero\n");
    puts( "Pruebe de nuevo introduciendo un número negativo");
   }
	 else if (number < 0)
   {
	   printf("%.2f %s", number, "es menor que cero\n");
     puts( "pruebe de nuevo introduciendo un número positivo");
   }
	 else {
	   printf("%.2f %s", number, "es igual a cero\n");
     puts( " ¿por qué no introduce otro número? ");
   }
}
```

Comparación de sentencias `if` anidadas y secuencia de sentencias `if` a

Al programar se puede optar por implementar soluciones con una secuencia de sentencias de `if`  o una única sentencia de `if` anidada. Por ejemplo , la sentencia `if` del ejemplo 2.2.7 se puede reescribir con una secuencias de sentencias de `if`, de la siguiente forma:

```c
if (x > 0)
	num_pos = num_pos + 1;
if (x < 0)
	num_neg = num_neg + 1;
if (x == 0)
	num_zeros = num_zeros + 1;
```

En el ejemplo anterior la secuencia es lógicamente equivalente a la original, sin embargo, en muchas ocaciones no es legible  ni eficiente. La contrario de la sentencia `if` anidada, la secuencia no muestra claramente cuál es la secuencia a ejecutar para un valor determinado de `x`. Con respecto a la eficiencia, la sentencia `if` anidad es ejecutada más rápido cuando `x` es positivo a que la primera condición `(x > 0)` es verdadera, lo que significa que la siguiente parte es omitida. En contraste, se comprueban siempre las tres condiciones de las sentencias `if`. Si `x` es negativa, se comprueban dos condiciones de sentencias `if` anidadas frente a las tres condiciones de las secuencias de sentencias `if`. Una estructura típica `if-else` anidada permitida es:

```c
if (numero > 0) {
	...
}
else
{
	if ( ...) 
	{
		... 
	}
	else 
	{
	  if ( ...)
    {
			...
		}
	}
		...
}
```

<aside>
📌 Ejemplo 2.2.9. Calcular el mayor de tres números enteros

</aside>

```c
#include <stdio.h>
   
int main()   
{      
	int a, b, c, mayor;
  
	printf("\n Introduzca tres enteros:");
  scanf("%d %d %d",&a,&b,&c);
      
	if (a > b)
	  if (a > c) mayor = a;
    else mayor = c;
	else
    if (b > c) mayor = b;
    else mayor = c;
  printf("El mayor es %d \n",mayor);
      
	return 0;
}
```

Ejecución

```c
Introduzca tres enteros: 77 54 85 
El mayor es 85
```

Análisis

Al ejecutar el primer `if`, la condición `(a > b)` es verdadera, entonces se ejecuta el segundo `if`. En el segundo `if` la condición `(a > c)` es falsa, en consecuencia se ejecuta `else` mayor = 85 y se termina la sentencia `if`; a continuación se ejecuta la última línea y se visualiza *El mayor es 85.*

## Sentencia `switch`

La sentencia `switch` es una sentencia C que se utiliza para seleccionar una de entre múltiples alternativas. La sentencia `switch` es especialmente útil cuando la selección se basa en el valor de una variable simple o de una expresión simple denominada ***expresión de control*** o ***selector***. El valor de la expresión puede ser de tipo `int` o `char`, pero no puede ser de tipo `float` o `double`.

Sintaxis.

```c
switch(selector)
{
	case tag1 : statement1;
	case tag1 : statement1;
	.
	.
	.
	case tagn : statementn;
	default: statementd; /*opcional */
}
```

La sentencia `switch` evalúa la expresión de control o selector y es comparado con cada una de las etiquetas de `case`. La expresión selector debe ser de tipo ordinal (por ejemplo, `int`, `char`, pero no `float` o `string`). Cada etiqueta es un valor único, constante y cada etiqueta debe tener un valor diferente de los otros. Si el valor de la expresión selector es igual a una de las etiquetas `case`. Por Ejemplo, `statement1` entonces la ejecución comenzará con la primera sentencia de la secuencia `statement1` y continuará hasta que se encuentre el final de la sentencia de control `switch`, o hasta encontrar la sentencia `break`. Es habitual que después de cada bloque de sentencias correspondiente a una secuencia se desee determinar la ejecución del `switch`; para ello se sitúa la sentencia `break` como última sentencia del bloque. La sentencia `break` hace que no siga la ejecución en de las siguientes sentencias del `switch`.

Sintaxis con break

```c
switch (selector)
{
	case label1 : statement1;
								break;
	case label2 : statement2;
								break;
	.
	.
	.
	case labeln : statementn;
								break;
	default:      statementd; /* opcional */
}
```

El tipo de dato de cada etiqueta debe ser el mismo que la expresión **selector**. Las expresiones están permitidas como etiquetas pero solo si cada operador de la expresión es por sí mismo una constante, por ejemplo, `4 + 8` o bien `m * 15`, siempre que `m` hubiera sido definido anteriormente como constante con nombre.

Si el valor del **selector** no está listado en ninguna etiqueta `case`, no se ejecutará ninguna de las opciones a menos que se especifique una acción en forma predeterminada. La omisión de una etiqueta  default puede crear un error lógico difícil de prever. Aunque la etiqueta default es opcional, se aconseja utilizar a menos que se tenga la certeza de que todos los valores de **selector** estén incluidos en las etiquetas `case`.

Una sentencia break consta de la palabra reservada `break` seguida de `;`. Cuando la computadora ejecuta las siguientes sentencias a una etiqueta `case`, continúa hasta que se alcanza una sentencia `break`. Si la computadora encuentra una sentencia `break`, termina la sentencia `switch`. Si se omite la sentencia break, después de ejecutar el código de case se continuará la ejecución secuencial de la siguientes sentencias.

<aside>
📌 Ejemplo 2.2.10. Elección de tres opciones y un valor de forma predeterminada.

</aside>

```c
switch (opcion)
{
	case 0:
	  puts("Cero!");
	  break;
	case 1:
	  puts("Uno!");
	  break;
	case 2:
	  puts("Dos!");
	  break;
	default:
	  puts("Fuera de rango");
}
```

<aside>
📌 Ejemplo 2.2.11. Selección múltiple, tres etiquetas ejecutan la misma sentencia.

</aside>

```c
switch (opcion)
{         
	case 0:           
	case 1:         
	case 2:             
					puts("Menor de 3");
			    break;           
	case 3:
				  puts("Igual a 3");
			    break;
  default:
          puts("Mayor que 3");
}
```

<aside>
📌 Ejemplo 2.2.12. Comparación de las sentencias `if-else-if` y `switch`. Se necesita saber si un determinado carácter es una vocal.

</aside>

```c
if ((car == 'a') || (car == 'A'))
	printf( "%c es una vocal\n",car);
else if ((car == 'e') || (car == 'E'))
	printf( "%c es una vocal\n",car);
else if ((car == 'i') || (car == 'I'))
	printf( "%c es una vocal\n",car);
else if ((car == 'o') || (car == 'O'))
	printf( "%c es una vocal\n",car);
else if ((car == 'u') || (car == 'U'))
	printf( "%c es una vocal\n",car);
else
	printf( "%c no es una vocal\n",car);
```

```c
switch (car)
{
	case 'a': case 'A':
	case 'e': case 'E':
  case 'i': case 'I':
  case 'o': case 'O':
  case 'u': case 'U':
								      printf( "%c es una vocal\n",car);
								      break;
  default:
								      printf( "%c no es una vocal\n",car);
 }
```

<aside>
📌 Ejemplo 2.2.13. Dada una nota de un examen mediante un código escribir el literal que le corresponde a cada nota.

</aside>

```c
/* Programa resuelto con la sentencia switch */

#include <stdio.h>

int main() {  
	char nota;
  printf("Introduzca calificación (A-F) y pulse Intro:");
  scanf("%c",&nota);
    
	switch (nota)
  {
	  case 'A': puts("Excelente. Examen superado");
              break;
    case 'B': puts("Notable. Suficiencia");
              break;
    case 'C': puts("Aprobado");
              break;
    case 'D':
    case 'F': puts("Reprobado");
              break;
		default:
              puts("No es posible esta nota");
	}
    puts("Final de programa");
    return 0;
}
```

Cuando se ejecuta la sentencia switch en el ejemplo 2.2.13 se evalúa `nota`; si el valor de la expresión es igual al valor de una etiqueta, entonces se transfiere el flujo de control a las sentencias asociadas con la etiqueta correspondiente. Si ninguna etiqueta coincide con el valor de la nota se ejecuta la sentencia `default` y las sentencias que vienen después de ella. Normalmente la última sentencia de las sentencias que vienen después de un `case`  es una sentencia `break`. Esta sentencia hace que el flujo de control del programa salta a la siguiente sentencia del `switch`. Si no existiera `break`, se ejecutarían también las sentencias restantes de la sentencia `switch`.

Ejecución 

```c
Introduzca calificación (A-F) y pulse Intro: A 
Excelente. Examen superado
Final de programa
```

Ejecución dos:

```c
Introduzca calificación (A-F) y pulse Intro: B 
Notable. Suficiencia
Final de programa
```

Ejecución tres:

```c
Introduzca calificación (A-F) y pulse Intro: E
No es posible esta nota
Final de programa
```

<aside>
📌 Ejemplo 2.2.14.  Seleccionar un tipo de vehículo según un valor numérico.

</aside>

```c
int tipo_vehiculo;

printf("Introduzca tipo de vehiculo:");
scanf("%d",&tipo_vehiculo);
switch(tipo_vehiculo)
{
		case 1:
						printf("turismo\n");
						peaje = 500;
						break; 
		case 2:
		        printf("autobus\n");
		        peaje = 3000;
		        break;
	  case 3:
		        printf("motocicleta\n");
		        peaje = 300;
		        break;
		default:
		        printf("vehículo no autorizado\n");
}
```

Caso particular de `case`:

Se puede utilizar varias expresiones case en una alternativa dada dentro de la sentencia switch. Por ejemplo, se puede escribir:

```c
switch(c) {
      case '0':case '1': case '2': case '3': case '4':
      case '5':case '6': case '7': case '8': case '9':
																											 num_digitos++; 
																											 break;
			case ' ': case '\t': case '\n':
																								       num_blancos++; 
																								       break;
      default:
																								       num_distintos++;
   }
```

**Uso de sentencias `switch` en menús**

La sentencia switch es ideal para implementar menús. Un menú de un restauran presenta una lista de alternativas para que un cliente elija entre sus diferentes opciones. Un menú en un programa de computadora hace la misma función: presentar una lista de opciones en la pantalla para que el usuario elija una de ellas. 

## Operador `? :`

El lenguaje C utiliza un tercer mecanismo de selección llamado **expresión condicional**, es una expresión que produce uno de dos valores, resultado de una expresión lógica o booleana (también llamada condición). Tiene la forma C ? A : B y es una operación ternaria (tres operandos) en el que `C`, `A` y `B` son tres operandos y `? :` es el operador. 

Sintaxis

```c
condition ? statement1 : statement2
```

`condition` es una expresión lógica, `statement1` y `statement2` son cualquier expresión.

Se evalúa la `condition`, si el valor es verdadero (distinto de cero) entonces se devuelve como resultado el valor de `statement1`, si el valor de `condition` es falso se devuelve como resultado el valor de `statement2`.

```c
a == b ? funcion1():funcion2();
```

Es equivalente a

```c
if (a == b)
      funcion1();
   else
      funcion2();
```

Otro ejemplo.

```c
int entrada1, entrada2;
         int menor;
         scanf("%d %d",&entrada1,&entrada2);
         menor = entrada1 <= entrada2  ?  entrada1 : entrada2;
```

<aside>
📌 Ejemplo 2.2.15 Seleccionar el mayor de dos números enteros con la sentencia `if-else` y con el operador `?:`.

</aside>

```c
#include <stdio.h>
void main() {
int n1, n2;
           printf("Introduzca dos números positivos o negativos:");
           scanf("%d %d",&n1,&n2);
/* selección con if-else */ if (n1 > n2)
             printf("%d > %d",n1,n2);
else
             printf("%d <= %d",n1,n2);
           /* operador condicional */
           n1 > n2 ? printf("%d > %d",n1,n2): printf("%d <= %d",n1,n2);
}
```