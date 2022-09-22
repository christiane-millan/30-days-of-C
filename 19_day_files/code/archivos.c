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
void show_movies_from_file();
int find_movie(dmovie *, int, int);
dmovie find_movie_from_file(int id);
void init_file();
void save_movie_to_file(dmovie *);
void del_movie_to_file(int);

int main_menu();

int main()
{
    init_file();
    

    dmovie my_movies[k_max];
    dmovie new_movie;

    while (1)
    {
        int opt = main_menu();
        int idx, id;
        dmovie new_movie;
        switch (opt)
        {
        case 1: new_movie = get_movie();
                save_movie_to_file(&new_movie);
                break;
        case 2: printf("Id a buscar:");
                scanf("%d", &idx);
                new_movie = find_movie_from_file(idx);
                if(new_movie.id != -1)
                {
                    show_movie_ptr(&new_movie);
                } else {
                    printf("No existe una película con el id %d\n", idx);
                }
                break;
        case 3:
                show_movies_from_file();
                break;
        case 4: printf("Id a eliminar:");
                scanf("%d", &idx);
                //id = find_movie(my_movies, movies_number, idx);
                new_movie = find_movie_from_file(idx);
                if ( new_movie.id != -1)
                {
                    show_movie_ptr(&new_movie);
                    printf("Desea eliminar la película?\n");
                    del_movie_to_file(idx);
                } else {
                    printf("No existe una película con el id %d\n", idx);
                } 
                break;
        
        case 5: printf("Id a modificar:");
                scanf("%d", &idx);
                // id = find_movie(my_movies, movies_number, idx);
                // if ( id != -1)
                // {
                //     show_movie_ptr(&my_movies[id]);
                //     printf("Desea modificar la película?");
                //     my_movies[id] = get_movie();
                // } else {
                //     printf("No existe una película con el id %d\n", idx);
                // } 
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

void show_movies_from_file()
{
    FILE *pf;
    pf = fopen("movies.bin", "rb");
    if (pf == NULL)
    {
        printf("Error al abrir el archivo");
    } else
    {
        int i = 0;
        while (!feof(pf))
        {
            dmovie movie = {-1, " ", " ", 0.0, " ", 0};
            int r = fread(&movie, sizeof(dmovie), 1, pf);
            if ( r != 0 && movie.id != -1)
            {
                printf("\n\nPelícula # %d\n", i + 1);
                //printf("A: %d", movie.id);
                show_movie_ptr(&movie);  
                i++;
            } 
        }
        fclose(pf);
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

dmovie find_movie_from_file(int id)
{
    FILE *pf;
    dmovie movie = {-1, " ", " ", 0.0, " ", 0};

    pf = fopen("movies.bin", "rb");
    if (pf == NULL)
    {
        printf("Error al abrir el archivo");
    } else
    {
        int i = 0;
        while (!feof(pf))
        {            
            int r = fread(&movie, sizeof(dmovie), 1, pf);
            if ( r != 0 && movie.id == id)
            {
                fclose(pf);
                return movie;
            } 
        }
    }
    return movie;
}

void init_file()
{
    FILE *pf;
    pf = fopen("movies.bin", "wb");
    if (pf == NULL)
    {
        printf("No se pudo crear el archivo...\n");
    } else {
        dmovie m = {-1, "", "", 0.0, "", 0};
        for (int i = 0; i < k_max; i++)
        {
            fwrite(&m, sizeof(dmovie),1, pf);
        }
        fclose(pf);
    }
}

void save_movie_to_file(dmovie *movie)
{
    FILE *pf;

    pf = fopen("movies.bin", "r+b");
    if (pf == NULL)
    {
        printf("No se pudo abrir el archivo");
    } else {
        fseek(pf, (movie->id - 1) * sizeof(dmovie), SEEK_SET);
        fwrite(movie, sizeof(dmovie), 1, pf);
    }
    fclose(pf);
}

void del_movie_to_file(int id)
{
    FILE *pf;
    dmovie m = {-1, " ", " ", 0.0, " ", 0};
    pf = fopen("movies.bin", "r+b");
    if (pf == NULL)
    {
        printf("No se pudo abrir el archivo");
    } else {
        fseek(pf, (id - 1) * sizeof(dmovie), SEEK_SET);
        fwrite(&m, sizeof(dmovie), 1, pf);
    }
    fclose(pf);
}