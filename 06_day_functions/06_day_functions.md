# Día 6

* [Funciones](#funciones)
  * [Definición de una función](#definición-de-una-función)
  * [Prototipos de una función](#prototipos-de-funciones)
*[Parámetros de la función](#parámetros-const-de-una-función)
  * [Paso de parámetros por valor](#paso-de-parámetros-por-valor)
  * [Paso de parámetros por referencia](#paso-de-parámetros-por-referencia)
* [Ejercicios](#ejercicios)
* [Problemas](#problemas)

## Funciones

El proceso de escribir un programa (o resolver un problema con un programa de computadora) la tarea principal es descomponer el problema en pequeñas tareas (en funciones) y enfocarse en resolver cada pequeña parte. Cuando se descompone un problema en pequeñas partes, podemos ver fácilmente la esencia del problema. Permite centrarse en cada uno de los aspectos de un problema mayor o en afinar los detalles del problema divido en piezas.

Si se agrupan funciones en bibliotecas otros programas pueden reutilizar las funciones, por esta razón se puede ahorrar tiempo de desarrollo. Y dado que las bibliotecas contienen rutinas presumiblemente comprobadas, se incrementa la fiabilidad del programa completo.

La mayoría de los programadores no construyen bibliotecas, sino que, simplemente las utilizan. Por ejemplo, cualquier compilador incluye más de 500 funciones de biblioteca, que esencialmente pertenecen a la biblioteca ANSI (American Standards Institute). Dado que existen tantas funciones de biblioteca, no siempre será fácil encontrar la función necesario, más por la cantidad de funciones a consultar que por su contenido en si. Por ello, es frecuente disponer del manual de biblioteca de funciones del compilador o de algún libro que lo incluya.

### Definición de una función

[Video clase - funciones](https://www.youtube.com/watch?v=cP9-B_i83JM&list=PL3_qQRFomlqLXuL2ukPe0pTNKoVt3fuMJ&index=1)

El lenguaje C es un lenguaje de programación estructurado, también llamado programación modular. Al escribir un programa este se divide en módulos, en lugar de uno solo. El programa se fracciona en módulos (o funciones) con la finalidad de aislar los problemas, escribir programas correctos más rápido y producir programas que son mucho más fáciles de mantener.

Las funciones son una parte esencial en un programa de C. Cada función que es creada debe tener las siguientes partes:

- **Identificadores de función**: Este es el nombre de la función. El nombre de la función debe ser muy específico con respecto a lo que hace.
- **Tipo de resultado de la función** o **tipo de valor retornado**: Las funciones pueden devolver un valor a quien los llama, el que llama puede ignorar ese resultado. Si un tipo de valor de retorno es especificado, la función debe devolver un valor de ese tipo al que llama.
- **Bloque de función**: Un bloque de función esta directamente asociado con el nombre de la función y una lista de parámetros, donde sentencias adicionales son agregadas para realizar el trabajo de la función.
- **Sentencia de retorno**: El mecanismo principal para retornar un valor de un tipo especificado de la función llamada a quien la llamo.
- **Lista de parámetros de la función**: Es una lista opcional de valores que son pasado a la función, loas cuales pueden ser utilizados como parte de su ejecución.

Ejemplos de funciones

La función `cuadrado()` escribe los cuadrados de números enteros sucesivos a partir de un número dado `n`, parámetro de la función, hasta obtener un cuadrado mayor de 1000. Esta función no devuelve un valor, es de tipo void, por esta razón la sentencia final es simplemente `return`.

```c
void cuadrado(int n)
{  
	int q = 0;  

	while (q <= 1000) 
	{	
		/* el cuadrado ha de ser menor de 1000 */	   
		q = n*n;        
		printf("El cuadrado de: %d es %d \n",n,q);        
		n++;
	}
	return; 
}
```

La función `suma()` calcula la suma de un número determinado (parámetro) de elementos leídos de la entrada estándar (teclado). Esta función devuelve un valor de tipo `float`, que es la suma de `num_elementos` datos de entrada. Por esta razón la sentencia final es `return total`.

```c
float suma (int num_elementos)   
{      
	int indice;      
	float total = 0.0;      
	
	printf("\n \t Introduce %d números reales\n", num_elementos);
      
	for (indice = 0; indice < num_elementos; indice++)     
	{        
		float x;        
		scanf("%f ";&x);        
		total += x;
	}      

	return total;   
}
```

### Prototipos de funciones

La declaración de una función se denomina prototipo. Los prototipos de una función contienen la cabecera de la función, con la diferencia de que los prototipos terminan en punto y coma. 

Un prototipo consta de los siguientes elementos:

- Tipo de dato retornado
- Nombre de la función
- Lista de argumentos encerrados entre paréntesis
- `;`

Ejemplo:

```c
#include <stdio.h>

float area_rectangulo(float b, float a); /* declaración */
float entrada(void);                     /* prototipo o declaración */

int main()
{
    float b, h;
    printf("\n Base del rectangulo: ");
    b = entrada();
    printf("\n Altura del rectangulo: ");
    h = entrada();
    printf("\n Area del rectangulo: %.2f", area_rectangulo(b, h));
    return 0;
} /* devuelve número positivo */

float entrada()
{
    float m;
    do
    {
        scanf("%f", &m);
    } while (m <= 0.0);
    return m;
}

/* calcula el area de un rectángulo */
float area_rectangulo(float b, float a)
{
    return (b * a);
}
```

<aside>
📌 En un prototipo de función los nombres de los parámetros pueden ser omitidos para tener claridad en el código.

</aside>

```c
char* copiar (char*, int);
char* copiar (char * buffer, int n);
```

## Parámetros de la función

C siempre utiliza el método de **parámetros por valor** para pasar variables a funciones. Con el fin de que una función devuelva n valor a través del argumentos hay que pasar la dirección de la variable, y que el argumento correspondiente de la función sea un apuntador (puntero), es la forma de conseguir en C un paso de **parámetros por referencia**.

El paso de parámetros a una función depende del tipo de datos que se utiliza. Por ejemplo, si se tienen la declaración de la función `circulo` con tres argumentos

```c
void circulo(int x, int y, int diametro);
```

Cuando se realiza la llamada a la función se deben pasar tres argumentos a `circulo`. En el punto de llamada cada parámetro puede ser una constante, una variable o una expresión, como en la llamada:

```c
circulo(25, 40, vueltas*4);
```

### Paso de parámetros por valor

El paso por valor o  (paso por copia) significa que cuando C compila la función y el código que llama a la función, este recibe una copea de los valores de los parámetros. Se se cambia el valor de un parámetro, el cambio solo afecta a la función y no tiene efecto fuera de ella.

La figura 7.3. muestra la acción de pasar un argumento por valor. La variable real `i` no se pasa, pero el valor de `i`, `6` se pasa a la función receptora.

En la técnica de paso de parámetros por valor, la modificación de la variable (parámetro pasado) en la función receptora no afecta al parámetro argumento en la función llamadora.

<aside>
📌 El método de forma predeterminada de pasar argumentos es por valor, a menos que se pasen arreglos. Los arreglos se pasan siempre por dirección o referencia al primer elemento.

</aside>

El siguiente programa muestra el mecanismo de paso de parámetros por valor 

```c
/*
      Muestra el paso de parámetros por valor.
      Se puede cambiar la variable del parámetro en la función,
      pero su modificación no puede salir al exterior.
   */
#include <stdio.h>
void DemoLocal(int valor);
void main(void)
{
    int n = 10;
    printf("Antes de llamar a DemoLocal, n = %d\n", n);
    DemoLocal(n);
    printf("Después de llamada a DemoLocal, n = %d\n", n);
}
void DemoLocal(int valor)
{
    printf("Dentro de DemoLocal, valor = %d\n", valor);
    valor = 999;
    printf("Dentro de DemoLocal, valor = %d\n", valor);
}
```

```bash
Antes de llamar a DemoLocal, n = 10
Dentro de DemoLocal, valor = 10
Dentro de DemoLocal, valor = 999
Después de llamar a DemoLocal, n = 10
```

### Paso de parámetros por referencia

Cuando una función debe modificar el valor del parámetro pasado y devolver este valor modificado a la función llamadora, se ha de utilizar el método de paso de parámetros por referencia o dirección.

En este método, el compilador pasa la dirección de memoria del valor del parámetro a la función. Cuando se modifica el valor del parámetro, este valor queda almacenado en la misma dirección de memoria, por lo que al retomar la función llamadora la dirección de memoria donde se almacenó el parámetro contendrá el valor modificado. Para pasar una variable por referencia, el símbolo & debe preceder al nombre de la variable y el parámetro variable correspondiente a la función debe declararse como apuntador (puntero).

```c
float x;
int y;
entrada(&x,&y);
.. .
void entrada(float *x, int *y)
```

C utiliza apuntadores (punteros) para implementar parámetros por referencia, ya que en forma predeterminada en C el paso de parámetros es por valor.

```c
/* método de paso por referencia, mediante puntero */
void intercambio(int *a, int *b)
{
      int aux = *a;
      *a = *b;
      *b = aux;
}
```

## Diferencias entre paso de variables por valor y por referencia

Las reglas a considerar al pasar variables por valor o por referencia son:

- Los parámetros por valor reciben copias de los valores de los argumentos que se les pasan
- La asignación a parámetros por valor de una función nunca cambian el valor del argumento original pasado a los parámetros.
- Los parámetros por el paso por referencia (declarados con `*`, punteros) reciben una dirección de los argumentos pasados, a éstos les debe de preceder el operador &, excepto en arrays (arreglos).
- En una función, las asignaciones a parámetros por referencia (apuntador) cambia los valores de los argumentos originales.

Ejemplo:

```c
#include <stdio.h>
#include <math.h>
void potrat1(double x, double y);
void potrat2(double *x, double *y);
void main()
{
    double a, b;
    a = 5.0;
    b = 1.0e2;
    potrat1(a, b);
    printf("\n a = %.1f b = %.1lf", a, b);
    potrat2(&a, &b);
    printf("\n a = %.1f b = %.1lf", a, b);
}
void potrat1(double x, double y)
{
    x = x * x;
    y = sqrt(y);
}
void potrat2(double *x, double *y)
{
    *x = (*x) * (*x);
    *y = sqrt(*y);
}
```

La ejecución del programa producirá:

```bash
a = 5.0 b = 100.0
a = 25.0 b = 10.0
```

## Parámetros `const` de una función

Con el objetivo de agregar seguridad a las funciones, se puede especificar un parámetro como constante, lo que indica al compilador que es de solo lectura al interior de la función. Si se intente escribir este parámetro se producirá un mensaje de error de compilación.

```c
void f1(const int x, const int* y);
void f2(int x, int * const y);

void f1(const int x, const int* y)
{
	x = 10; /* error por cambiar un objeto constante */
	*y = 11; /* error por cambiar un objeto constante */
	y = &x; /* correcto, sólo protege el valor contenido */

}

void f2(int x, int* const y)
{
	x = 10; /* correcto */
	*y = 11; /* correcto, ahora no se protege el contenido (*y) */
	y = &x; /* error, protege a la variable puntero */ 
}
```

## Ejercicios

6.1. Escribir una función que tenga un argumento de tipo entero y que devuelva la letra P si el número es positivo, y la letra N si es cero o negativo.

6.2. Escribir una función lógica de dos argumentos enteros, que devuelvan `true` si uno divide al otro y `false` en caso contrario.

6.3. Escribir una función que convierta una temperatura dada en grados Celsius a grados Fahrenheit. La fórmula de conversión es: $F = \frac{9}{5} C + 32$

6.4. Escribir una función lógica `digito` que determine si un carácter es uno de los dígitos del 0 al 9.

6.5. Escribir una función lógica `vocal` que determine si un carácter es una vocal.

6.6. Escribir una función `redondeo` que acepte un valor real `cantidad` y un valor entero `decimales` y devuelva el valor `cantidad` redondeado al número especificado de decimales. Por ejemplo, `(20.562, 2)` devuelve `20.56`.

6.7. Determinar y visualizar el número más grande de dos números dados mediante una función.

6.8. Escribir un programa que calcule los N primeros números naturales primos mediante una función.

## Problemas

6.1. Escribir una función que reciba una cadena de caracteres y la devuelva en forma inversa (”hola” se convierte en “aloh”).

6.2. Escribir una función que determine si una cadena de caracteres es un palíndromo (un palíndromo es un texto que se lee igual en sentido directo y en sentido inverso: radar).

6.3. Escribir un programa que mediante  una función que acepte un número de día, mes y año y lo visualice en formato dd/mm/aa

Por ejemplo los valores8, 10, 1946 se visualizaran como:

8/10/46

6.4. Escribir un programa que utilice una función para convertir coordenadas polares a rectangulares

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/6b799d7d-cfc5-4bb5-9317-da80de8f6ebe/Untitled.png)

6.5. Escribir un programa que lea un entero positivo y a continuación llame a una función que visualice sus factores primos.

6.6. Escribir un programa, mediante funciones, que visualice un calendario de la forma:

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/6a126fe2-393b-4afc-8166-ff338e835a85/Untitled.png)

El usuario indica únicamente el mes y el año.

6.7. Escribir un programa que lea los dos enteros positivos `n` y `b` que llame a una función `cambiar_base` para calcular y visualizar la representación del número `n` en la base `b`.

6.8. Escribir un programa que permita el cálculo del `mcd` (máximo común divisor) de dos números por el algoritmo de Euclides (Dividir `a` entre `b`, se obtienen el cociente `q` y el resto `r` si es cero `b` es el mcd, si no se divide `b` entre `r`, y así sucesivamente hasta encontrar un resto cero; el último divisor es el mcd). La función `mcd()` devolverá el máximo común divisor.

6.9. Escribir una función que devuelva el inverso de un número dado (1234, inverso 4321).

6.10. Calcular el coeficiente del binomio con una función factorial

$\frac{m}{n} = \frac{m!}{n!(m-n)!}$ donde $n, k \in \N$  y $k \leq n$

6.11. Escribir un programa que lea dos números x y n y en una función calcule la suma de la progresión geométrica:

$1 + x + x^2+x^3+ \cdots + x^n$

6.12. Escribir un programa que encuentre el valor mayor, el valor menor y la suma de los datos de entrada. Obtener la media de los datos mediante una función.

6.13. Escribir una función que acepte un parámetro x ($x \neq 0$) y devuelva el siguiente valor

$x^5(e^{2x}-1)$

6.14. Escribir una función con dos parámetros, x y n, que devuelva lo siguiente:

$x + \frac{x^n}{n} - \frac {x^{n+2}}{n+2}$  si $x \geq 0$

$\frac{x^{n+1}}{n + 1} - \frac {x^{n-1}}{n-1}$  si $x < 0$

6.15. Escribir una función que tome como parámetros las longitudes de los tres lados de un triángulo (`a`, `b` y `c`) y devuelve el área del triángulo.

$Área = \sqrt{p(p-a)(p-b)(p-c)}$ donde $p = \frac{a+b+c}{2}$

6.16. Escribir un programa mediante funciones que realiza las siguientes tareas:

1. Devolver el valor del día de la semana en respuesta a la entrada de la letra inicial (mayúscula o minúscula) de dicho día.
2. Determinar el número de días de un mes

6.17. Escribir un programa que lea una cadena de hasta diez caracteres que representan un número en numeración romana e imprima el formato de número romano y si equivalente en numeración arábiga. Los caracteres romanos y sus equivalentes son:

M 1000

D 500

C 100

L 50

X 10

V 5

I 1

Compruebe con sus programa los siguientes datos:

LXXXVI (86), CCCXIX (319), MCCLIV (1254)

6.18. Escribir una función que calcule cuántos puntos de coordenadas entera existen dentro de un triángulo del que se conocen las coordenadas de sus tres vértices.

6.19. Escribir un programa que mediante funciones determine el área correspondiente a la circunferencia circunscrita de un triángulo del que conocemos las coordenadas de los vértices.

6.20. Dado el valor de un ángulo escribir una función que muestra el valor de todas las funciones trigonométricas correspondientes al mismo.