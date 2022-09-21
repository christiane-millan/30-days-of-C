# Día 19

[<< día 18](../18_day_tda_i/18d_day_tda_i.md) | [Inicio](../README.md) | [día 20 >>]()

La operación de introducir (leer) datos en el sistema se denomina **lectura** y la generación de datos del sistema se denomina **escritura**. La lectura de datos se realiza desde el teclado e incluso desde unidades de disco duro y la escritura de datos se realiza en el monitor y en la impresora del sistema.

Las funciones de entrada/salida no están definidas en el propio lenguaje C, sino que están incorporadas en cada compilador de C bajo la forma de biblioteca de ejecución. En C existe la biblioteca stdio.h estandarizada por ANSI. Esta biblioteca proporciona tipos de datos, macros y funciones para acceder a los archivos. El manejo de archivos en C se hace mediante el concepto de flujo (stream) o canal y también denominado secuencia. Los flujos pueden estar abiertos o cerrados, conducen los datos entre el programa y los dispositivos externos. Con las funciones proporcionadas por la biblioteca se pueden tratar archivos secuenciales, de acceso directo, archivos indexados, etc.

## Flujos

Un flujo (stream) es una abstracción que se refiere a un flujo o corriente de datos que fluye entre  un origen o fuente (productor) y un destino o sumidero ( consumidor). Entre el origen y el destino debe existir una conexión o canal (pipe) por la que circulan los datos. La apertura de un archivo supone establecer la conexión del programa con el dispositivo que contiene el archivo, por el canal que comunica el archivo con el programa van a fluir las secuencias de datos. Hay tres flujos o canales abiertos automáticamente:

```c
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;
```

Estas tres variables se inicializan al comenzar la ejecución del programa y permite admitir secuencias de caracteres, en modo texto. Tienen el siguiente cometido:

- `stdin` asocia la entrada estándar (teclado) con el programa.
- `stdout` asocia la salida estándar (pantalla) con el programa.
- `stderr` asocia la salida de mensaje de error (pantalla) con el programa.

Cuando se ejecuta `printf()` se escribe en `stdout`, en pantalla y cuando se quiere leer una variable con `scanf()` se captura la sencuencia de entrada `stdin`.

El acceso a los archivos se hace con un buffer intermedio. Se puede pensar en el buffer com una arreglo donde se van almancenando los datos dirigidos al archivo, o desde el archivo; el buffer se vuelca cuando de una forma u otra se da la orden de vaciarlo. Por ejemplo, cuando se llama a la función para leer una cadena del archivo, la función lee tantos caracteres como quepan en el buffer. A continuación se obtiene la cadena del buffer, una posterior llamada a la función obtendrá la siguiente cadena del buffer y así sucesivamente hasta que se quede vacío y se llene con una llamada posterior a la función de lectura. El lenguaje C trabaja con archivos como buffer y esta diseñado para acceder a una amplia gama de dispositivos, de tal forma que trata cada dispositivo com una secuencia, pudiendo haber secuencias de caracteres y secuencias binarias. Con las secuencias se simplifica el manejo de archivos en C.

## Apuntador `FILE`

Los archivos se encuentra en dispositivos externos como cintas, cartuchos, discos, cd, etc. y tienen un nombre y unas características. En el programa el archivo tiene un nombre interno que es una apuntador a una estructura predefinida (apuntador a archivo). Esta estructura contiene información del archivo, como la dirección del buffer que utiliza, el modo de apertura del archivo, el último carácter leído del buffer y otros detalles que generalmente el usuario no necesita saber. El identificador de la estructura es `FILE` y esta declarada en el archivo de cabecera `stdio.h`.

```c
typedef struct{
      short level;
      unsigned flags;/* estado del archivo: lectura, binario ... */
      char fd;
      unsigned char hold;
      short bsize;
      unsigned char *buffer, *curp;
      unsigned istemp;
      short token;
}FILE;
```

El detalle de los campos de `FILE` puede cambiar de un compilador a otro.

Ejemplo de uso de FILE

```c
FILE *pf;
FILE* show(FILE *); /*prototipo de una función */
```

## Apertura de un archivo

