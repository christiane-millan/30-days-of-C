# Día 16

[<< día 15](../15_day_recursion_ii/15_day_recursion_ii.md) | [Inicio](../README.md) | [día 17 >>](../17_day_search/17_day_search.md)

## Ordenamiento

Ordenar se refiere al proceso de colocar los datos contenidos en los elementos de un arreglo en un orden específico, tanto en orden ascendente o descendente. Mientras que la búsqueda facilita el acceso a los datos almacenados en un sistema computacional o una aplicación. Por ejemplo, al utilizar un teléfono móvil,  resultaría complicado encontrar los datos de un contacto en la agenda si no estuvieran ordenados o tuviéramos la posibilidad de buscar por su nombre.

Si los datos  almacenados en una computadora están ordenados resulta muy fácil y práctico recuperar la información. Por lo que, el proceso de ordenar los datos es una aplicación importante en las ciencias computacionales.

Un algoritmo de ordenamiento puede ser definido como un algoritmo que coloca los datos de los elementos de un arreglo o lista en un orden específico. Los datos pueden ser dispuesto en un orden numérico o algún otro orden predefinido.

Los algoritmos de ordenamiento se encuentran en dos categorías básicas de acuerdo con el tipo almacenamiento donde se encuentran los datos.

1. Ordenamiento interno, este tipo de ordenamiento se refiere cuando los datos son almacenados en la memoria principal de la computadora.
2. Ordenamiento externo, este tipo de ordenamiento se refiere cuando los datos son almacenados en archivos. Este tipo de algoritmo es aplicado, cuando la cantidad de datos almacenados es muy grande y no puede ser almacenados en memoria principal.

Tipos de métodos de ordenamiento

1. Ordenamiento por selección (Selection sort)
2. Ordenamiento por inserción (Inserción Sort)
3. Ordenamiento por mezcla (Merge sort)
4. Ordenamiento burbuja (Bubble sort)
5. Ordenamiento rápido (Quick sort)

## Ordenamiento burbuja

El ordenamiento burbuja o ordenamiento de intercambio es un algoritmo de ordenamiento simple. Funciona mediante la repetición de mover el elemento más grande al final del arreglo. En burbuja, se comparan dos elementos y son intercambiados sí están en la posición incorrecta. Si el elemento con el índice menor  es mayor que el otro elemento, entonces son intercambiados de lugar. Este proceso es repetido hasta que la lista este ordenada.

Técnica del ordenamiento burbuja

La idea básica de burbuja es, si se asume que se tiene un arreglo `ARR` de tamaño `N`, entonces el número de iteraciones requerido para ordenar el arreglo será de `N-1`

Paso 1. Durante la primera iteración, el valor más grande en el arreglo es colocado en la ultima posición `(N-1)`

Paso 2. Durante la segunda iteración el segundo valor más grande será colocado en la segunda posición más grande del arreglo `(N-2)`.

Paso 3. Durante la tercera iteración el tercer valor más grande será colocado en la posición `N-3`, ya si sucesivamente.

Este procedimiento es repetido hasta que todos los elementos en el arreglo son revisados y colocados en su posición correcta, lo que significa que el arreglo ha sido ordenado.

```c
ALGORITHM: BUBBLE_SORT(ARR, N):
	FOR I = 1 to N-1
		FOR J = 1 to N -1
			IF (ARR[J] > ARR[J + 1]) THEN
				Interchange ARR[J] with ARR[J+1]
			END IF
		END FOR
	END FOR
END ALGORITHM
```

Ejemplo

## Ordenamiento Rápido (Quick sort)

El ordenamiento rápido también conocido como ordenamiento por intercambio de particiones fue desarrollado por C. A. R. Horas, es un algoritmo de ordenamiento ampliamente usado el cual utiliza el enfoque divide y vencerás. Se divide el arreglo no ordenado en dos sub-arreglos. El método divide y vencerás divide un problema en pequeños problemas, y así sucesivamente. Cuando no hay elementos en el arreglo resultante  o solo queda un elemento, entonces el arreglo esta ordenado. El algoritmo quick sort tienen una complejidad de $O(n log_{10}n)$

