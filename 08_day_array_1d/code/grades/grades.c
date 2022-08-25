#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_grades(float[], int);
void get_grades(float[], int);
float max_grade(float [], int);

int main()
{
    const int max_students = 50;
    int number = 0;
    float grades[max_students];
    float grades_copy[max_students];

    srand(time(NULL));
    //Inicializar
    // for (int i = 0; i < max_students; i++)
    // {
    //     //numero = rand () % (N-M+1) + M;
    //     grades[i] = rand() % 11;
    // }

    // for (int i = 0; i < max_students; i++)
    // {
    //     grades_copy[i] = grades[i];
    // }


    while ((number <= 0) || (number > 50))
    {
        printf("El número de alumnos:");
        scanf("%d", &number);
    }


    // printf("Calificaciones iniciales:\n");
    // print_grades(grades, number);

    printf("Captura de las calificaciones:\n");
    get_grades(grades, number);
    
    printf("Calificaciones capturadas:\n");
    print_grades(grades, number);
    
    printf("Calificación maxima: %f\n", max_grade(grades, number));

    return 0;
}

void print_grades(float g[], int size)
{
    for (int i = 0; i < size; i++)
    {
       printf("Numero lista %d - calificación: %.1f\n", i + 1, g[i]); 
    }
    
}

void get_grades(float g[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Ingresa la calificación %d:", i + 1);
        scanf("%f", &g[i]);
    }
}

float max_grade(float g[], int size)
{
    float m = g[0];
    for (int i = 0; i < size; i++)
    {
        if ( m < g[i])
        {
            m = g[i];
        }   
    }
    return m;
}