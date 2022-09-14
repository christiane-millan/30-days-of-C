# Día 18

[<< día 17](../17_day_search/17_day_search.md) | [Inicio](../README.md) | [día 19 >>](../19_day_files/19_day_files.md)

## Introducción

El proceso de abstracción de datos permite inventar nuevos datos o definir nuevos tipos de datos de acuerdo al contexto del problema que se plantea resolver.  El resultado de este proceso son los tipos de datos abstractos (ADT, Abstract Data Types). Se dice que son los tipos de datos definidos por el usuario, pero por usuario se refiere a quién realiza el proceso de abstracción que en este caso es el diseñador de un algoritmo de computadora o el desarrollador de un software. Es importante no confundir con el usuario de programa.

Para entender el significado de ADT solo necesitamos dividir el termino en dos partes “tipo de dato” y “abstracción”. En párrafos anteriores hemos definido que un tipo de datos es de una variable es una colección de valores que una variable puede tomar.  El termino abstracto en el ámbito de las estructuras de datos significa ademas de la especificación detallada. Necesita ser considerada una descripción de las estructuras de datos con una lista de operaciones que pueden ser ejecutas sobre los datos dentro de la estructura.

Al utilizar esta técnica de abstracción de datos no solo es necesario representar la estructura que los compone, si no también, el comportamiento que deben tener.

Al implementar un ADT se debe considerar la representación de los datos y las operaciones sobre tales datos. En otra palabras un ADT se compone de estructuras de datos y los procedimientos que manipulan esas estructuras de datos.

Tipo de datos abstracto es un modelo matemático  para implementar un algoritmo es necesario debe hallarse una manera de representar los datos los TDA en función de los  tipos de datos y los operadores manejados por ese lenguaje.

Para representar un ADT se emplean **estructuras de datos** que son un conjunto de variables de distintos tipos, conectados entre sí de diversas formas.

“Una estructura de datos es una manera eficiente de almacenar y organizar elementos de información en la memoria de la computadora.” Mientras que los datos se refieren a un valor o un conjunto de valores, las estructuras son el método para organizar los datos. El objetivo de la estructura es almacenar, recuperar y actualizar los datos de manera eficiente.

Algunos ejemplos de estructuras de datos son pilas, colas, arreglos, árboles binarios, listas ligadas, tablas bash.

En componente básico de una estructura es la celda. Una celda es una caja capaz de almacenar un valor de algún tipo de dato básico o compuesto.

Las estructuras de datos se crean dando nombres a agregados de celdas y opcionalmente interpretando los valores de algunas celdas como representantes de **conexión entre celdas** (por ejemplo, apuntadores).

Un ejemplo sencillo es el **arreglo**, que es una sucesión de celdas de un tipo dado al cual se le llama celda se accede mediante un índice. Se hace referencia a un elemento mediante el nombre del arreglo y el indice. Otra forma de agrupar celdas en los lenguajes de programación es la estructura de **registros**. Un registro es una celda constituida por campos que pueden ser de distintos tipos.  **A menudo los registro se agrupan en arreglos**. Otra forma de agrupar es mediante **archivos**. Al igual que los arreglos de una dimensión los archivos es una secuencia de valores de un tipo particular, la diferencia es que el archivo no tiene un índice. Los archivos son accedido en forma secuencia. Un arreglo o un registro son estructuras de acceso aleatorio lo que significa que el tiempo  necesario para acceder a un componente del arreglo o de un registro es independiente del valor del indice del arreglo o del selector del campo. La ventaja de agrupar por archivos en lugar de hacerlo por arreglos es que el número de elementos de un archivo puede ser ilimitado y variable con el tiempo.

Otra forma de **agrupación de celdas** de los lenguajes de programación es la creación de relaciones entre celdas **mediante apuntadores y cursores**. Un apuntador es una celda cuyo valor indica o señala a otra. Representación grafica de las estructuras se muestran celdas con apuntares.

Las estructuras de datos son utilizadas en áreas como: diseño de compiladores, sistemas majadores de base de datos (DBMS), Inteligencia artificial, análisis numérico, paquetes de análisis estadístico, graficación (CGI), sistemas operativos y simulación.

Algunas estructuras de datos sacrifican velocidad para eficientes la utilización de memoria, mientras que otras sacrifican el uso de memoria con la finalidad de aumentar la velocidad.

# Operaciones sobre las estructuras de datos

