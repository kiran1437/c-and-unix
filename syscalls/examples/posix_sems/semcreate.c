 #include <fcntl.h>           /* For O_* constants */
 #include <sys/stat.h>        /* For mode constants */
 #include <semaphore.h>

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
 


	int
main(int argc, char **argv)
{

	 sem_t   *sem;


	sem = sem_open("/myposixsemaphore", O_CREAT|O_RDWR, S_IRWXU, 2);

	if ( sem == SEM_FAILED ) 
	{ 
		perror("Error creating semaphore  object\n");
		exit(1);
	} 	       








	exit(0);
}