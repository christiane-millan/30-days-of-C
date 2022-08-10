# Día 3

* [Estructuras Secuenciales](https://github.com/christiane-millan/30-days-of-C/tree/main/03_day__sequential#estructuras-secuenciales)

## Estructuras de control

Los programas hasta este punto se ejecutan de forma secuencial, es decir, cada sentencia se ejecuta después de otra. La primera sentencia de una función se ejecuta y continua hasta la última sentencia y solo se ejecutan por única vez. Es común que para resolver un problema se requiera definir cuales sentencias serán ejecutadas y cuales no. Las **estructuras de control** determinan la secuencia o flujo de ejecución de las sentencias. 

Las estructuras de control se dividen en tres tipos:

- Secuencia
- Selección (decisión)
- Repetición

Como se menciona anteriormente las estructuras de control determinan el flujo de ejecución de un programa o función. Esto permite combinar instrucciones o sentencias en una unidad lógica con un punto de entrada y un punto de salida.

## Estructuras secuenciales

El flujo secuencial es un conjunto de secuencias encerradas entre llaves que se pueden utilizar para especificar un flujo de secuencia.

```c
{
	sentencia_1 ;
	sentencia_2;
	.
	.
	.
	sentencia_n;
}
```

## Ejercicios

1.1. Salida en pantalla

Escribir un programa que imprima su nombre y dirección.

Ejemplo:

```Bash
Nombre: Homero J. Simpson
Dirección: Av. Evergreen 742. Sprinfield, NT 48007. USA.
```

1.2. Salida en texto largo en pantalla

Escribir un programa que imprima una página de texto con no más de 40 caracteres por línea.

Ejemplo:

```Bash
Pass
```

1.3. Letrero

Escribir un programa que imprima las letras UTM con asteriscos.

Ejemplo:

```Bash
*       *   ***********   *           *
*       *        *        * *       * * 
*       *        *        *  *     *  *
*       *        *        *   *   *   *
*       *        *        *    * *    *
*       *        *        *     *     *
*       *        *        *           *  
*       *        *        *           *
  *****          *        *           *
```



2.1. Escribir las siguentes expresiones aritméticas como expresiones de computadora. La potencia puede utilizar la función `pow()`. Ejemplo: $(x + y)^2$ es `pow(x + y, 2)`.

![Expresiones](./expressions.png)

2.2. Escribir un programa que lea un entero, lo multiplique por 2 y a continuación lo escriba de nuevo en la pantalla.

2.3. Escribir un programa que intercambie los valores entre dos variables.

2.4. Escribir un programa que lea dos enteros en las variables `x` y `y`, y a continuación obtenga los valores de:

* La división x entre y
* El residuo de la división de x entre y

2.5. Escribir un programa que **solicite al usuario** la longitud y anchura de una habitación y acontinuación visualice su superficie con cuatro decimales (formto 5.4f).

2.6. Escribir un programa que convierte un número dado en segundos en el equivalente a minutos y segundos.

2.7. Escribir un programa que solicite dos números decimales y calcule su suma, visualizando la suma. Por ejemplo si los números son `57.45` y `425.55`, el program visualizará:

```bash
   57.45
+ 425.55
________
  483.00
```

2.8. Escribir un programa para calcular la longitud de la circunferencia y el área del círculo para un radio introducido por el teclado.

2.9. Escribir un programa que visualice valores como:

```bash
7.1
7.12
7.123
7.1234
7.12345
7.123456
```

## Problemas

2.16. Escribir un programa que lea dos enteros de tres dígitos y calcule e imprima su producto, cociente y el resto cuando el primero se divide entre el segundo. La salida será justificada a la derecha.

2.17. Una temperatura Celsius puede ser convertidad a una temperatura equivalente F de acuerdo con la siguinte fórmula: $F = \frac{9}{5}C+ 32$

Escribir un programa que lea la temperatura en Celsius y la escriba en F.

2.18. Un sistema de ecuaciones lineas 

$ax + bx = x$
$dx + ey = f$

se puede resolver con las siguiente fórmulas:

$ x = frac{ce -bf}{ae - bd}$

$ y = frac{af - cd}{ae - bd}$

Diseñar un programa que lea dos conjuntos de coefiencientes (a, b y c; d, e y f) y visualice los valores de `x` y `y`.

2.19. Escribir un programa que dibuje el rentángulo siguiente:

```bash
* * * * * * * * * * * * 
*                     *
*                     *
*                     *
*                     *
* * * * * * * * * * * * 
```

2.20. Modificar el programa anterior (2.19), de modo que se lea una palabra de cinco letras y se impriman en el centro del rectángulo.

2.21. Escribir un programa que lea dos números y visualice el mayor.

2.22. Escribir un programa para convertir una medida dada en pies a sus equivalentes en: a) yardas; b) pulgadas; c) centimetros; d) metros (1 pie = 12 pulgadas, 1 yarda = 3 pies, 1 pulgada = 2.54 cm, 1 m = 100 cm). Leer el número de pies e imprimir el número de yardas, pies, pulgadas, centímetros y metros.

