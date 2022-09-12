# Día 17

[<< día 16](../16_day_sort/16_day_sort.md) | [Inicio](../README.md) | [Día 17](#día-17) | [día 18 >>](../18_day_tda_i/18d_day_tda_i.md)

## **Búsqueda**

Buscar significa encontrar si un dato en particular si existe en un arreglo o en una lista o no. El proceso de buscar un valor particular en una lista o arreglo es llamado búsqueda. Si el dato buscado es encontrado se dice que la búsqueda fue exitosa y la posición de dónde fue encontrado el dato es devuelta por el proceso de búsqueda. Sin embargo, si el valor no existe, entonces se dice que la búsqueda no fue exitosa. Existen diferentes algoritmos, pero tres de estas técnicas de búsqueda son populares

- Búsqueda lineal o búsqueda secuencial
- Búsqueda binaria
- Búsqueda de interpolación
- Búsqueda hash

## Búsqueda lineal o secuencial

Es una técnica simple usada para buscar un dato particular en un arreglo. La búsqueda lineal funciona por comparando el valor de las clave que se busca con cada elemento del arreglo en secuencia lineal hasta que se encuentra una coincidencia.

La búsqueda no sera exitosa si todos los elementos son leídos y el elemento deseado no es encontrado. Se deben considerar los siguientes puntos:

Es la manera más sencilla de buscar un elemento en una lista

Para buscar el dato secuencialmente, no importa si el arreglo esta ordenado o desordenado

Buscar en el siguiente arreglo

87, 25, 24, 39, 74, 1, 99, 12, 30, 67

Bucar el 74

**Algoritmo**

```c
ALGORITHM: SEQUENTIAL_SEARCH(ARR, N):
	SET I = 0, POS = -1
	REPEAT WHILE I < N 
		IF ( ARR[I] = VAL )
			POS = I
		END IF
	END WHILE
	RETURN POS
END ALGORITHM
```

### Complejidad del algoritmo de búsqueda lineal o secuencial

El tiempo de ejecución de la búsqueda final es $O(n)$, donde $n$ es el número de elementos en el arreglo. El algoritmo es llamado es búsqueda lineal porque su complejidad puede ser expresada de forma lineal, los cuales son el número de comparaciones para encontrar el elemento objetivo y este crece linealmente con respecto al tamaño del arreglo. En el mejor de los casos en la búsqueda es cuando el elemento se  encuentra en la primera posición del arreglo. Obviamente, en el peor de los casos ocurre cuando el elemento buscado es iguala al último elemento del arreglo. Sin embargo, en ambos casos las $n$ comparaciones tiene que ser realizadas.

### **Desventajas de la búsqueda lineal**

Es un proceso que consume mucho tiempo, y trabaja secuencialmente.

Puede ser aplicado solo a pequeñas cantidades de datos

Es un proceso muy lento y casi todos los datos tienen que ser accedamos en el proceso, en especial cuando el elemento a búscar esta al final del arreglo.

## Búsqueda binaria

La búsqueda binaria es un algoritmo de búsqueda extremadamente eficiente cuando se compara contra la búsqueda lineal. La búsqueda binaria funciona cuando un arreglo o lista esta ordenado.

En la búsqueda binaria, primero se compara el valor del dato a buscar cone l elemento que se encuentre en la posición de en medio de la estructura. Si el elemento coincide, entonces la posición del elemento es retornada. De otro modo, se realiza la búsqueda en la parte izquierda del arreglo o viceversa, se repite este proceso en la parte izquierda o derecha del arreglo.

### **Algoritmo de búsqueda binaria**

1. Encontrar el elemento del centro del arreglo `(n/2)`

2. Com para el elemento del centro con el elemento buscado

3. Si el elemento es el deseado entonces la búsqueda termina con éxito.

4. Si el dato es menor al elemento buscado, entones buscar en la parte baja del arreglo, los elemento del lado izquierdo.

5. Si el elemento es mayor que el del centro, la búsqueda se realiza en la parte derecha del arreglo

6. Se repiten estos pasos hasta encontrar el elemento o no tener sub-arreglos

```c
ALGORITHM: BINARY_SEARCH(ARR, N):
	SET BEG= lower_bound, END = upper_bound, POS = -1
	REPEAT WHILE ( BEG <= END ) DO
		SET MID = (BEG + END) / 2
		IF (ARR[MID] = VAL) THEN
			POS =  MID
		ELSE
			IF (ARR[MID] > VAL) THEN
				SET END = MID - 1
			ELSE 
				SET BEG = MID + 1
			END IF
		END IF
	END WHILE
	RETURN POS
END ALGORITHM
```

Ejemplo

0, 10, 20, 30, 40, 50, 60, 90, 100

VAL = 20

### **Complejidad del algoritmo de búsqueda binario**

En este algoritmo en cada comparación realizada el espacio de búsqueda es reducido a la mitad. Por lo que, podemos definir su eficiencia en el peor de los casos como $O(\log_10 n)$, donde  $n$ es el numero de elementos en el arreglo. Obviamente, en el mejor de los casos ocurre cuando el dato esta a la mitad del arreglo.

### **Desventajas de la búsqueda binaria**

La búsqueda binaria requiere que los elementos de los datos en el arreglo este ordenados, de otro modo, la búsqueda binaria no funciona.

Una búsqueda binaria no puede ser utilizada para situaciones donde hay muchas inserciones o eliminaciones de elementos en los arreglos.

[<< día 16](../16_day_sort/16_day_sort.md) | [Inicio](../README.md) | [día 18 >>](../18_day_tda_i/18d_day_tda_i.md)