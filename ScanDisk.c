/*
You move to the extreme right then to the extreme left and vice versa and 
complete the processes that comes in their path.
BARY EAZY !
*/
#include <stdio.h>
#include <stdlib.h>

int minEle(int tracks[], int n)
{
    int min = 99999;
    for(int i = 0; i < n; i++)
    {
        if(min > tracks[i])
        {
            min = tracks[i];
        }
    }
    return min;
}

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
    int track_range[2] = {0, 199}; // range of tracks
    // if moving to the right first and then to the left
    total_movement += (abs(start - track_range[1]) + abs(track_range[1] - minEle(tracks, n)));
    printf("Total head movement is %d", total_movement);
    return 0;
}