Para procesar un archivo, primero es necesario abrir el archivo. La apertura del archivo supone conectar el archivo externo con el programa e indicar cómo va a ser tratado el archivo: binario o de caracteres, etc. El programa accede a los archivos a través de un apuntador a la estructura `FILE`, la función de apertura devuelve dicho apuntador. La función para abrir un archivo es `fopen()`, el formato de llamada es:

```c
fopen(file_name, mode);
```

La función devuelve un apuntador `FILE`, a través de dicho apuntador el programa hace referencia al archivo, La llamada `fopen()`, se debe de hacer de tal forma que el valor que devuelve se asigne a una variable apuntador a `FILE`, para así después referirse a dicha variable. 

Esta función puede detectar un error al abrir el archivo, por ejemplo que el archivo no exista y se quiera leer, entonces devuelve `NULL`. 

Ejemplo. Declaración de una variable de tipo apuntador a `FILE`. Y sentencia de apertura de un archivo.

```c
FILE * pf;
pf = fopen(file_name, mode);
```

Ejemplo de apertura de un archivo

```c

FILE *pf;
char nm[ ] = "C:LICENSIA.EST";
pf = fopen(nm, "r");
if (pf == NULL)
{
	puts("Error al abrir el archivo.");
	exit(1); 
}
```

Otro ejemplo de apertura de archivo

```c
FILE *ff;
char* arch = "C:JARDINES.DAT";

if ((ff = fopen(nm, "w"))== NULL)
{
	puts("Error al abrir el archivo para escribir.");
	exit(−1);
}
```

### Modos de apertura de un archivo

Al abrir el archivo con `fopen(`) el sengundo arguento especifica el modo a tratar el archivo. Los archivos se establecen en modo lectura, escritura o añadido y si es de texto o binario.

Los modos básicos se expresan en la siguiente tabla:

Los modos de abrir un archivo binario son: `“rb”`, `“wb”`, `“ab”`, `“r+b”`, `“w+b”` y `“a+b”`.

Ejemplo de apertura de archivos

```c
#include <stdio.h>
#include <stdlib.h>

FILE *pf1, *pf2;
char org[ ] = "C:LICENCIA.EST";
char dst[ ] = "C:RESUMEN.REC";

pf1 = fopen(org,"rt");
pf2 = fopen(dst,"wb");
if (pf1 == NULL || pf2 == NULL)
{
	puts("Error al abrir los archivos.");
	exit(1);
}
```

### `NULL` y `EOF`

pass

### Cierre de archivos

Al terminar la ejecución de un programa, es necesario cerrar el archivo, para que entre otras acciones se vuelque el buffer y se actualize el archivo.

La función `fclose(ptr_file)` cierra el archivo asociado con el apuntador `ptr_file`, devuelve `EOF` si ha habido un error al cerrar.

```c
#include <stdio.h>
...   
FILE *pf1, *pf2;
...   
pf1 = fopen("C:\\DATOS.DAT","at");
pf2 = fopen("C:\\TEMPS.RET","wb");
...
fclose(pf1);
fclose(pf2);
```

### Volcado del buffer: `fflush()`

En el proceso de entrada/salida con archivos no se realiza accediendo directamente al dispositivo externo sino a un buffer (memoria interna). La operación de grabar escribe los datos en el buffer, en el momento que está lleno se vuelca al dispositivo externo. La operación de lectura vuelva datos del archivo al buffer de tal forma que se lee de este, cuando se ha leído todo el buffer la misma operación de lectura vuelca nuevos datos desde el archivo al buffer para seguir leyendo de este.

La finalidad de buffer es disminuir el tiempo de acceso a los archivos. La operación de cierre de un archivo vuelva el buffer en el archivo. En C la función fflush() vuelca el buffer del archivo pasado como argumento.

```c
FILE *fc;
fc = fopen("file_name", "w");
...
fflush(fc);
```

En ocasiones es necesario volcar el flujo de entrada del teclado, sobre todo cuando se mezcla la entrada de cadenas `gets()` y números `scanf()`. La función `fflush(stdin)` hace que se vacíe el buffer de entrada.  

```c
int cuenta;
char b[81];
...
printf("Cantidad: ");
scanf("%d",&cuenta);
fflush(stdin);
printf("Dirección: ");
gets(b);
```

