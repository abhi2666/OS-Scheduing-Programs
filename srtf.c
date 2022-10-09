#include <stdio.h>

void findTimes(int at[], int bt[], int wt[], int tat[], int n)
{
    int rem_bt[n];
    for (int i = 0; i < n; i++)
    {
        rem_bt[i] = bt[i];
    }
    int remaining = 0, time, smallest = 0, CT = 0; // obviously !!

    for(time = 0; remaining != n; time++)
    {
        // time will increase and we will check process 
        // with shortest burst time each time.

        for(int i = 0; i < n; i++)
        {
            // check if any process is ready to be executed
            // also check if its bt is not zero
            if(at[i] <= time && rem_bt[i])
            {
                // find the shortest process
                smallest = i; // store its index
            }
        }
        rem_bt[smallest]--;
        // if process is already fully executed then
        // calcuate its waiting time and TAT
        if(rem_bt[smallest] == 0)
        {
            remaining++; // one process is completed
            CT = time + 1; // completion time
            printf("For Process %d\n", smallest+1);
            printf("Waiting Time is : %d\n", CT - at[smallest] - bt[smallest]);
            printf("Turn Around Time : %d\n", CT - at[smallest]);
        }
    }
    
}

int main()
{
    int n;
    printf("Enter no. of processes : \n");
    scanf("%d", &n);
    int at[n], bt[n], wt[n], tat[n];

    printf("Enter Arrival Time: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &at[i]);
    }

    printf("Enter Burst Time: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }

    findTimes(at, bt, wt, tat, n);
    
    

    return 0;
}