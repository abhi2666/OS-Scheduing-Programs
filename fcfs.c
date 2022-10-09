#include <stdio.h>

void WTandTAT(int at[], int bt[], int wt[], int tat[], int n)
{
   int temp[n];
   wt[0] = tat[0] = temp[0] = 0;

   for(int i = 0; i < n; i++)
   {
      temp[i + 1] = temp[i] + bt[i];
      wt[i] = temp[i] - at[i];
      tat[i] = wt[i] + bt[i];
   }
}
int main()
{
   int n;
   printf("Enter no. of processes : \n");
   scanf("%d", &n);
   int bt[n], wt[n], at[n], tat[n];

   printf("Enter Arrival Time : \n");
   for (int i = 0; i < n; i++)
   {
      scanf("%d", &at[i]);
   }

   printf("Enter Burst Time : \n");
   for (int i = 0; i < n; i++)
   {
      scanf("%d", &bt[i]);
   }

   WTandTAT(at, bt, wt, tat, n);

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