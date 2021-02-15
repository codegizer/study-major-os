#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/shm.h>

#include <sys/stat.h>
#include <sys/mman.h>

int main()
{
	const int SIZE = 4096;
	const char *name = "OS";
	const char *message0 = "Hello,";
	const char *message1 = "Shared Memory\n";

	int shm_fd;
	char *ptr;

	shm_fd = shm_open(name, O_CREAT | O_RDWR,0666);

	ftruncate(shm_fd, SIZE);

	ptr = (char*) mmap(0,SIZE, PROT_READ | PROT_WRITE, MAP_SHARED,shm_fd,0);

	sprintf(ptr, "%s", message0);
	ptr+= strlen(message0);

	sprintf(ptr, "%s", message1);
	ptr+= strlen(message1);

	return 0;

	//gcc filename.c -lrt
}