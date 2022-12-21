/*
Least Recently Used..
*/
#include<stdio.h>

void lru(int sequence[], int n, int value, int hash[], int frames, int idx)
{
    int distance = 0, max = 0, midx = 0, k = frames;
    int i, j;
    while(k--)
    {  
        j = hash[k];
        for(i = idx; i >= 0; i++)
        {
            distance++;
            if(sequence[i] == j)
            {
                midx = i;
                break; //completed for one element..now 2 more left
            }
        }
        if(distance>max)
        {
            max = distance;
            //not completed yet..because I got bored !
        }
    }
}
int main()
{
    int n;
    printf("Enter the number:\n");
    scanf("%d", &n);
    int sequence[n];
    int i, j = 0;
    printf("Enter the sequence: \n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &sequence[i]);
    }

    int frames, pageFault = 0, hit = 0;
    printf("Enter no. of frames:\n ");
    scanf("%d", &frames);

    int hash[frames];
    for(i = 0; i < n; i++)
    {
        hash[i] = 0;
    }

    for(int i = 0; i < n; i++)
    {
        if(isPresent(sequence[i], hash, frames))
        {
            //then that is a hit....do nothing
            hit++;
        }
        else
        {
            pageFault++;
            lru(sequence, n, sequence[i], hash, frames, i);
        }
    }
    
    return 0;
}