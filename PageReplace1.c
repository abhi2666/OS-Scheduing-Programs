// FIFO page replacement algo
// you have to find page fault

#include <stdio.h>

void set_zero(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = 0;
    }
    
}

int sequenceIn(int val, int hash[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(hash[i] == val) return 1;
    }
    return 0;
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

    int frames;
    printf("Enter no. of frames:\n ");
    scanf("%d", &frames);

    //..............MAIN LOGIC...............//
    int hash[frames];
    int pageFault = 0;
    int hit = 0;
    set_zero(hash, frames);

    for(int i = 0; i < n; i++)
    {
        if(sequenceIn(sequence[i], hash, frames))
        {
            //means sequence is present
            hit++;
        }
        else
        {
            // if sequence not in hash table
            //put it in hash table
            pageFault++;
            hash[j%frames] = sequence[i];
            j++;
        }
    }

    printf("Page Fault is: %d", pageFault);

    return 0;
}