## Funciones de entrada/salida para archivos

Una vez que se ha abierto un archivo en modo escritura, para guardar los datos se utilizan funciones asociadas a `FILE`: `fprintf()`, `fscanf()`, `fputs()`, `fgets()` para escribir y leer cualquier dato del programa en un archivo de texto.

### Funciones `putc()` y `fputc()`

Ambas funciones son idénticas; putc() está definida como macro. Escribe un carácter en el archivo asociado con el apuntador FILe. Devuelve el carácter escrito, o bien EOF si no puede escribirlo. El formato de llamada:

```c
putc(c, ptr_file);
fputc(c, ptr_file);
```

donde `c` es el carácter a escribir. 

Ejemplo, se crea un archivo SALIDA.PTA con los caracteres introducidos por teclado.

```c
#include <stdio.h>
int main( )
{
	int c;
	FILE* pf;
	char *salida = "\\SALIDA.TXT";

	if ((pf = fopen(salida,"wt")) == NULL)
	{
		puts("ERROR EN LA OPERACION DE APERTURA");
		return 1; 
	}
  
	while ((c=getchar( ))!=EOF)
  {
		putc(c,pf);
	}
	fclose(pf);
	
return 0; 
}
```

### Funciones `getc()` y `fgetc()`

Estas dos funciones son iguales, tienen el mismo formato y la misma funcionalidad; son recíprocas a `putc()` y `fputc()` pero estas leen un carácter (el siguiente) del archivo asociado con el apuntador `FILE` y devuelva el carácter leído o `EOF` si es fin de archivo ( o si ha habido un error). 

Ejemplo, se desea leer el archivo `SALIDA.PTA` creado en el ejercicio anterior para mostrarlo en pantalla y contar las líneas que tiene.

```c
#include <stdio.h>
  
int main( )
{
	int c, n=0;
  FILE* pf;
  char *nombre = "\\SALIDA.TXT";
  if ((pf = fopen(nombre,"rt")) == NULL)
  {
    puts("ERROR EN LA OPERACION DE APERTURA");
		return 1; 
	}
  while ((c=getc(pf))!=EOF)
  {
    if (c == '\n')
    {
       n++; printf("\n");
    }
    else
       putchar(c);
	}
  printf("\nNúmero de líneas del archivo: %d",n);
  fclose(pf);
  return 0;
}
```

### Funciones `fputs()` y `fgets()`

Estas funciones escriben o leen, respectivamente, una cadena de caracteres en el archivo asociado. 

- La función `fputs()` escribe una cadena de caracteres. La función devuelve `EOF` si no ha podido escribir la cadena, un valor no negativo si la escritura es correcta.
- La función `fgets()` lee una cadena de caracteres del archivo. Termina la captación de la cadena cuando lee el carácter de fin de línea, o bien cando ha leído `n-1` caracteres, donde `n` es una argumento de la función. La función devuelve un apuntador a la cadena devuelta o `NULL` si ha habido algún error.

```c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MX 121
#define MN 30

int main( ) {
	FILE *in, *out;
	char nom1[ ]= "\\CARTAS.DAT";
	char nom2[ ]= "\\PRIMERO.DAT";
	char cad[MX];
	in = fopen(nom2,"rt");
	out= fopen(nom1,"at");
	if (in == NULL || out == NULL)
	{
		puts("Error al abrir archivos. ");
		exit(−1); 
	}
    
	while (fgets(cad,MX,in)) /*itera hasta que devuelve puntero NULL*/
	{
		if (strlen(cad) >= MN)
			fputs(cad,out);
		else puts(cad);
	}
	
	fclose(in);
	fclose(out);
	return 0;
}
```

### Funciones `fprintf()` y `fscanf()`

Las funciones `fprintf()` y `fscanf()` permiten escribir o leer variables de cualquier tipo de datos estándar, los códigos de formato indican a C la transformación que debe realizar con la secuencia de caracteres con los flujos (archivos asociados) a que se aplican. Estas dos funciones tienen como primer argumento el apuntador (puntero) a `FILE` asociado al archivo de texto.

