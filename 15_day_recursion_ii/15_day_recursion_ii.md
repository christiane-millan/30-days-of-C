# Día 15

[<< día 14](../14_day_recursion/14_day_recursion.md) | [Inicio](../README.md) | [día 16 >>](../16_day_sort/16_day_sort.md)

# Recursión vs Iteración

La iterativa utiliza estructura de control repetitiva y la recursión utiliza una estructura de control de selección.

La iterativa utiliza explícitamente una estructura de control repetitiva mientras que la recursión consigue la repetición mediante sucesivas llamadas a la función.

La iteración y recursión implican cada una condición de parada. La iteración termina cuando la condición del bucle o ciclo no se cumplen, mientras que la recursión termina cuando se reconoce un caso base (se alcanza la condición de parada).

## Desventajas y ventajas de la recursión

### **Desventajas**

Todas las ocasiones que se realiza la llamada a la función, se requiere de tiempo suplementario para realizar cada llamada (costo en procesador y espacio en memoria).

Cada llamada de la función se realiza una creación y copia de las variables de la función, incrementa el consumo de memoria y tiempo de ejecución.

La recursividad es más lenta que un proceso iterativo porque requiere de una pila que gestione las llamadas realizadas a la función.

### **Ventajas**

La recursividad reduce el tamaño del código y lo hace fácil de entender. Existen numerosos problemas que son complejos que poseen naturaleza recursiva, por lo que son más fáciles de implementar mediante recursividad.

Cuando el consumo de tiempo y memoria sean decisivos o concluyentes para la resolución del problema, la solución a elegir debe ser, normalmente, la iterativa.

Aunque cualquier problema se puede resolver de manera recursiva, se puede implementar de manera iterativa con el uso de una pila. Es recomendable utilizar un enfoque recursivo cuando la solución del problema es más natural y produce un programa fácil de comprender y depurar.

Directrices para elegir entre la implementación de una solución recursivo o iterativa.

1. La solución recursiva deberá ser considerada cuando la implementación iterativa no sea posible.
2. La solución recursiva puede ser considerada cuando el tiempo de ejecución y consumo de memoria es aceptable de acuerdo a los limites del sistema.
3. Si ambas soluciones son factibles, la recursiva siempre consumida mayor cantidad de recursos computacionales.
4. Elegir la recursividad si la solución es más fácil de leer y comprender que la iterativa (considerar los costos extras de tiempo y memoria).

# Ejemplo, Torres de Hanoi

Es un juego que tiene sus orígenes en la cultura oriental y en un leyenda sobre el templo de Brahma cuya estructura simulaba una plataforma metálica con tres varillas y discos en su interior. El problema consiste en tres varillas A, B y C o postes en los que se alojan discos (n discos) que se pueden trasladar de una varilla a otra libremente pero con la condición: cada disco es ligeramente inferior en diámetro al que esta justo debajo de él.

Las torres de Hanoi es un rompecabezas matemático que consiste en tres varillas y un número de discos de diferentes tamaños  los cuales pueden ser trasladados de una varilla a otra libremente. El rompecabezas comienza con los discos ordenados y apilados de manera ascendente en una varilla, el disco más pequeño se encuentra en la cima formando un cono. El objetivo de el acertijo es mover todos los discos de una varilla ( varilla origen) a otra varilla (destino) con la ayuda de la tercera varilla (auxiliar).

El acertijo tienen las siguientes reglas:

1. No colocar un disco sobre de un de menor tamaño.
2. Solo un disco puede ser movido a la vez.

## **Diseño del algoritmo iterativo**

```c
ALGORITHM: HANOI (n)
	COMPUTE number_of_moves = 2^n -1 
	IF n % 2 = 0 THEN 
		Interchange destination pole and auxiliary
	FOR I = 1 to number_of_moves
		IF I % 3 = 1 THEN
			Legal movement of top disk between source and destination
		IF I % 3 = 2 THEN
			Legal movement of top disk between source and auxiliary
		IF I % 3 = 0 THEN
			Legal movement of top disk between auxiliary and destination
END ALGORITHM
```

Ejemplo: Con tres discos

[<< día 14](../14_day_recursion/14_day_recursion.md) | [Inicio](../README.md) | [Arriba](#día-15) | [día 16 >>](../16_day_sort/16_day_sort.md)