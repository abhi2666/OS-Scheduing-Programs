// Disk scheduling FIFO algorithm
/*
You will be given with the starting address of R/W head
..You just have to find the total movement of R/W head.
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    printf("Enter no. of tracks: \n");
    scanf("%d", &n);
    int tracks[n];
    int i, start;
    for(i = 0; i < n; i++)
    {
        scanf("%d", &tracks[i]);
    }
    printf("Enter the starting address: \n");
    scanf("%d", &start);
    int total_movement = 0;

    for(i = 0; i < n; i++)
    {
        total_movement += abs(tracks[i] - start);
        start = tracks[i];
    }
    printf("Total Track Movement is: %d", total_movement);
    return 0;
}