#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main()
{

    pid_t pid;

    pid = fork();

    if(pid<0) { //error occurred
        fprintf(stderr,"Fork Failed");
        return 1;
    }else if(pid==0){ //chid process
        execlp("/bin/ls","ls",  NULL);
    }else{//parent process
        wait(NULL);
        printf("Child Complete %d",pid);
    }

    return 0;

}