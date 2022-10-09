
#include <stdio.h>

int main()
{
	int n;
	printf("Enter no. of processes : \n");
	scanf("%d", &n);
	int bt[n], rem_bt[n], wt[n], at[n], tat[n];

	printf("Enter Arrival Time : \n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &at[i]);
	}

	printf("Enter Burst Time : \n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &bt[i]);
		rem_bt[i] = bt[i];
	}

	int completed = 0, time = 0, smallest, CT = 0;

	for (time = 0; completed != n; time++)
	{
		for (int i = 0; i < n; i++)
		{
			if (at[i] <= time && rem_bt[i])
			{
				smallest = i;
			}
			rem_bt[smallest]--;
			if (rem_bt[smallest] == 0)
			{
				// means process is fully executed
				completed++;
				CT = time + 1;
			}
		}
	}

	return 0;
}