En secciones anteriores definimos las diferencias entre los ADT y las estructura de datos. Como en parte de la definición de la implementación de una estructura de datos, es necesario definir las operaciones que son ejecutas por las estructuras de datos.

- **Creación** (Creation). Es el proceso de crear la estructura. Incluye la declaración e inicialización de la estructura.
- **Inserción** (Insertion). Es el proceso de agregar un nuevo elemento de datos a la estructura de datos. Por ejemplo, agregar los datos de un empleado que recién se ha integrado a la organización.
- **Eliminación** (Delete). Es el proceso de remover un elemento de dato en particular de una colección de elementos de datos. Por ejemplo, eliminar el nombre de un empleado que ha renunciado a su cargo dentro de la empresa.
- **Actualización** (Update). Es el proceso de modificar los elementos de datos de una estructura de datos. Por ejemplo, si la dirección de un alumno ha cambiado, debe ser actualizada.
- **Búsqueda** (Searching). Es usada para encontrar una estructura de datos en particular o todos los elementos de datos con la ayuda de una clave, por ejemplo, para encontrar los nombres de personas que viven en Querétaro.
- **Ordenación** (Sorting). Es el proceso de colocar en un orden específico los elementos de datos, puede ser de forma ascendente o descendente. Un ejemplo, es ordenar los nombres de los estudiantes por orden alfabético.
- **Fusión o Mezclado** (Merging). Es el proceso de combinar los elementos de datos de dos diferentes listas para formar una sola lista de elementos de datos.
- **Recorrido** (Traversal). Es el proceso de de acceder a cada elemento de dato exactamente solo una vez para ser procesado. Un ejemplo es para imprimir los nombres de todos los estudiantes de una clase.
- **Destrucción** (Destruction). Es el proceso de eliminar toda la estructura de datos. Es la última operación de una estructura de datos.

## Estructuras

Los **arreglos son estructuras de datos** que contienen un número determinado de elementos y todos los elementos han de ser del mismo tipo de datos, es decir, es una **estructura de datos homogénea**. Esta estructura es útil si se desea almacenar una lista de temperaturas tomadas durante el día. Pero si se requiere almacenar información de alumnos como nombre, edad, dirección, matrícula, etc. Los arreglos no so adecuados. La solución consiste en utilizar un tipo de dato **registro**, denominado **estructura en C.**

Los componentes de una estructura se llaman **miembros**. Cada miembro de una estructura puede contener valores de un tipo diferente de datos. Por ejemplo, se puede utilizar una estructura para almacenar distintos tipos de información sobre una persona, tal como su nombre estado civil, edad y fecha de nacimiento. Cada uno de estos elementos se denomina **nombre del miembro**. 

Una **estructura** es una colección de uno o más tipos de elementos denominados **miembros**, cada un de los cuales puede ser de un tipo de dato diferente.

Por ejemplo, suponga que se desea almacenar los datos de una colección de `movie`. Estos datos pueden ser:

- Título
- Director
- Duración
- Género
- Año de producción

La estructura movie tiene cinco elementos, después de definir los miembros, se debe determinar el tipo de dato a utilizar para cada miembro.

### Declaración de una estructura

Es un tipo de dato definido por el usuario, el formato de declaración es:

```c
struct <struct_name>
{
	<data_type1> <member_name1> 
	<data_type2> <member_name2> 
	...
	<data_typen> <member_namen>
};
```

Ejemplo:

```c
struct movie
{
	char title[30];
	char director[25];
	float duration;
	char genre[15];
	int year;
};
```

### Definición de variables de estructuras

Una estructura se accede utilizando una variable o variables que se pueden definir después de la declaración de la estructura. Se debe considerar la declaración y la definición. La diferencia técnica entre declaración y definición es:

- Una declaración específica simplemente el nombre y el formato de la estructura de datos, pero no reserva almacenamiento en memoria. La declaración específica un nuevo tipo de datos `struct` `<struct_name>`.
- La definición de variable para cada estructura crea un área en memoria en donde los datos se almacenan de acuerdo con el formato estructurado declarado.

Las variables de estructuras se pueden definir de dos formas:

1. Listando inmediatamente después de la llave de cierre de la declaración de la estructura.
2. Listando el tipo de estructura creado seguido por las variables correspondientes en cualquier lugar del programa antes de utilizar. 

