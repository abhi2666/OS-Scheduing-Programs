#include <stdio.h>

void print_data(int mat[][3], int rows, int column)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n, m, i, j, k;
    n = 5;                             // Number of processes
    m = 3;                             // Number of resources
    int allocated[5][3] = {{0, 1, 0},  // P0 // Allocation Matrix
                           {2, 0, 0},  // P1
                           {3, 0, 2},  // P2
                           {2, 1, 1},  // P3
                           {0, 0, 2}}; // P4

    int max_need[5][3] = {{7, 5, 3},  // P0 // MAX Matrix
                          {3, 2, 2},  // P1
                          {9, 0, 2},  // P2
                          {2, 2, 2},  // P3
                          {4, 3, 3}}; // P4

    int available[3] = {3, 3, 2}; // Available Resources

    int remaining[5][3];
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 3; j++)
        {
            remaining[i][j] = max_need[i][j] - allocated[i][j];
        }
    }
    // print_data(remaining, 5, 3);
    // compare the available with the remaining..if remaining is more than avail then leave it
    // else complete that process
    int finish[5]; // store which process is finished
    for (i = 0; i < 5; i++)
    {
        finish[i] = 0;
    }
    int flag = 0;
    // for each row
    for (i = 0; i < 5; i++)
    {
        flag = 0;
        // for each column of a row check if its less or more than available
        if (finish[i] == 0)
        {
            for (j = 0; j < 3; j++)
            {
                if (available[j] < remaining[i][j])
                {
                    // you can't complete the process
                    flag = 1; // means can't complete this process
                    break;
                }
            }
        }

        if (flag == 0)
        {
            // means you can do the current process
            finish[i] = 1; // process at ith index is finished
            printf("p[%d]->", i);

            for(j = 0; j < 3; j++)
            {
                available[j] += allocated[i][j];
            }
        }
    }
    //now print all the processes which ain't printed
    for(i = 0; i < 5; i++)
    {
        if(finish[i] != 1)
        {
            printf("p[%d]->", i);
        }
        
    }
    return 0;
}