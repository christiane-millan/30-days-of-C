# Día 7

* [Funciones en línea, macros con argumentos](#funciones-en-línea-macros-con-argumentos)
* [Funciones de biblioteca](#funciones-de-biblioteca)

## Funciones en línea, macros con argumentos

Las funciones en línea sirven para aumentar la velocidad de un programa. Si la función es una expresión, el código es pequeño y se utiliza muchas veces en el programa. Realmente no son funciones, el preprocesador expande o sustituye la expresión cada vez que se le llama. Así la siguiente función:

```c
float fesp(float x)
{
	return (x*x + 2*x –1);
}
```

puede sustituirse por la función en línea (macro con argumentos):

```c
#define fesp(x) (x * x + 2 * x - 1)
```

Este programa se realizan cálculos de la función para valores de x de un intervalo

```c
#include <stdio.h>
#define fesp(x) (x * x + 2 * x –1)

void main()
{
    float x;
    for (x = 0.0; x <= 6.5; x += 0.3)
        printf("\t f(%.1f) = %6.2f ", x, fesp(x));
}
```

Antes de que el compilador construya el ejecutable de este programa, el preprocesaro sustituye toda llamada a `fexp(x)` por la expresión asociada. Realmente es como si se hubiese escrito:

```c
printf("\t f(%.1f) = %6.2f ", x, (x * x + 2 * x –1));
```

### Creación de macros con argumentos

Por ejemplo la función media de tres valores se puede escribir:

```c
#define MEDIA3(x,y,z) ((x) + (y) + (z))/3.0
```

Este segmento de código invoca a `MEDIA3`

```c
double a = 2.9;
printf("\t %lf ", MEDIA3(a,4.5,7));
```

- En esta llamada MEDIA3 se pasan argumentos de distintos tipo.
- Es importante tener en cuenta que en las macros no hay comprobación de tipos
- Para evitar problemas de prioridad utilizar paréntesis en cada argumento e incluso encerrar entre paréntesis toda la expresión.

Ejemplo de una expresión que ocupa más de una línea.

```c
#define FUNCION3(x) {                     \ 
											if ((x) <−1.0)      \ 
												(−(x) * (x) + 3); \
										  else if ((x) <= 1)  \ 
												(2 * (x) + 5);    \
									    else                \ 
												((x) * (x)-5);    \
										}
```

Ejemplo. Una aplicación de una macro con argumentos es `VolCono()`, que calcula el volumen de la figura `Cono`.

$(V = \frac{1}{3} \pi r^2h)$

```c
#include <stdio.h>

#define PI 3.141592
#define VOLCONO(radio,altura) ((PI*(radio*radio)*altura)/3.0)

int main() {
    float radio, altura, volumen;
    
		printf("\nIntroduzca radio del cono: ");
    scanf("%f",&radio);
    printf("Introduzca altura del cono: ");
    scanf("%f",&altura);

    volumen = VOLCONO(radio, altura);
    
		printf("\nEl volumen del cono es: %.2f",volumen);
    return 0;
 }
```

## Funciones de biblioteca

Todas las versiones del lenguaje C ofrecen una biblioteca estándar de funciones que proporcionan soporte para operaciones realizadas con frecuencia. Estas funciones permiten realizar operaciones con solo una llamada a la función (sin necesidad de escribir su código fuente).

Las funciones estándar o predefinidas, como así se denominan las funciones pertenecientes a la biblioteca estándar, se dividen en grupos; todas las funciones que pertenecen al mismo grupo se declaran en el mismo archivo de cabecera.

Los nombres de los archivos de cabecera estándar más utilizados son:

`<assert.h> <ctype.h> <errno.h> <float.h> <limits.h> <locale.h> <math.h> <setjmp.h> <signal.h> <stdarg.h> <stddef.h> <stdio.h> <stdlib.h> <string.h> <time.h>` 

Para utilizar las funciones o una macro se debe conocer su número de argumentos, sus tipos y el tipo de valores de retorno.

Algunos de los grupos de funciones más usuales son:

- E/S estándar
- matemáticas
- rutinas estándar
- Visualizar ventana de texto
- de conversión
- de diagnóstico
- de manipulación de memoria
- de control de procesos
- clasificación (ordenación)
- directorios
- fecha y hora
- de interfaz
- diversas
- búsqueda
- manipulación de cadenas
- gráficos

### Funciones de carácter

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/276cafb4-28b4-4c19-9ca3-89242466d89f/Untitled.png)

Ejemplo: Programa que lee un carácter del teclado y comprobar si es una letra. 

```c
#include <stdio.h>
#include <ctype.h>

int main()
{
    char inicial;
    printf("¿Cuál es su primer carácter inicial?: ");
    scanf("%c%*c", &inicial);
    
    while (!isalpha(inicial))
    {
        puts("Carácter no alfabético ");
        printf("¿Cuál es su siguiente inicial?: ");
        scanf("%c%*c", &inicial);
    }

    puts("¡Terminado!");
    
    return 0;
}
```

Ejemplo: Programa que comprueba si la entrada es una V o una H

```c
#include <stdio.h>
#include <ctype.h>

int main()
{
    char resp;
    char c;
    
    printf("¿Es un varón o una hembra (V/H)?: ");
    scanf("%c", &resp);
    resp = toupper(resp);
    
    switch (resp)
    {
    case 'V':
        puts("Es un enfermero");
        break;
    case 'H':
        puts("Es una maestra");
        break;
    default:
        puts("No es ni enfermero ni maestra");
        break;
    }
    return 0;
}
```

### Funciones numéricas

Las funciones matemáticas disponibles son las siguientes:

- Funciones matemáticas de carácter general
- trigonométricas
- logarítmicas
- exponenciales
- aleatorias

### Funciones de utilidad

- `abs(n)`, `labs(n)`
- `atof(cad)`
- `atoi(cad)`, `atol(cad)`
- `div(num, denom)`
- `ldiv(num, denom)`