La definición y declaración de una estructura movie se puede hacer de las siguientes formas:

```c
struct movie
{
	char title[30];
	char director[25;]
	float duration;
	char genre[15];
	int year;
} movie_1, movie_2, movie_3;
```

Segunda forma:

```c
struct movie
{
	char title[30];
	char director[25;]
	float duration;
	char genre[15];
	int year;
};

struct movie movie_1, movie_2, movie_3;
```

Otros ejemplo:

```c
struct info_libro
{
    char titulo[60];
    char autor[30];
    char editorial[30];
    int anyo;
} libro1, libro2, libro3;
 
struct info_libro libro1, libro2, libro3;
```

```c
struct corredor
      {
        char nombre[40];
        int edad;
        char sexo;
        char categoria[20];
        char club[26];
        float tiempo;
};

struct corredor v1, s1, c1;
```

### Inicialización de una declaración de estructuras

Se puede inicializar una estructura de dos formas: dentro de la sección de código de su programa o se puede inicializar como parte de la definición. Cuando se inicializa como parte de la definición se especifican valores iniciales entre llaves, después de la definición de variables estructura. El formato general en este caso es:

```c
struct <tipo> <nombre variable estructura> = 
{ 
	valor miembro1,
	valor miembro2, 
	...
	valor miembron 
};
```

Ejemplos:

```c
struct info_libro
   {
      char titulo[60];
      char auto[30];
      char editorial[30];
      int anyo;
   } libro1 = {"Maravilla del saber ","Lucas Garcia", "McGraw-Hill", 1999};
```

```c
struct coleccion_CD
   {
      char titulo[30];
      char artista[25];
      int num_canciones;
      float precio;
      char fecha_compra[8];
   } cd1 = {
              "El humo nubla tus ojos",
              "Col Porter",
              15,
              2545,
"02/6/99" };
```

```c
struct corredor v1 = {
      "Salvador Rapido",
      29,
      'V',
      "Senior",
      "Independiente",
      0.0
};
```

### Tamaño de la estructura

El operador `sizeof` se aplica sobre un tipo de datos o bien sobre una variable. Se puede aplicar para determinar el tamaño que ocupa en memoria una estructura. 

```c
#include <stdio.h>

struct persona
{
  char nombre[30];
  int edad;
  float altura;
  float peso;
};

void main()
{
  struct persona mar;
  printf("Sizeof(persona): %d \n",sizeof(mar));
}
```

El resultado se obtiene de acuerdo con el número de bytes que cada una de los miembros que se agrupan en la estructura:

## Acceso a estructuras

El acceso a una estructura tiene la finalidad de almacenar o recuperar información. Se puede acceder a los miembro de una estructura de dos formas:

1. Utilizando el operador `.`
2. Utiliznado el operador `->`

### Almacenamiento de información en una estructura

Se puede almacenar información mediante la inicialización, asignación directa o lectura del teclado.

Sintaxis

```c
<variable_struct_name>.<member_name> = data;
```

Ejemplos:

```c
strcpy(cd1.titulo,"OK Computer");
cd1.precio = 345.75;
cd1.num_canciones = 14;
```

El operador punto proporciona el camino directo al miembro correspondiente. Los datos se almacenan en un miembro dado debe ser del mismo tipo declarado para ese miembro. Ejemplo:

```c
struct corredor cr;

printf("Nombre: ");
gets(cr.nombre);

printf("edad: ");
scanf("%d",&cr.edad);
              
printf("Sexo: ");
scanf("%c",&cr.sexo);

printf("Club: ");
gets(cr.club);

if (cr.edad <= 18)
	strcpy(cr.categoria, "Juvenil");
else if (cr.edad <= 40)
	strcpy(cr.categoria, "Senior");
else
	strcpy(cr.categoria, "Veterano");
```

### Acceso a una estructura mediante el operador apuntador

El operador apuntador `->` sirve para acceder a los datos de una estructura a partir de un apuntador. Para utilizar este operador se debe definir una variable apuntador para apuntar a la estructura. 

```c
struct estudiante
{
	char Nombre[41];
	int Num_Estudiante;
	int Anyo_de_matricula;
	float Nota;
};
```

Se puede definir `ptr_est` como un apuntador a la estructura:

```c
struct estudiante *ptr_est;
struct estudiante mejor;
```

