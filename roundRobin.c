/*
RR (Round Robin) -- Pre Emptive Scheduling algorithm
Pre-requisite -- understanding of Round Robin on Notebook

Steps --> Find waiting time then Jhinga Lala

Criteria -- Time Quantum (This is the time given for which the process
will execute each time until its fully executed and terminated)
*/
#include <stdio.h>
void waitingTime(int n, int bt[], int wt[], int timeQuant)
{
    int t = 0; // represents the time for which a certain
    // process has already been executed
    int rem_bt[n]; // just a copy of rem_bt because we can't lose
    // original bt array
    for (int i = 0; i < n; i++)
    {
        rem_bt[i] = bt[i];
    }

    int done;
    while (1)
    {
        done = 1;
        // we will traverse all the processes and will execute
        // for the given time quanta..
        for (int i = 0; i < n; i++)
        {
            if (rem_bt[i] > 0) // checking if process is executed or not yet
            {
                done = 0; // means it is a pending process

                // for each process check if its less or more than
                // timeQuant
                if (rem_bt[i] > timeQuant)
                {

                    t += timeQuant;
                    rem_bt[i] -= timeQuant;
                }
                else
                {
                    // remaining burst time is less than timeQuant
                    // means the process is going to get fucked up

                    t += rem_bt[i];
                    // waiting time will be total time process took
                    // minus its burst time
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if (done == 1)
        {
            break;
        }
    }
}

void turnAroundTime(int n, int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];
    }
}

int main()
{
    int n;
    printf("Enter no. of processes : \n");
    scanf("%d", &n);
    int bt[n], wt[n], tat[n], timeQuant;

    printf("Enter Burst Time : \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }

    printf("Enter time quantum : \n");
    scanf("%d", &timeQuant);
    waitingTime(n, bt, wt, timeQuant);
    turnAroundTime(n, bt, wt, tat);

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