2.23. Teniendo como datos de entrada el radio y la altura de un cilindro se desea calcular: el área lateral y el volumen del cilindro.

2.24. Calcular el área de un triángulo mediante la fórmula: $area = (p (p - a)(p - b)(p - c))^{1/2}$ donde p es el semiperímetro, $p = (a + b + c)/2$ y $a$, $b$ y $c$ son lostres lados del triángulo.

2.25. Escribir un programa que calcule y escriba el producto, conciente entero y resto de dos números de tres cifras.

2.26. Construir un programa para obtener la hipotenusa y los ángulos agudos de un triángulo rectángulo a partir de las longitudes de los catetos.

2.27. Escribir un programa que desgloce cierta cantidad de segundos introducida por teclado en su equivalente en semanas, días, horas, minutos y segundos.

2.28. Escribir un programa que exprese cierta cantidad de pesos mexicanos en billetes y monedas del curso legal.

2.29. La fuerza de atracción entre dos masas, $m_1$ y $m_2$ separadas por una distancia $d$, está dada por la fórmula:
$F = \frac{G * m_1 * m_2}{d^2}
donde $G$ es la constante de gravitación universal
$G = 6.673 \cdot 10^{-8} cm^3/g \cdot s^2$
Escribir un programa que lea la masade de dos cuerpos y la distancia entre ellos y a continuación ontenga la fuerza gravitacional entre ellos. La salida debe ser en dinas; un dina es igual a $g \cdot cm 7 s^2$.

2.30 La relación entre los lados $(a, b)$ de un triángulo y la hipotenusa $(h)$ viene dada por la fórmula:
$a^2 + b^2 = h^2$

Escribir un programa que lea la longitud de los lados y calcule la hipotenusa.

2.31. Escribir un programa que lea la hora del un día en notación de 24 horas y la respuesta en notación de 12 horas. Por ejemplo: si la entrada es 13:45, la salida será:

```bash
1:45 PM
```

El programa pedirá al usuario que introduzca exactamente cinco caracteres. Así por ejemplo, las nueve en punto se introducen como:

```bash
09:00
```

2.31. Escribir un programa que lea el radio de un círculo y a continuación visualice; área del círculo, diámetro del circulo y longitud de la circunferencia del círculo.

2.32. * Escribir un programa que determine si un año es bisiesto. Un año es bisiesto si es múltiplo de 4 (por ejemplo, 1984). Sin embargo, los años múltiplos de 100 solo son bisiestos cuando a la vez son múltiples de 400 (por ejemplo, 1800 no es bisiesto, mientras que 2000 si lo es).

2.33. * Construir un programa que indique si un número introducido por teclado es positivo, igual a cero, o negativo.
