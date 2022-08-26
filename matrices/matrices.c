#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE_1D 4
#define SIZE_2D 30

int main()
{
    srand(time(0));

    const int size_1d = 4;
    const int size_2d = 20;

    int g[SIZE_1D] = {0};
    int grades[SIZE_2D][SIZE_1D] = {0};
    
    int cols = 4;
    int rows = 20;

    float grades_2[rows][cols];
    float grades_3[20][4];

    const int m = 3;
    const int n = 4;
    int matriz[m][n] = {{11, 12, 13, 14}, 
                        {21, 22, 23, 24},   
                        {31, 32, 33, 34}};


    int data1 = matriz[1][2];
    int data2 = matriz[m-1][n-1];
    printf("%d", matriz[1][2]);

    matriz[0][0] = 10;


    // el ciclo más externo controla filas
    for (int row = 0; row < rows; row++)
    {
        // el ciclo interno controla las columnas
        for (int col = 0; col < cols; col++)
        {
            grades_2[row][col] = rand() % 101;
        }
        
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%.2f\t", grades_2[i][j]);
        }
        printf("\n");
    }
    
    

    return 0;
}