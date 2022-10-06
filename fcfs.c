// First Come First Serve (Non- PreEmptive Scheduling)
/*
If a process enters execution queue then it will get executed and 
will terminate and then only next process will come..

*/

#include <stdio.h>

void get_data(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}

void waiting_time(int wt[], int bt[], int n)
{
    //waiting time for first process is obviously zero
    wt[0] = 0;
    for(int i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

}

void turnAroundTime(int tat[], int bt[], int wt[], int n)
{
    for(int i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];
    }
}

int main()
{
    int n; // no of processes
    printf("Enter total no. of processes: ");
    scanf("%d", &n);
    printf("\n");
    int at[n], bt[n];
    printf("Enter arrival time : \n");
    get_data(at, n);
    printf("Enter burst time : \n");
    get_data(bt, n);

    // find the waiting time..
    int wt[n], tat[n];
    waiting_time(wt, bt, n);
    turnAroundTime(tat, bt, wt, n);

    printf("WT is :\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", wt[i]);
    }

    printf("\n");
    printf("TAT is : \n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", tat[i]);
    }
    return 0;
}