```c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
/* declaración de tipo global estructura */
typedef struct {
  char* nm;
  int dia;
  int ms;
  int aa;
  char mes[11];
}PERSONA;

void entrada(PERSONA* p);
char* mes_asci(short n);

int main( )
{
  FILE *pff;
  char nf[ ]= "\\PERSONS.DAT";
  char r = 'S';
  if ((pff = fopen(nf,"wt"))==NULL)
  {
		puts("Error al abrir archivos. ");
		exit(−1); 
	}
  while (toupper(r) == 'S')
  {
    PERSONA pt;
    entrada(&pt);
    printf("%s %d-%d-%d %s\n",pt.nm,pt.dia,pt.ms,pt.aa,pt.mes);
    fprintf(pff,"%s %d-%d-%d %s\n",pt.nm,pt.dia,pt.ms,pt.aa,pt.mes);
    printf("Otro registro?: "); scanf("%c%*c",&r);
  }
  fclose(pff);
  return 0;
}

/* se leen los atributos de una persona por teclado */
void entrada(PERSONA* p)
{
	char bf[81];
	printf("Nombre: "); 
	gets(bf);
	p->nm =(char*)malloc((strlen(bf)+1)*sizeof(char));
	strcpy(p->nm,bf);
	printf("Fecha de nacimiento(dd mm aaaa): ");
	scanf("%d %d %d%*c",&p->dia,&p->ms,&p->aa);
	printf("\n %s\n",mes_asci(p->ms));
	strcpy(p->mes,mes_asci(p->ms));
}

char* mes_asci(short n)
{
	static char *mes[12]= {
    "Enero", "Febrero", "Marzo", "Abril",
    "Mayo", "Junio", "Julio", "Agosto",
    "Septiembre", "Octubre", "Noviembre", "Diciembre"};
 if (n >= 1 && n <= 12)
    return mes[n-1];
 else
    return "Error mes";
}
```

### Función `foef()`

Diversas funciones de lectura de caracteres devuelven `EOF` cuando leen el carácter de fin de archivo. Con dicho valor, que es una macro definida en stdio.h, ha sido posible formar bucles para leer un archivo completo. La función `foef()` realizar el cometido anterior, devuelve un valor distinto de 0 (`true`) cuando se lee el carácter de fin de archivo, en caso contrario devuelve 0 (`false`).

```c
int c, n=0; FILE* pf;
char *nombre = "\\SALIDA.TXT"; .. .
while (!feof(pf))
{
     c=getc(pf);
     if (c == '\n')
     {
        n++; printf("\n");
     }
.. .
```

### Función `rewind()`

Una vez que se alcanza el fin de archivo, nuevas llamadas a `feof()` siguen devolviendo un valor distinto de cero (`true`). Con la función `rewind()` se sitúa el apuntador del archivo al inicio de este.

```c
#include <stdio.h>
#include <string.h>

FILE* pg;
char nom[ ]="PLUVIO.DAT";
char buf[121];
int nl = 0;

if ((pg = fopen(nom,"rt") )== NULL)
{
	puts("Error al abrir el archivo.");
	exit(−1);
}

while (!feof(pg))
{
  fgets(buf,121,pg); nl++;
}
rewind(pg);

while (!feof(pg))
{
.. . }
```

## Archivos binarios en C

La apertura de un archivo en modo binario en C requiere utilizar el modo `b`. Los archivos binarios son secuencias de 0s y 1s. Los archivos binarios optimizan la memoria ocupada por un archivo (sobre todo en campos numéricos). La eficiencia de un archivo binario se contrapone al hecho de realizar la lectura en modo binario y solo se puede visualizar desde el entorno de un programa.

```c
FILE *pf1, *pf2, *pf3;
pf1 = fopen("gorjal.arr", "rb");
pf2 = fopen ("tempes.feb","w+b");
pf3 = fopen("telcon.fff","ab");
```

### Función de salida `fwrite()`

La función `fwrite()` escribe un buffer de cualquier tipo de dato en un archivo binario. 

Ejemplo, de apertura de un archivo en modo binario para escribir y grabar números reales en doble precisión mediante un bucle for.

