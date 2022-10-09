/*
SJF --  Shortest Job First
Criteria -- Burst Time

The process with the least burst time will execute first
and so on.
*/
#include <stdio.h>

void swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

void sort(int bt[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (bt[j] > bt[j + 1])
            {
                swap(&bt[j], &bt[j + 1]);
            }
        }
    }
}

void WTandTAT(int bt[], int wt[], int tat[], int n)
{
    wt[0] = 0;
    for(int i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
    }
    for(int i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];
    }
}
int main()
{
    int n;
    printf("Enter no. of processes : \n");
    scanf("%d", &n);
    int bt[n], wt[n], tat[n];

    printf("Enter Burst Time : \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }
    // sort the processes on the basis of bt
    sort(bt, n);
    WTandTAT(bt, wt, tat, n);

    printf("Waiting time :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", wt[i]);
    }
    printf("\n");
    printf("turn around time :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", tat[i]);
    }
    printf("\n");

    return 0;
}