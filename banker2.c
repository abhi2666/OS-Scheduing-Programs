/*
Banker's Algo 
You need --> no. of processes, memory allocated to them, max memory they need 
and available memory you have.
*/

#include <stdio.h>

void get_data(int arr[][50], int n, int m)
{
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    return;
}

void set_zero(int f[], int n)
{
    for(int i = 0; i < n; i++)
    {
        f[i] = 0;
    }
    return;
}

void set_data(int r[][50], int a[][50], int m[][50], int rows, int column)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < column; j++)
        {
            r[i][j] = m[i][j] - a[i][j];
        }
    }
}

void print_data(int a[][50], int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    //you need allocated memory, max memory(for every process) and available memory
    int n;
    printf("Enter no. of processes: ");
    scanf("%d", &n);
    printf("\nEnter rows and column: ");
    int rows, column;
    scanf("%d %d", &rows, &column);
    int allocated[rows][column];
    int max_need[rows][column];
    printf("\nEnter memory alloted for each process: ");
    get_data(allocated, rows, column);
    printf("\nEnter max memory for each process: ");
    get_data(allocated, rows, column);
    int available[rows];
    printf("\nEnter the available resource: ");
    for(int i = 0; i < rows; i++)
    {
        scanf("%d", &available[i]);
    }
      
    //................Banker's Algo.................//

    int remaining[rows][column];
    printf("\nCreating remaining need....");
    set_data(remaining, allocated, max_need, rows, column);
    printf("\nRemaining Needs are: ");
    print_data(remaining, rows, column);

    return 0;
}