A los miembros de la estructura estudiante se pueden asignar datos como sigue (siempre y cuando la estructura tenga creado un espacio de almacenamiento, por ejemplo, con `malloc()` o bien, tenga la dirección de una variable estructurada);

```c
ptr_est = &mejor; /* ptr_est tiene la dirección(apunta a) mejor */
strcpy(ptr_est -> Nombre, "Pepe alomdra");
ptr_est -> Num_Estudiante = 3425;
ptr_est -> Nota = 8.5;
```

### Lectura de información de una estructura

Se puede acceder a los miembros de una estructura con el operador `.` o `->`. Se puede introducir información desde el teclado o desde un archivo, o asignar valores calculados.

 

```c
struct complejo
{
	float pr;
	float pi;
	float modulo;
};
   
struct complejo z; printf("\nParte real: ");
scanf("%f",&z.pr);
printf("\nParte imaginaria: ");
scanf("%f",&z.pi);
   
/* cáculo del módulo */
z.modulo = sqrt(z.pr*z.pr + z.pi*z.pi);
```

### Recuperación de información de una estructura

Se recupera información de una estructura utilizando el operador de asignación o una sentencia de salida `printf()`, `puts()`, … Para acceder a los miembros se utiliza el operador `.` o `->`. Ejemplos:

```c
float x,y;
struct complejo z;
struct complejo *pz;
pz = &z; x = z.pr; y = z.pi;...
   printf("\nNúmero complejo (%.1f,%.1f), módulo: %.2f",
             pz->pr ,pz->pi, pz->modulo);
```

# `Typedef`

La sentencia typedef permite al programador crear un sinónimo de un tipo de dato definido por el usuario o de un tipo ya existente.

Ejemplo:

```c
typedef double Longitud;

Longitud Distancia (const Punto& p, const Punto& p2)
{
	...
	Longitud longitud = sqrt(r-cua);
	return longitud;
}
```

Otro ejemplo

```c
struct complejo
{
	float x,y; 
};

typedef struct complejo complex;

/* definición de un array de complejos */ 
complex v[12];
```

## Estructuras anidadas

En las estructuras anidadas se pueden contener otras estructuras como miembros. Ejemplo:

```c
struct empleado
{
  char nombre_emp[30];
  char direccion[25];
  char ciudad[20];
  char provincia[20];
  long int cod_postal;
  double salario;
};
struct cliente
{
  char nombre_cliente[30];
  char direccion[25];
  char ciudad[20];
  char provincia[20];
  long int cod_postal;
  double saldo;
};
```

```c
struct info_dir
{
      char direccion[25];
      char ciudad[20];
      char provincia[20];
      long int cod_postal;
};

struct empleado
{
      char nombre_emp[30];
      struct info_dir direccion_emp;
      double salario;
};

struct cliente
{
      char nombre_cliente[30];
      struct info_dir direccion_clien;
      double saldo;
};
```

Ejemplo:

```c
#include <stdio.h>
#include <time.h>
struct fecha
{
    unsigned int mes, dia, anyo;
};
struct tiempo
{
    unsigned int horas, minutos;
};
enum tipo_operacion
{
    deposito,
    retirada,
    aldia,
    estado
};
typedef struct fecha Fecha;
typedef struct tiempo Tiempo;
typedef enum tipo_operacion TipOperacion;
struct registro_operacion
{
    long numero_cuenta;
    float cantidad;
    TipOperacion operacion;
    Fecha f;
    Tiempo t;
};
typedef struct registro_operacion RegistrOperacion;
RegistrOperacion entrada(void);
int main()
{
    RegistrOperacion w;
    w = entrada();
    printf("\n Operación realizada\n\n");
    printf("\t%ld\n", w.numero_cuenta);
    printf("\t%d-%d-%d\n", w.f.dia, w.f.mes, w.f.anyo);
    printf("\t%d:%d\n", w.t.horas, w.t.minutos);
    return 0;
}
RegistrOperacion entrada(void)
{
    int x, y, z;
    RegistrOperacion una;
    printf("\nNúmero de cuenta: ");
    scanf("%ld", &una.numero_cuenta);
    puts("\tTipo de operación");
    puts("Deposito(0)");
    puts("Retirada de fondos(1)");
    puts("Puesta al dia(2)");
    puts("Estado de la cuenta(3)");
    scanf("%d", &una.operacion);
    printf("\nFecha (dia mes año): ");
    scanf("%d %d %d", &una.f.dia, &una.f.mes, &una.f.anyo);
    printf("Hora de la operacion(hora minuto): ");
    scanf("%d %d", &una.t.horas, &una.t.minutos);
    return una;
}
```