```c
FILE *fd;
double x;

fd = fopen("reales.num","wb");
for (x = 0.5; x > 0.01;)
{
	fwrite(&x, sizeof(double), 1, fd);
	x = pow(x,2.);
}
```

El prototipo de la función es:

```c
size_t fwrite(const void *ptr,size_t tam,size_t n,FILE *pf);
```

Otro ejemplo

Se dispone de una muestra de las coordenadas de puntos en el plano representada por pares de números enteros `(x,y)`, tales que `1 ≤ × ≤100` y `1 ≤ y ≤100`. Se desea guardar en un archivo binario todos los puntos disponibles.
El nombre del archivo que se crea es `PUNTOS.DAT`. Según se lee se comprueba la validez de un punto y se escribe en el archivo con una llamada a la función `fwrite()`. La condición de terminación del bucle es la lectura del punto `(0,0)`.

```c
#include <stdio.h>

struct punto
{
	int x,y; 
};
  
typedef struct punto PUNTO;
  
int main( )
{
	PUNTO p;
	char *nom ="C:PUNTOS.DAT";
	FILE *pp;
	if ((pp = fopen(nom,"wb"))== NULL)
	{
		puts("\nError en la operación de abrir archivo.");
		return -1; }
	  puts("\nIntroduce coordenadas de puntos, para acabar: (0,0)");
	  do {
	    scanf("%d %d",&p.x,&p.y);
	    while (p.x<0 || p.y<0)
	    {
	      printf("Coordenadas deben ser >=0 :");
	      scanf("%d %d",&p.x,&p.y);
		  }
	    if (p.x>0 || p.y>0)
	    {
	      fwrite(&p, sizeof(PUNTO), 1, pp);
      }
    } while (p.x>0 || p.y>0);
	fclose(pp);
	return 0; 
}
```

### Función de lectura `fread()`

Esta función lee de un archivo n bloques de bytes y lo almacena en el buffer. El número de bytes de cada bloque (tamaño) se pasa como parámetro, al igual que el número `n` de bloques y la dirección del buffer (o variable) donde se almacena. El prototipo de la función está en `stdio.h`

```c
size_t fread(void *ptr,size_t tam,size_t n,FILE *pf);
```

Ejemplo, abrir un archivo binario para lectura. El archivo se lee hasta el fin del archivo y cada lectura es de un número real que se acumula en la variable s.

```c
FILE *fd;
double x,s=0.0;

if((fd = fopen("reales.num","rb"))== NULL)
	exit(-1);

while (!feof(fd))
{
	fread(&x, sizeof(double), 1, fd);
	s += x; 
}
```

Otro ejemplo

```c
#include <stdio.h>

struct punto
{
    int i, j;
};

typedef struct punto PUNTO;
FILE *pp;
int cuenta_pto(PUNTO w);

int main()
{
    PUNTO p;
    char *nom = "C:PUNTOS.DAT";
    float media, nmd, dnm;
    if ((pp = fopen(nom, "rb")) == NULL)
    {
        puts("\nError al abrir archivo para lectura.");
        return -1;
    }
    printf("\nIntroduce coordenadas de punto a buscar: ");
    scanf("%d %d", &p.i, &p.j);
    printf("\nRepeticiones del punto (%d,%d): %d\n",
           p.i, p.j, cuenta_pto(p));
    /* Cálculo de la media i para un valor j */
    printf("Valor de j: ");
    scanf("%d", &p.j);
    media = nmd = dnm = 0.0;
    for (p.i = 1; p.i <= 100; p.i++)
    {
        int st;
        rewind(pp);
        st = cuenta_pto(p);
        nmd += (float)st * p.i;
        dnm += (float)st;
    }
    if (dnm > 0.0)
        media = nmd / dnm;
    printf("\nMedia de los valores de i para %d = %.2f", p.j, media);
    return 0;
}
/* Cuenta el número de veces del punto w */
int cuenta_pto(PUNTO w)
{
    PUNTO p;
    int r;
    r = 0;
    while (!feof(pp))
    {
        fread(&p, sizeof(PUNTO), 1, pp);
        if (p.i == w.i && p.j == w.j)
            r++;
    }
    return r;
}
```

