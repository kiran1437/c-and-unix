 #include <sys/mman.h>
 #include <sys/stat.h>        /* For mode constants */
 #include <fcntl.h>           /* For O_* constants */

#include <stdio.h>
#include <stdlib.h>
 


	int
main(int argc, char **argv)
{
	int 	shm_fd;
	int length = 256;

	shm_fd = shm_open("/myposixshm_sasken", O_CREAT|O_RDWR, S_IRWXU);

	if ( shm_fd == -1 ) 
	{ 
		perror("Error creating Shared memory object\n");
		exit(1);
	} 	       



	ftruncate(shm_fd, length);

	void *ptr = mmap(NULL, length, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);




	close(shm_fd);
	exit(0);
}
