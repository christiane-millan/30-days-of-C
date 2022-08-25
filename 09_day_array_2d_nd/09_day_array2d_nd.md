# Arreglos bidimensionales y N-dimensionales

En esta sección se extiende el concepto de un arreglo de una dimensión a muchas dimensiones. Los arreglos multidimensionales ocurren en miles de circunstancias de la vida diaria, desde un tablero de juego de damas chinas o un tablero de ajedrez, una tabla de multiplicar, o los pixeles de una pantalla hasta mas complejos objetos tridimensionales como un espacio volumétrico.

Es común presentar un arreglo de dos dimensiones como un arreglo de arreglos de una dimensión. De ese modo un arreglo de tres dimensiones es un arreglo de arreglos de dos dimensiones. Por lo tanto, un arreglo de n-dimensiones es un arreglo de arreglos de (n-1)-dimensiones.

Un arreglo de una dimensión es llamado vector en algunos dominios, mientras que en otros casos es referido como un arreglo lineal. Un arreglo tienen una representación grafica tanto horizontal como vertical.

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/1cf3bff9-a0c1-403b-894b-5ac88225e9ee/Untitled.png)

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/90f1bd72-b833-4779-8a20-c989666a6e56/Untitled.png)

Un arreglo de dos dimensiones puede ser conceptualizado como un arreglo de arreglos de una dimensión o com una matriz que consiste de filas y columnas. En el mundo real, existen muchos conceptos de ejemplos de arreglos de dos dimensiones: tabla periódica de los elementos, una pantalla compuesta de pixeles, una hoja de cálculo, la selección de snacks en una máquina expendedora, por mencionar algunos. Un arreglo de dos dimensiones en C, por lo tanto, es una herramienta util para modelar muchas matrices o  grids del mundo real.

Una representación gráfica de esto es la siguiente:

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/0817607e-40ae-45ae-910e-90684ce76a63/Untitled.png)

Si consideramos una arreglo de dos dimensiones como una matriz, se obtiene una tabla o grid. Y se puede representar como sigue:

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/c8e892a8-ca11-4aaf-8a28-294a7987e17e/Untitled.png)

Un arreglo tridimensional puede ser conceptualizado como un arreglo de arreglos de dos dimensiones, con tres dimensiones (x, y, z) donde x y y son las filas y columnas. Este objeto tiene ahora un volumen dado por z (denominados capas).

En el mundo real existen muchos ejemplos de arreglos de tres dimensiones: oficinas en un edificio de multiples pisos, el espacio tridimensional en el que vivimos, dimensiones espaciales para modelado de objetos. L

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/10f3dfe0-e9c9-4ad3-aa18-a46455e3482a/Untitled.png)

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/3bac50db-eb16-481d-ab2e-555215728176/Untitled.png)

Se puede conceptualizar un arreglo de N dimensiones como un arreglo de arreglos de (n-1) dimensiones. En este punto resulta difícil realizar una conceptualización visual de arreglos multidimensionales. En C se permite un número ilimitado de arreglos multidimensionales. 

## Declaración de arreglos de dos dimensiones

```c
int array_2D[4][5];
```

```c
const int size_1D = 5;
const int size_2D = 4;

int array_2D[size_2D][size_1D]
```

```c
int rows = 4;
int cols = 5;

int array_2D[row][cols]
```

## Inicialización de arreglos de dos dimensiones

Inicializar todos los elementos en 0. 

```c
int array_2D[4][5] = {0};
```

Dar valores diferentes a cada elemento del arreglo:

```c
int array_2D[size_2D][size_1D] = { {11 , 12 , 13 , 14 , 15 } ,
                                   {21 , 22 , 23 , 24 , 25 } ,
                                   {31 , 32 , 33 , 34 , 35 } ,
                                   {41 , 42 , 43 , 44 , 45 ) };
```

## Declaración de arreglos tridimensionales

```c
const int size_1D = 5;
const int size_2D = 4;
const int size_3D = 3;

int array_3D[3][4][5];
int array_3D[size_1D][size_2D][size_3D];
```

```c
int x = 5;
int y = 4;
int z = 3;

int array_3D[x][y][z];
```

## Inicialización de arreglos de tres dimensiones

```c
int array_3D[3][4][5] = {0};
```

```c
int array3D[size3D][size2D][size1D] = 
                           { { {111 , 112 , 113 , 114 , 115 },
                               {121 , 122 , 123 , 124 , 125 } },
                             { {211 , 212 , 213 , 214 , 215 },
                               {221 , 222 , 223 , 224 , 225 } },
                             { {311 , 312 , 313 , 314 , 315 },
                             {321 , 322 , 323 , 324 , 325 } } };
```

## Declaración de arreglos n-dimensionales