## Arreglos de estructuras

Los arreglos de estructuras son idóneos para almacenar un archivo completo de empleados, un archivo de inventarios, o cualquier conjunto de datos que se adapte al formato de estructura. Mientras los arreglos proporcionan un medio para almacenar diversos valores del mismo tipo, los arreglos de estructuras permiten almacenar un conjunto de diversos valores de diferentes tipos, agrupados en estructuras.

Ejemplo, un arreglo de estructuras de libros

```c
struct info_libro libros[100];
```

Para inicializar un elemento, se utiliza una notación de arreglos:

```c
strcpy(libros[0].titulo, "C++ a su alcance");
strcpy(libros[0].autor, "Luis Joyanes");
strcpy(libros[0].editorial, "McGraw-Hill");
libros[0].anyo = 1999;
```

### Arreglos como miembros

Los miembros de las estructuras pueden ser de cualquier tipo y en particular arreglos.

```c
struct nomina
{
	char nombre[30];
	int dependientes;
	char departamento[10];
	float horas_dias[7];
	float salario;
} empleado[100];
```

Otro ejemplo:

```c
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
struct inventario
{
    char titulo[25];
    char fecha_pub[20];
    char autor[30];
    int num;
    int pedido;
    float precio_venta;
};
typedef struct inventario Inventario;
int main()
{
    Inventario libro[100];
    int total = 0;
    char resp, b[21];
    do
    {
        printf("Total libros %d \n", (total + 1));
        printf("¿Cuál es el título?: ");
        gets(libro[total].titulo);
        printf("¿Cuál es la fecha de publicación?: ");
        gets(libro[total].fecha_pub);
        printf("¿Quién es el autor?");
        gets(libro[total].autor);
        printf("¿Cuántos libros existen?: ");
        scanf("%d", &libro[total].num);
        printf("¿Cuántos ejemplares están pedidos?: ");
        scanf("%d%*c", &libro[total].pedido);
        printf("¿Cuál es el precio de venta?: ");
        gets(b);
        libro[total].precio_venta = atof(b); /* conversión a real */
        printf("\n ¿Hay más libros? (S/N)");
        scanf("%c%*c", &resp);
        resp = toupper(resp); /* convierte a mayúsculas */
        if (resp == 'S')
        {
            total++;
            continue;
        }
    } while (resp == 'S');
    return 0;
}
```

## Estructuras como parámetros

C permite pasar estructuras a funciones, por valor o referencia. Si la estructura es grande, el tiempo necesario para copiar un parámetro struct, en el paso por valor, puede ser prohibitivo. En tal caso, se debe considerar el método de pasar la dirección de la estructura.

```c
#include <stdio.h>
/* Define el tipo estructura info_persona */
struct info_persona
{
    char nombre[20];
    char calle[30];
    char ciudad[25];
    char provincia[25];
    char codigopostal[6];
};
/* prototipos de funciones */
void entrad_pna(struct info_persona *pp);
void ver_info(struct info_persona p);
void main(void)
{
    struct info_persona reg_dat;
    /* Pasa por referencia la variable */
    entrad_pna(&reg_dat);
    /* Pasa por valor */
    ver_info(reg_dat);
    printf("\nPulsa cualquier carácter para continuar\n");
    getchar();
}
void entrad_pna(struct info_persona *pp)
{
    puts("\n Entrada de los datos de una persona\n");
    /* Para acceder a los campos se utiliza el selector -> */
    printf("Nombre: ");
    gets(pp->nombre);
    printf("Calle: ");
    gets(pp->calle);
    printf("Ciudad: ");
    gets(pp->ciudad);
    printf("Provincia: ");
    gets(pp->provincia);
    printf("Código postal: ");
    gets(pp->codigopostal);
}
void ver_info(struct info_persona p)
{
    puts("\n\tInformación relativa a la persona");
    puts(p.nombre);
    puts(p.calle);
    puts(p.ciudad);
    puts(p.provincia);
    puts(p.codigopostal);
}
```

[<< día 17](../17_day_search/17_day_search.md) | [Inicio](../README.md) || [Día 18](#día-18) | [día 19 >>](../19_day_files/19_day_files.md)