#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef float longitude;
typedef struct movie dmovie;

struct movie
{
    char title[30];
    char director[25];
    float duration;
    char genre[15];
    int year;
} movie_1 = {"Lord of the rings I",
             "Peter Jackson", 
             3.1,
             "Fantasy", 
             2001 }, 
  movie_2, movie_3;

struct movie movie_4 = {"Spiderman I",
                        "Sam Raymi",
                        0.96,
                        "Comics",
                        2002
                        };

struct movie movie_5;

struct movie *p_movie_5 = &movie_5;

int *p_int;

dmovie movie_7;
dmovie *P_movie_7;

void show_movie(dmovie);
void show_movie_ptr(dmovie *);
void get_movie(dmovie);
void get_movie_ptr(dmovie *);

int main()
{
    int y = 0;
    int z;
    const int k_max = 100;
    z = 0;
    int n[10];
    int m[3] = {1, 2, 3};

    longitude size;

    struct movie *p_movie_6 = (struct movie *) malloc(sizeof(struct movie));

    //struct movie my_movies[100];
    dmovie my_movies[k_max];

    dmovie *my_multimedia = (dmovie *) malloc (100 * sizeof(dmovie));   


    printf("El tamaño: %lu\n", sizeof(movie_1));
    printf("El tamaño: %lu\n", sizeof(struct movie));

    printf("Datos de la película: \n");
    printf("Título: %s\n", movie_1.title);
    printf("Director: %s\n", movie_1.director);
    printf("Duración: %.2f\n", movie_1.duration);
    printf("Genéro: %s\n", movie_1.genre);
    printf("Año de lanzamiento: %d\n", movie_1.year);


    //movie_2.title = "DJango";
    strcpy(movie_2.title, "DJango");
    strcpy(movie_2.director, "Tarantino");
    movie_2.duration = 3.75;
    strcpy(movie_2.genre, "Action");
    movie_2.year = 2012;

    

    strcpy(p_movie_5->title, "Star Wars Episode IV");
    strcpy(p_movie_5->director, "George Lucas");
    p_movie_5->duration = 2.01;
    strcpy(p_movie_5->genre, "Action");
    p_movie_5->year = 1977;

    printf("Datos de la película: \n");
    printf("Título: %s\n", p_movie_5->title);
    printf("Director: %s\n", p_movie_5->director);
    printf("Duración: %.2f\n", p_movie_5->duration);
    printf("Genéro: %s\n", p_movie_5->genre);
    printf("Año de lanzamiento: %d\n", p_movie_5->year);


    return 0;
}

void show_movie(dmovie m)
{
    printf("Datos de la película: \n");
    printf("Título: %s\n", m.title);
    printf("Director: %s\n", m.director);
    printf("Duración: %.2f\n", m.duration);
    printf("Genéro: %s\n", m.genre);
    printf("Año de lanzamiento: %d\n", m.year); 
}

void show_movie_ptr(dmovie *m)
{
    printf("Datos de la película: \n");
    printf("Título: %s\n", m->title);
    printf("Director: %s\n", m->director);
    printf("Duración: %.2f\n", m->duration);
    printf("Genéro: %s\n", m->genre);
    printf("Año de lanzamiento: %d\n", m->year); 
}

void get_movie(dmovie m)
{
    printf("Ingresar datos de la película.\n");
    printf("Título de la película: ");
    gets(m.title);
    printf("Director: ");
    gets(m.director);
    printf("Duración: ");
    scanf("%f", &m.duration);
    fflush(stdin);
    printf("Genéro: ");
    gets(m.genre);
    printf("Año de lanzamiento: ");
    scanf("%d", &m.year);
}

void get_movie_ptr(dmovie *)
{
    printf("Ingresar datos de la película.\n");
    printf("Título de la película: ");
    gets(m->title);
    printf("Director: ");
    gets(m->director);
    printf("Duración: ");
    scanf("%f", &m->duration);
    fflush(stdin);
    printf("Genéro: ");
    gets(m->genre);
    printf("Año de lanzamiento: ");
    scanf("%d", &m->year);
}