Funcionamiento de Quick sort.

1. Un elemento del arreglo es seleccionado y llamado pivote
2. Después de elegir el pivote, todos los elementos del arreglo son ordenado de tal manera que todos los elementos menores que el elemento pivote estaban en el lado izquierdo, y todos los elementos mayores que el elemento pivote serán colocados del lado derecho. Después de ordenar todos los elementos, el pivote es colocado en su posición final. Por lo tanto, este proceso es conocido como particionado.
3. Ahora, los dos sub-arreglos ordenados serán recursivamente ordenados.

Técnica de ordenamiento rápido.

1. Inicialmente se asigna el índice del primer elemento a `LEFT` y `POS`. De manera similar, se asigna el índice del último elemento a `RIGHT` . Ahora, `LEFT = 0`, `POS = 0`, `RIGHT = N-1` (asumiendo que hay N elementos en el arreglo)
2. Comenzar con el elemento que es apuntado por `RIGTH`, se recorrerá todo el arreglo de derecha a izquierda, comparando cada elemento con el primer elemento apuntado por `POS`. `ARR[POS]` deberá ser siempre menor que `ARR[RIGHT]`.
    
    Si `ARR[POS]` es menor que `ARR[RIGHT]` entonces se continua comparando hasta que `RIGHT = POS`, si `RIGHT = POS` entonces eso significa que el pivote es colocado en su posición correcta.
    
    Si `ARR[RIGTH] < ARR[POS]`, entonces intercambiar los dos valores y continuar con el siguiente paso.
    
    Asignar `POS = RIGTH`
    
3. Comenzar con el primer elemento el cual es apuntado por `LEFT`, se recorre todo el arreglo de izquierda a derecha, comparando cada elemento con el elemento apuntado por `POS`. `ARR[POS]` deberá ser siempre mayor que `ARR[LEFT]`
    
    Si `ARR[POS]` es mayor que `ARR[RIGTH]` entonces se continúa con la comparación hasta que `LEFT = POS`. Si `LEFT = POS` entonces significa que el pivote esta colocado en la posición correcta.
    
    Si `ARR[LEFT] > ARR[POS]`, entonces se intercambian los dos valores y se regresa al paso anterior.
    

```c
ALGORITHM: QUICK_SORT(ARR, BEG, END):
	IF (BEG < END)
		CALL PARTITION( ARR, BEG, END, POS)
		CALL QUICK_SORT(ARR, BEG, POS-1)
		CALL QUICK_SORT(ARR, POS + 1, END)
	END IF
END ALGORITHM

ALGORITHM: PARTITION(ARR, BEG, END, POS):
	SET LEFT = BEG, RIGTH = END, POS = BEG, TEMP = 0
	WHILE (TEMP = 0) DO
		WHILE ( ARR[RIGHT] >= ARR[POS] && POS != RIGTH) DO
			SET RIGHT = RIGHT - 1
		END WHILE
		IF (POS = RIGHT) THEN
			SET TEMP = 1
		ELSE
			IF (ARR[POS] > ARR[RIGHT])
				Interchange ARR[POS] with ARR[RIGHT]
				SET POS = RIGHT
			END IF
		END IF
		IF TEMP = 0 THEN
			WHILE (ARR[POS] >= ARR[LEFT] && POS != LEFT) DO
				SET LEFT = LEFT + 1
			END WHILE

			IF (POS = LEFT) THEN
				SET TEMP =1
			ELSE 
				IF (ARR[LEFT] > ARR[POS] THEN
					Interchange ARR[POS] with ARR[LEFT]
					SET POS = LEFT
				END IF
			END IF
		END IF
	END WHILE
END ALGORITHM
```

### Complejidad de ordenamiento rápido (Quick sort)

