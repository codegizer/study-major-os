#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

//참고:: https://www.tutorialspoint.com/inter_process_communication/inter_process_communication_pipes.htm

int main()
{
	char msg_to_parent[BUFFER_SIZE] = "Hi";
	char msg_to_child[BUFFER_SIZE] = "Hello";

	char read_buf1[BUFFER_SIZE];
	char read_buf2[BUFFER_SIZE];

	int fd1[2];
	int fd2[2];
	pid_t pid;

	pipe(fd1);
	pipe(fd2);

	pid = fork();

	if(pid>0)
	{
		close(fd1[READ_END]);
		close(fd2[WRITE_END]);
		printf("In Parent: Writing to pipe 1 – Message is %s\n", msg_to_parent);

		write(fd1[WRITE_END],msg_to_parent,sizeof(msg_to_parent));			
		
		read(fd2[READ_END],read_buf1,sizeof(read_buf1));
		printf("In Parent: Reading from pipe 2 – Message is %s %p \n", read_buf1, &read_buf1);

	}else if (pid==0) {
		
		close(fd1[WRITE_END]);
		close(fd2[READ_END]);

		read(fd1[READ_END],read_buf2,sizeof(read_buf2));		
		printf("In Child: Reading from pipe 1 – Message is %s %p \n", read_buf2, &read_buf2);
		printf("In Child: Writing to pipe 1 – Message is %s\n", msg_to_child);
		write(fd2[WRITE_END],msg_to_child,sizeof(msg_to_child));			
	}

	return 0;
}