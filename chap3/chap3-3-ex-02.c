#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int value = 5;

int main()
{
    int i;

    fork();
    fork();
    fork();
    printf("Hello fork()!\n");

    return 0;
}