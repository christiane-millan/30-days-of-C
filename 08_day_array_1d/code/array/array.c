#include <stdio.h>
# define MAX 50

int main()
{
    int c1 = 4, c2= 3, c3= 9;
    const int k_max = 50;
    int day;

    int numbers[100] = {1};
    float average[] = {0.0, 0.0, 0.0, 0.0, 0.0};
    float calificaciones[5] = { 10.0, 9.0, 8.5, 5.0, 9.8 };
    float calificaciones_2[MAX];
    float calificaciones_2[k_max];

    printf("Cuantos días");
    scanf("%d", &day);

    float temperatures[day * 3];

    char message[] = "Hola mundo\0" ;

    calificaciones[2] = 9.5;
    printf("%f\n", calificaciones[3]);
    printf("%f\n", calificaciones[4]);

    printf("%s\n", message);
    message[5] = 'M';
    printf("%s\n", message);
    //message = "Hello world\n";
    // calificaciones = {5.0};
    calificaciones[0] = 5.0;
    calificaciones[1] = 5.0;
    calificaciones[2] = 5.0;
    calificaciones[3] = 5.0;
    calificaciones[4] = 5.0;

    for (int i = 0; i < MAX; i++)
    {
        calificaciones[i] = 5.0
    }
    
    

    return 0;
}