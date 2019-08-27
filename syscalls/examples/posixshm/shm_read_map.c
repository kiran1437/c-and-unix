 #include <sys/mman.h>
 #include <sys/stat.h>        /* For mode constants */
 #include <fcntl.h>           /* For O_* constants */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 


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




	void *ptr = mmap(NULL, length, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);


	printf ("----%s-----\n",ptr);



	close(shm_fd);
	exit(0);
}
