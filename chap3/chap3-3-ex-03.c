#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int value = 5;

int main()
{
    int i;
    pid_t pid;

    for(i=0;i<4;i++)
    {
        pid = fork();
    }

    printf ("Hello, Fork %d\n", pid);

    

    return 0;
}