## Funciones de acceso aleatorio

El acceso directo, aleatorio a los datos de un archivo se hace mediante su posición, es decir, el lugar relativo que ocupa. Tiene la ventaja de que se puede escribir registros en cualquier orden y posición. Es muy fácil acceder a la información que contiene. El incoveniente que tiene la organización directa es que necesita programar la relación que existe entre el contenido de un registro y la posición que ocupa.

Las funciones `fseek()` y `ftell()` se utilizan en el acceso directo a archivos en C. Estas funciones consideran el archivo como una secuencia de bytes, el número de bytes es el índice del archivo. Según sean leídos o escritos registros o datos en el archivo, el programa mantiene con la ayuda de un apuntador la posición actual. La función `ftell()` se conoce la posición. `fseek()` permite cambiar la posición del apuntador al archivo a una dirección determinada.

Las funciones `fsetpos()` y `fgetpos()` también permiten mover o conocer la posición actual del fichero.

### `fseek()`

Con `fseek()` se puede tratar al archivo como un arreglo, que es una estructura de acceso aleatorio. `fseek()` sitúa el apuntador del archivo en la posición aleatoria, dependiendo del desplazamiento y el origen relativo que se pasa como argumentos.

```c
typedef struct
{
    char nombre[41];
    int unidades;
    float precio;
    int pedidos;
} PRODUCTO;
PRODUCTO uno;
int n, stat;
FILE *pfp;
if ((pfp = fopen("conservas.dat", "r")) == NULL)
{
    puts("No se puede abrir el archivo.");
    exit(−1);
}
/* Se pide el número de registro */
printf("Número de registro: ");
scanf("%d", &n);
/* Sitúa el puntero del archivo */
stat = fseek(pfp, n * sizeof(PRODUCTO), 0);
/* Comprueba que no ha habido error */
if (stat != 0)
{
    puts("Error, puntero del archivo movido fuera de este");
    exit(−1) :
}
/* Lee el registro */
```

El segundo argumento de `fseek()` es el desplazamiento, el tercero es el origen relativo del desplazamiento (0 indica que empiece a contar desde el principio del archivo). EL formato de `fseek()` es: 

```c
fseek(puntero_archivo, desplazamiento, origen);
```

- `desplazamiento`  indica el número de bytes a mover, tiene que ser de tipo long
- `origen` es la posición desde la que se cuenta el número de bytes a mover, puede tener tres valores, que son:
    - `0` o  `SEEK_SET` cuenta desde el principio del archivo
    - `1`  o `SEEK_CUR` cuenta desde la posición actual del puntero al archivo
    - `2` o `SEEK_END` cuenta desde el final del archivo

La función `fseek()` devuelve un valor entero, distinto de cero si se comete un error en su ejecución, cero si no hay error. Prototipo:

```c
int fseek(FILE *pf,long dsplz,int origen);
```

### `ftell()`

La posición actual del archivo se puede obtener con la ayuda de `ftell()` y pasando un apuntador al archivo como argumento. La función devuelve la posición dad en número de bytes (un entero largo: `long int`) desde el inicio del archivo (byte 0).

```c
#include <stdio.h>
int main(void)
{
  FILE *pf;
  float x = 123.5;
  pf = fopen("CARTAS.TXT", "w");
  printf("Posición inicial: %ld\n",ftell(pf));
  fprintf(pf,"Caracteres de prueba");
  printf("Posición actual: %ld\n",ftell(pf));
  fwrite(&x,sizeof(float),1,pf);
  printf("Posición actual: %ld\n",ftell(pf));
  fclose(pf);
  return 0;
}
```

Para llamar a la función se utiliza como argumento el apuntador a `FILE`. El prototipo se encuentra en `stdio.h`

```c
long ftell(FILE *pf)
```

### Cambio de posición con `fgetpos()` y `fsetpos()`

Otra forma de conocer la posición actual o mover la posición en un archivo es mediante `fgetpos()` y `fsetpos()`.

La función `fgetpos()` tiene dos argumentos, el primero presenta al archivo (flujo) mediante un apuntador `FILE` asociado. El segundo argumento de tipo apuntador a `fpost_t` (tipo entero declarado en `stdio.h`) es de salida, la función le asigna la posición actual del archivo. Por ejemplo:

