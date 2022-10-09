#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void oddEvenSum(int a[], int n)
{
    int p = fork();
    int evenSum = 0, oddSum = 0;
    if(p == 0)
    {
        // for child process sum the even 
        for(int i = 0; i < n; i++)
        {
            if(a[i] % 2 == 0)
            {
                evenSum += a[i];
            }
        }

    }
    else if(p == 1)
    {
        // for parent process find oddSum
        for(int i = 0; i < n; i++)
        {
            if(a[i] % 2 != 0)
            {
                oddSum += a[i];
            }
        }
    }

    printf("Even sum is : %d\n", evenSum);
    printf("Odd sum is : %d\n", oddSum);
}

int main()
{
    int a[5] = {1, 2, 3, 4, 5};

    oddEvenSum(a, 5);
    return 0;
}