#include <stdlib.h> 
#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main()
{

    pid_t pid;

    pid = fork();

    if(pid>0)
    {
        printf("parent process %d\n",getpid());
    }else if(pid==0) {
        printf("chid process %d\n",getpid());
        pid = fork();
        if(pid>0){
            printf("child process %d\n",getpid());
        }else{
            printf("grand child %d\n",getpid());
        }
    }else {
        printf ("error\n");
    }

    system("ps | grep a.out");

    return 0;
}