#include <stdio.h>
#include <unistd.h>
int main()
{
    printf("process id: %d\n", getpid());
    fork();
    printf("Process id after fork: %d\n", getpid());
    return 0;
}