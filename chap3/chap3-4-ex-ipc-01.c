#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1


int main()
{
	char msg_to_parent[] = "To Parent";
	char msg_to_child[] = "To Parent";
	char buf[BUFFER_SIZE];
	int fd[2];
	pid_t pid;

	pipe(fd);

	pid = fork();

	if(pid>0)
	{
		write(fd[WRITE_END],"To Parent",sizeof(msg_to_parent));	
		
//		sleep(2);
		wait(NULL);
		read(fd[READ_END],buf,BUFFER_SIZE);
		printf("read %s\n",buf);

	}else if (pid==0) {
		
		read(fd[READ_END],buf,BUFFER_SIZE);
		printf("read %s\n",buf);

		write(fd[WRITE_END],"To Child",sizeof(msg_to_child));	
//		sleep(5);
	}

	return 0;
}