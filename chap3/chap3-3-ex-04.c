#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int value = 5;

int main()
{
 
    fork();
    value += 5;

    fork();
    value += 5;

    fork();
    value += 5;    

    printf ("Hello, Fork() %d\n", value);

    return 0;
}