```c
FILE *pf;
fpos_t* posicion;
...
fgetpos(pf, posicion);
printf("Posición actual: %ld", (*posicion));
```

La función `fsetpos()` se utiliza para cambiar la posición actual del archivo. La nueva posición se pasa como segundo argumento (de tipo `const fpost_t*`) en la llamada a la función. El primer argumento es el apuntador `FILE` asociado al archivo. Por ejemplo, se lee a partir de una posición del archivo, posteriormente se vuelve a la misma posición con el fin de completar un determinado proceso:

```c
FILE *fc;
fpos_t* posicion;
registro reg;
fgetpos(fc, posicion);
while (condicion)
{
fread(&reg, sizeof(registro),1,fc)
... }
fsetpos(fc, posicion);
```

Las dos funciones devuelven cero si no ha habido error en la ejecución, en caso contrario devuelven un valor distinto de cero (el número del error). Sus prototipos están en `stdio.h` y son los siguientes:

```c
int fgetpos(FILE* pf, fpos_t* p);
int fsetpos(FILE* pf, const fpos_t* p);
```

Ejercicio.  En un archivo se quieren grabar las notas que tienen los alumnos de una asignatura junto al nombre del profesor y el resumen de aprobados y suspensos. La estructura será la siguiente:

- Primer registro con el nombre de la asignatura y curso
- Segundo registro con el nombre del profesor, número de alumnos, de aprobados y suspensos
- Cada uno de los alumnos, con su nombre y nota.

Se crea un archivo binario (modo `wb+`) con la estructura que se indica en el enunciado. Antes de
escribir el segundo registro(profesor) se obtiene la posición actual, llamando a `fgetpos()`. Una vez que se han grabado todos los registros de alumnos, se sitúa como posición actual, llamando a `fgetpos()`, el registro del profesor con el fin de grabar el número de aprobados y suspensos. Naturalmente, según se pide las notas de los alumnos se contabiliza si está aprobado o suspenso. La entrada de datos se realiza desde el teclado.

```c
#include <stdlib.h>
#include <stdio.h>
typedef struct
{
    char asg[41];
    int curso;
} ASGTA;
typedef struct
{
    char nom[41];
    int nal, aprob, susp;
} PROFS;
typedef struct
{
    char nom[41];
    float nota;
} ALMNO;
void entrada(ALMNO *a);
}

void main(void)
{
    ASGTA a;
    PROFS h = {" ", 0, 0, 0};
    /* valores iniciales: alumnos,
                 aprobados, suspensos */
    ALMNO t;
    FILE *pf;
    int i;
    fpos_t *p = (fpos_t *)malloc(sizeof(fpos_t));
    pf = fopen("CURSO.DAT", "wb+");
    if (pf == NULL)
    {
        printf("Error al abrir el archivo, modo wb+");
        exit(−1);
    }
    printf("Asignatura: ");
    gets(a.asg);
    printf("Curso: ");
    scanf("%d%*c", &a.curso);
    fwrite(&a, sizeof(ASGTA), 1, pf);
    printf("Nombre del profesor: ");
    gets(h.nom);
    printf("Número de alumnos: ");
    scanf("%d%*c", &h.nal);
    fgetpos(pf, p); /* guarda en p la posición actual */
    fwrite(&h, sizeof(PROFS), 1, pf);
    for (i = 1; i <= h.nal; i++)
    {
        entrada(&t);
        if (t.nota <= 4.5)
            h.susp++;
        else
            h.aprob++;
        fwrite(&t, sizeof(ALMNO), 1, pf);
    }
    fflush(pf);
    fsetpos(pf, p); /*se sitúa en registro del profesor */
    fwrite(&h, sizeof(PROFS), 1, pf);
    fclose(pf);
}
void entrada(ALMNO *a)
{
    printf("Nombre: ");
    gets(a->nom);
    printf("Nota: ");
    scanf("%f%*c", &(a->nota));
}
```

[<< día 18](../18_day_tda_i/18d_day_tda_i.md) | [Inicio](../README.md) | [Día 19](#día-19) | [día 20 >>]()