La eficiencia del tiempo de ejecución para Quick sort es  $O(n \log_{10} n)$ en promedio en el mejor de los casos. Sin embargo, en el peor de los casos que ocurrirá si el arreglo ya esta ordenado y el elemento de más a la izquierda es seleccionado como elemento pivote. En el peor de los casos su eficiencia es de $O(n^2)$

Ejemplo

25, 7, 39, 17, 30, 52

## Ordenamiento por mezcla (Merge sort)

El método de ordenamiento por mezcla sigue el enfoque divide y veneras. El enfoque divide y vencerás es un buen enfoque en el cual se divide el arreglo en dos partes iguales, si el arreglo tienen n elementos cada sub arreglo será de tamaño n/2 elementos cada uno. Sin no hay elementos en el arreglo (o lista) o si el arreglo solo contiene un elemento, entonces ya esta ordenado. Sin embargo, si una arreglo tiene mas elementos, este es dividido en dos sub-arreglos que contengan la misma cantidad de elementos en ellos. Vencer, es el proceso de ordenar los dos sub-arreglos recursivamente usando el ordenamiento por mezcla. Finalmente, los dos sub-arreglos son mezclados en un solo arreglo ordenado.

### **Tecnica de ordenamiento por mezcla**

1. Si el arreglo tiene cero o un elemento en él, entonces no necesita ser ordenado ya que ese arreglo ya esta ordenado.
2. De otro modo, se hay mas elementos en el arreglo, entonces se divide el arreglo en dos sub-arreglos que contenga la misma cantidad de elementos
3. Cada sub-arreglo ahora es ordenado recursivamente usando el método de ordenamiento de mezcla.
4. Finalmente, los dos sub-arreglos son mezclados en un solo arreglo ordenado.

```c
ALGORITHM: MERGE_SORT(ARR, BEG, END):
	IF (BEG < END)
			SET MID = (BEG + (END - BEG))/2
			CALL MERGE_SORT(ARR, BEG, MID)
			CALL MERGE_SORT(ARR, MID + 1, END)
			CALL MERGE(ARR,  BEG, MID, MID + 1, END)
	END IF
END ALGORITHM

ALGORITHM: MERGE(ARR, BEG, MID, MID + 1, END):
	SET I = BEG, J = MID + 1, K = 0
	WHILE (I <= MID) && (J <= END)
		IF (ARR[I] > ARR[J]) THEN
			SET TEMP[K] = ARR[J]
			SET J = J +1
			SET K = K +1
		ELSE
			IF (ARR[J] > ARR[I]) THEN
				SET TEMP[K] = ARR[I]
				SET I = I +1
				SET K = K +1
			ELSE
				SET TEMP[K] = ARR[J]
				SET J = J +1
				SET K = K +1
				SET TEMP[K] = ARR[I]
				SET I = I +1
				SET K = K +1
			END IF
		END IF
	END WHILE

// Copy the remaining elements of the left
	WHILE ( I <= MID)
		SET TEMP[K] = ARR[I]
		SET I = I + 1
		SET K = K + 1
	END WHILE

// Copy the remaining elements of the right
	WHILE ( J <= END)
		SET TEMP[K] = ARR[J]
		SET I = I + 1
		SET K = K + 1
	END WHILE

	SET IND = 0
	WHILE (IND < K)
		SET ARR[IND] = TEMP[IND]
		SET IND = IND + 1
	END WHILE
END ALGORITHM
```

**Complejidad del ordenamiento por mezcla**

El tiempo de ejecución del algoritmo por mezcla es $O(n log_{10} n)$. Este tiempo de ejecución se alcanza en promedio también n el peor de los casos. A pesar de que tiene un tiempo optimo en su complejidad, algunas veces puede tener tiempos de ejecución de  $O(n)$.

Ejemplo

[<< día 15](../15_day_recursion_ii/15_day_recursion_ii.md) | [Inicio](../README.md) | [Día 16](#día-16) | [día 17 >>](../17_day_search/17_day_search.md)