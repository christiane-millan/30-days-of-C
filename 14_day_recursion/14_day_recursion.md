# Día 14

[<< día 13](../13_day_dinamic_arrays/13_day_dinamic_arrays.md) | [Inicio](../README.md) | [día 14 >>](../15_day_recursion_ii/15_day_recursion_ii.md)

## **Recursividad**

Si consideramos la siguiente función matemática

$f(x) = \left \{ \begin{matrix} f(0) = 0\\ f(x) = 2f(x-1) + x^2\end{matrix}\right.$

Para calcular $f(5)$  se requiere realizar una sustitución de la siguiente manera:

$f(5) = 2f(5-1) + 5^2 = 2f(4) + 5^2$

Antes de resolver esta expresión es necesario resolver $f(4)$ , es decir:

$f(4) = 2f(4-1) + 4^2 = 2f(3) + 4^2$

Ahora es necesario resolver $f(3)$  antes de calcular el resultado de $f(4)$

$f(3) = 2f(3-1) + 3^2 = 2f(2) + 3^2$

Y lo mismo ocurre con $f(2)$

$f(2) = 2f(2-1) + 2^2 = 2f(1) + 2^2$

Y con $f(1)$

$f(1) = 2f(1-1) + 1^2 = 2f(0) + 1^2$

Cuando se presenta el caso $f(0)$  de acuerdo a la función de recurrencia el resultado es $f(0)=0$ , por lo tanto no es necesario realizar ningún cálculo adicional.

Ahora que se conoce que $f(0)=0$  se puede sustituir en $f(1)$  para conocer el resultado de $f(1) = 1$. Ahora que se conoce el valor de $f(1)=1$ se puede sustituir en $f(2)$ y obtener como resultado $f(2)=6$,  así sucesivamente se resuelven todas las expresiones pendientes, es decir $f(3)=21$, $f(4)=58$ y por último  $f(5)=141$.

En matemáticas, existen numerosas funciones que tienen el carácter recursivo. En la vida ordinario ocurre en numerosas situaciones, por lo que en la programación a este proceso también se le conoce como recursividad (recursión).

La recursividad es el proceso que realiza una función al llamarse así misma un número de veces para realizar una operación. Dicho de otra manera, una función recursiva es una función que se llama así misma y ejecuta la misma instrucción repetidamente.

Ejemplo de recursividad

```c

```

El fundamento de la recursividad se define en dos principios o casos:

El **caso base** es aquel donde el valor de la función es conocido directamente sin la necesidad de aplicar la recursividad

El **caso progresivo** es el caso que se resuelve de manera recursiva, este caso se dice que es progresivo porque siempre debe conducir a alcanzar el caso base.

Ejemplo

Ejemplo de una función matemática que suma los primeros $n$ números enteros positivos.

Como punto de partida se puede afirmar que  $n=1$  se tienen que sumar $S(1)=1$, para $n=2$ se puede escribir $S(2) = S(1) + 2$ , en general aplicando la inducción matemática se tiene:

$S(n)=s(n-1)+n$

La definición de la función suma $S()$ respecto de sí misma, siempre para un caso más pequeño $(n-1)$. $S(2)$ respecto a $S(1)$, $S(3)$ respecto a  $S(2)$ y en general  $S(n)$ respecto a  $S(n-1)$.

El algoritmo que resuelve el problema de la suma de los   primeros enteros de forma iterativa, utiliza un simple bucle for:

```c
ALGORITHM: SUM (n)
	SET sum = 0
	FOR I = 1 to n
		sum = sum + I
	RETURN sum
END ALGORITHM
```

El algoritmo que calcula la suma mediante un proceso iterativo debe considerar una condición de parada. Así, en el caso recursivo de  $S(6)$ se define cómo: $S(6)= 6 + S(5)$ , de acuerdo a la definición $S(5) = 5 + S(4)$, este proceso continua con $S(4)= 4 + S(3)$, $S(3)= 3 + S(2)$, $S(2) = 2. + S(1)$, hasta $S(1)$ por definición se conoce que  $S(1) =1$. En matemáticas, la definición de una función en términos de sim misma se denomina definición inductiva y conduce naturalmente a una implementación recursiva. El caso $S(1) = 1$ es esencial dado que se detiene, potencialmente, una cadena de llamadas repulsivas. El caso base es esencial en una solución recursiva.

En resumen el algoritmo que calcula la suma debe considerar:

$S(n) = \left \{ \begin{matrix} 1 \text{, si }n = 1\\ n + S(n-1) \text{, si } n> 1\end{matrix}\right.$

La implementación de un algoritmo recursivo para realizar la suma de los primeros   números enteros:

```c
ALGORITHM: SUM (n)
	IF n =  1 THEN
		RETURN 1
	ELSE
		RETURN n + SUM(n-1) 
END ALGORITHM
```

**Ejemplo sobre el cálculo del factorial de un número entero.**

El factorial de un número entero positivo es  denotado por $n!$  y se define como el producto de todos los enteros menores o iguales a  , es decir:

$n! = n \cdot (n-1) \cdot (n-2) \cdot (n-3) \cdot \ldots \cdot 3 \cdot 2 \cdot 1$

$1! = 1$

$0! = 1$

Por ejemplo:

$5! = 5 \cdot 4  \cdot 3 \cdot 2 \cdot 1 = 120$

Ejemplo de factorial solución iterativa:

```c
ALGORITHM: FACTORIAL (n)
	SET result = 1
	FOR I = 2 to n
		result = result * I
	RETURN result
END ALGORITHM
```

Ejemplo de factorial solución recursiva:

```c
ALGORITHM: FACTORIAL (n)
	IF n = 0 OR n = 1 THEN
		RETURN 1
	ELSE
		RETURN n *  FACTORIAL(n-1)
	END IF 
END ALGORITHM
```

Las cuatro reglas básicas para el diseño de una función recursiva:

1. Caso base, de acuerdo a los fundamentos de la recursividad, el caso base es aquel que no requiere de ningún cálculo para conocer el resultado de la llamada de la función.
2. Caso recursivo, como se explico anteriormente se debe detectar aquel caso que es repetitivo y que se resuelve con una llamada de la función así misma, siempre cuando este orientado en alcanzar el caso base.
3. Regla de diseño, se asume que todas las llamadas recursivas se resuelven de manera contabilizada.
4. **Regla del interés compuesto** es importante asegurarse de no duplicar la resolución de la misma instancia de un problema en llamadas recursivas separadas.

**Ejemplo sobre el cálculo de la serie Fibonacci.**

En la serie Fibonacci: 0, 1, 1, 2, 3, 5, 8, 13, 21, … se observa que la serie comienza con 0 y 1, y tiene la propiedad de que cada elemento es la usa de dos elementos anteriores, por ejemplo:

$0 + 1= 1$

$1 +1 = 2$

$2 + 1 = 3$

$3 + 2 = 5$

$5 + 3 = 8$

Entonces se puede establecer que:

$fibonacci(0) = 0$

$fibonacci(1) = 1$

…

$fibonacci(n) = fibonacci(n-1) + fibonacci(n-2)$

La definición recursiva será:

$fibonacci(n) = n \text{, si} n= 0 \text{ o } n=1$

$fibonacci(n) = fibonacci(n-1) + fibonacci(n-2)$

La implementación iterativa de la serie Fibonacci sería:

```c
ALGORITHM: FIBONACCI (n)
	IF n = 0 OR n = 1
		RETURN n
	SET fibonacci_lower = 0
	SET fibonacci_upper = 1
	FOR I = 2 to n
		x = fibonacci_lower
		fibonacci_lower = fibonacci_upper
		fibonacci_upper = x + fibonacci_lower 
	RETURN fibonacci_upper
END ALGORITHM
```

La implementación recursiva es:

```c
ALGORITHM: FIBONACCI (n)
	IF n = 0 OR n = 1
		RETURN n
	ELSE
		RETURN FIBONACCI(n-1) + FIBONACCI(n-2) 
END ALGORITHM
```

La formulación recursiva puede resultar ineficiente si  se repiten los cálculos realizados anteriormente.

## Tipos de recursividad

Supongamos que $f_1$ y $f_2$  son dos funciones. Entonces:

**Recursividad directa**, es aquella donde la función $f_1$  manda llamar a  $f_1$ en el caso progresivo, es decir, se manda llamar a sí misma.

En la **recursividad indirecta** la función $f_1$ en el caso progresivo mandar llamar a la función $f_2$, pero la función $f_2$ para cumplir con su objetivo requiere manda llamar a $f_1$, por lo tanto la llamada recursiva se realiza a través de $f_2$ y por eso se le conoce como indirecta.

Ejemplo, escribir una aplicación para mostrar en pantalla el alfabeto, utilizando recursión indirecta.

```c
ALGORITHM: FUNCA (c)
	IF c > ‘A’
		FUNCIONB(c) 
	PRINT(c)
END ALGORITHM

ALGORITHM: FUNCB(c)
	FUNCIONB(c - 1) 
END ALGORITHM
```

[<< día 13](../13_day_dinamic_arrays/13_day_dinamic_arrays.md) | [Inicio](../README.md) | [Día 14](#día-14) [15 >>](../15_day_recursion_ii/15_day_recursion_ii.md)