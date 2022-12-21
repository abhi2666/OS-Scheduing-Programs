#include<stdio.h>

void waitingTime(int n, int bt[], int wt[], int timeQuant)
{
    int rem_bt[n];
    for(int i = 0; i < n; i++)
    {
        rem_bt[i] = bt[i];
    }
    int ct = 0; //completion time

    int done;
    while(1)
    {
        done = 1;
        //run until all the processes are executed
        for(int i = 0; i < n; i++)
        {
            if(rem_bt[i] > 0)
            {
                //means there are processes to execute
                done = 0;
                if(rem_bt[i] > timeQuant)
                {
                    //run the process for given time quant
                    rem_bt[i] -= timeQuant;
                    ct+= timeQuant;
                }
                else
                {
                    //process wants less time than the timeQuant 
                    ct += rem_bt[i];
                    wt[i] = ct - bt[i];
                    rem_bt[i] = 0;
                }
            }

        }
        if(done == 1) 
        {
            break;
        }
    }

}

void getTAT(int wt[], int bt[], int tat[], int n)
{
    for(int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
    }
}

void print_data(int wt[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", wt[i]);
    }
}

int main() 
{ 
    int n = 3; 
    // Burst time of all processes 
    int bt[] = {10, 5, 8}; 
    int tat[n];
    int wt[n];
    for(int i = 0; i < n; i++)
    {
        wt[i] = 0;
    }
    int quant = 2; 
    waitingTime(n, bt, wt, quant);
    getTAT(wt, bt, tat, n);
    print_data(wt, n);
    return 0; 
} 