```c
const int size_1D = 5;
const int size_2D = 4;
const int size_3D = 3;
const int size_4D = 7;

int array4D[size_4D][size_3D][size_2D][size_1D];
```

La inicialización de un arreglo n-dimensional puede ser tediosa, por lo que se puede utilizar la asignación de un valor para todos los elementos o utilizar ciclos.

```c
int array4D[size_4D][size_3D][size_2D][size_1D] = {0};
```

## Acceso a elementos de un arreglo multidimensional

Para acceder a los elementos de un arreglo se deben considerar tanto las dimensiones del arreglo  el uso de un rango valido de índices.

Para acceder a un elemento de un arreglo, se utilizan `[]`. Es importante recordar que C comienza el primer indice en la posición 0. 

```c
int third;
first = array_1D[2];          // third element.
first = array_2D[0][2];       // third element of 1st row.
first = array_3D[0][0][2];    // third element of 1st layer and 1st row. 
first = array_4D[0][0][0][2]; // third element of 1st volume, 1st layer, 
                             // and 1st row
```

Utilizando literales numéricas que indique el último elemento  de cada dimensión, se puede acceder al último elemento de cada un de los arreglos:

```c
int last;
last = array_1D[4];          // last element.
last = array_2D[3][4];       // last element of last row.
last = array_3D[2][3][4];    // last element of last layer of last row.
last = array_4D[6][2][3][4]; // last element of last volume, last layer,
                            // and last row.
```

Al utilizar las constantes es más fácil realizar el acceso anterior:

```c
int last;
last = array_1D[size_1D-1];                     // last element.
last = array_2D[size_2D-1][size_1D-1];           // last element of last row.
last = array_3D[size_3D-1][size_2D-1][size_1D-1]; // last element of last layer of last row.
last = array_4D[size_4D-1][size_3D-1][size_2D-1][size_1D-1];
```

Se puede recuperar valores o asignar valores con la notación de arreglos:

```c
last = INT_MAX;
array_1D[size_1D-1] = last;
array_2D[size_2D-1][size_1D-1] = last;
array_3D[size_3D-1][size_2D-1][size_1D-1] = last;
array_4D[size_4D-1][size_3D-1][size_2D-1][size_1D-1] = last;
```

## Manipulación de arreglos de multidimensionales con ciclos

Existen múltiples formas de acceder a arreglos multidimensionales con ciclos, pero una de las formas más comunes es utilizar `for()…` anidados. 

Para atravesar un arreglo bidimensional, se utilizan dos ciclos. El ciclo exterior controla las filas y el ciclo interior controla las columnas.

```c
for( j = 0; j < size_2D ; j++ )  {    // j : 0..(size2D-1)
  for( i = 0; i < size_1D ; i++ )  {  // i : 0..(size1D-1)
    array_2D[j][i] = (10*j) + i ;
  }
}
```

Para atravesar un arreglo tridimensional, se utiliza el ciclo utilizado para arreglos bidimensionales con un ciclo adicional. El ciclo externo controla las capas, y los ciclos internos controlan las filas y columnas. 

```c
for( k = 0 ; k < size_3D ; k++ )  {      // k : 0..(size3D-1)
  for( j = 0 ; j < size_2D ; j++ )  {    // j : 0..(size2D-1)
    for( i = 0 ; i < size_1D ; i++ )  {  // i : 0..(size1D-1)
      array_2D[k][j][i] = (k*100) + (j*10) + i ;
    }
  }
}
```

## Arreglos multidimensionales como paso de parámetros

Ahora se crearán funciones que permiten manipular los arreglos:

Una función que permite incializar un arreglo de dos dimensiones y una función que permite inicializar un arreglo de tres dimensiones.

```c
void initialize2DArray( int row , int col , int array[row][col] )  {
  for( int j = 0 ; j < row ; j++ )  {      // j : 0..(row-1)
    for( int i = 0 ; i < col ; i++ )  {    // i : 0..(col-1)
      array[j][i] = (10*(j+1)) + (i+1);
    }
  }
}

void intialize3DArray( int x , int y , int z , int array[z][y][x] ){
  for( int k = 0 ; k < z ; k++ )  {         // k : 0..(z-1)
    for( int j = 0 ; j < y ; j++ )  {       // j : 0..(y-1)
      for( int i = 0 ; i < x ; i++ )  {     // i : 0..(x-1) 
        array[k][j][i] = (100*(k+1)) + (10*(j+1)) + (i+1);
      }
    }
```

Ejemplo: Una función que suma los elementos de cada arreglo:

```c
int sum2DArray( int row , int col , int array[row][col])  {
  int sum = 0;
  for( int j = 0 ; j < row ; j++ )  {       // j : 0..(row-1)
    for( int i = 0 ; i < col ; i++ )  {     // i : 0..(col-1)
      sum += array[j][i];
    }
  }
  return sum;
}

int sum3DArray( int z , int y , int x , int array[z][y][x] )  {
  int sum = 0;
  for( int k = 0 ; k < z ; k++ )  {           // k : 0..(z-1)
    for( int j = 0 ; j < y ; j++ )  {         // j : 0..(y-1)
      for( int i = 0 ; i < x ; i++ )  {       // i : 0..(x-1)
        sum += array[k][j][i];
      }
    }
  }
  return sum;
}
```

Ejemplo: Una función que imprime el contenido de cada uno de los arreglos:

```c
void print2DArray( int row , int col , int array[row][col] ) {
  for( int j = 0 ; j < row ; j++ )  {      // j : 0..(row-1)
    for( int i = 0 ; i < col ; i++ )  {    // i : 0..(col-1)
      printf("%4d" , array[j][i]);
    }
    printf("\n");
  }
  printf("\n");
}

void print3DArray( int z , int y , int x , int array[z][y][x] ) {
  for( int k = 0 ; k < z ; k++ )  {          // k : 0..(z-1)
    for( int j = 0 ; j < y ; j++ )  {        // j : 0..(y-1)
      for( int i = 0 ; i < x ; i++ )  {      // i : 0..(x-1)
        printf("%4d" , array[k][j][i]);
      }
      printf("\n");
    }
    printf("\n");
  }
}
```

Una función main() para probar las funciones anteriores

```c
#include <stdio.h>
#include "arraysND.h"

int main( void )
{
  const int size1D = 5;
  const int size2D = 4;
  const int size3D = 3;

  int array2D[size2D][size1D];
  int array3D[size3D][size2D][size1D];

  int total = 0;
  
  initialize2DArray(  size2D , size1D , array2D );
  print2DArray(       size2D , size1D , array2D );
  total = sum2DArray( size2D , size1D , array2D );
  printf( "Total for array2D is %d\n\n" , total );
  
  initialize3DArray(  size3D , size2D , size1D , array3D );
  print3DArray(       size3D , size2D , size1D , array3D );
  total = sum3DArray( size3D , size2D , size1D , array3D );
  printf( "Total for array3D is %d\n\n" , total );
}
```

Resultado de la ejecución

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/fa312952-6fff-4994-893a-87181c9fa434/Untitled.png)

Modificar el programa anterior para que imprima las filas y columnas de la siguiente forma

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/ee1fe6c9-1b44-4b0a-9180-51d3f109c100/Untitled.png)

Ejercicio: Comprobar si una matriz de números enteros es simétrica respecto a la diagonal principal. a matriz se genera internamente, con la función `rand()` y argumento `N(8)` para que la matriz tenga valores de 0 a 7. El tamaño de la matriz se pide como dato de entrada. La función `simetric()` determina si la función es simétrica. La función `main()` genera matrices hasta encontrar una que sea simétrica y la escribe en pantalla.

```c
/*
Determina si una matriz es simétrica. La matriz se genera con números alea- torios de 0 a 7. El programa itera hasta encontrar una matriz simétrica.
  */
  #include <stdlib.h>
  #include <stdio.h>
  #include <time.h>
  #define N 8
  #define randomize (srand (time (NULL)))
  #define random(num) (rand ()% (num))
  void gen_mat(int a[][N], int n);
  int simetrica(int a[][N], int n);
  void escribe_mat(int a[][N], int n);
  int main(void)
  {
 int a[N][N];
int n,i,j;
int es_sim;
randomize;
/* define matriz de tamaño máximo N */

do {
       printf("\nTamaño de cada dimensión de la matriz, máximo %d: ",N);
       scanf("%d",&n);
    }while (n<2 || n>N);
    do {
       gen_mat(a,n);
       es_sim = simetrica(a,n);
       if (es_sim)
       {
         puts("\n\Encontrada matriz simétrica.\n");
         escribe_mat(a,n);
       }
  } while (!es_sim);
return 0; }
void gen_mat(int a[][N], int n)
{
  int i,j;
    for (i=0; i<n; i++)
}
for (j=0; j<n; j++)
  a[i][j]= random(N);
int simetrica(int a[][N], int n)
{
  int i,j;
  int es_simetrica;
  for (es_simetrica=1,i=0; i<n-1 && es_simetrica; i++)
  {
    for (j=i+1; j<n && es_simetrica; j++)
      if (a[i][j] != a[j][i])
       es_simetrica= 0;
}
  return es_simetrica;
}
void escribe_mat(int a[][N], int n)
{
  int i,j;
  puts("\tMatriz analizada");
    puts("\t –––––––––––––– \n");
  for (i=0; i<n; i++)
  { putchar('\t');
    for (j=0; j<n; j++)
         printf("%d %c",a[i][j],(j==n-1 ?’\n ':' '));
} }
```
