#include <stdio.h>

typedef struct movie dmovie;

struct movie
{
    int id;
    char title[30];
    char director[25];
    float duration;
    char genre[15];
    int year;
};

const int k_max = 100;
int movies_number = 0;

dmovie get_movie();
void show_movie_ptr(dmovie *);
void show_movies(dmovie *, int);
int find_movie(dmovie *, int, int);

int main_menu();

int main()
{
    dmovie my_movies[k_max];
    dmovie new_movie;

    while (1)
    {
        int opt = main_menu();
        int idx, id;
        switch (opt)
        {
        case 1: my_movies[movies_number++] = get_movie(new_movie);
                break;
        case 2: printf("Id a buscar:");
                scanf("%d", &idx);
                id = find_movie(my_movies, movies_number, idx);
                if ( id != -1)
                {
                    show_movie_ptr(&my_movies[id]);
                } else {
                    printf("No existe una película con el id %d\n", idx);
                }
                break;
        case 3: show_movies(my_movies, movies_number);
                break;
        case 4: printf("Id a eliminar:");
                scanf("%d", &idx);
                id = find_movie(my_movies, movies_number, idx);
                if ( id != -1)
                {
                    show_movie_ptr(&my_movies[id]);
                    printf("Desea eliminar la película?");
                    my_movies[id].id = -999;
                } else {
                    printf("No existe una película con el id %d\n", idx);
                } 
                break;
        
        case 5: printf("Id a modificar:");
                scanf("%d", &idx);
                id = find_movie(my_movies, movies_number, idx);
                if ( id != -1)
                {
                    show_movie_ptr(&my_movies[id]);
                    printf("Desea modificar la película?");
                    my_movies[id] = get_movie();
                } else {
                    printf("No existe una película con el id %d\n", idx);
                } 
                break;
        case 6: return 0; 

        default:
            break;
        }
    }
    

    return 0;
}

int main_menu()
{
    int option;
    do
    {
        printf("My Netflix\n");
        printf("1. Agregar películas\n");
        printf("2. Buscar película por id\n");
        printf("3. Mostrar películas\n");
        printf("4. Eliminar película\n");
        printf("5. Modificar película\n");
        printf("6. Salir\n");
        printf("Ingresar una opción: ");
        scanf("%d", &option);/* code */
        fflush(stdin);
    } while ((option < 1) || (option > 6));
    
    return option;
}

dmovie get_movie()
{
    dmovie m;

    printf("Ingresar datos de la película.\n");
    printf("Identificador: ");
    scanf("%d", &m.id);
    fflush(stdin);
    printf("Título: ");
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

    return m;
}

void show_movie_ptr(dmovie *m)
{
    printf("Datos de la película: \n");
    printf("Id: %d\n", m->id);
    printf("Título: %s\n", m->title);
    printf("Director: %s\n", m->director);
    printf("Duración: %.2f\n", m->duration);
    printf("Genéro: %s\n", m->genre);
    printf("Año de lanzamiento: %d\n", m->year); 
}

void show_movies(dmovie *m, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (m[i].id != -999)
        {
            printf("Película # %d\n", i+1);
            show_movie_ptr(&m[i]);
        }  
    }
}

int find_movie(dmovie *m, int size, int id) 
{
    for (int i = 0; i < size; i++)
    {
        if (id == m[i].id)
        {
            return i;
        }
    }
    return -1;
}