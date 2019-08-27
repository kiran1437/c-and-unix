 #include <fcntl.h>           /* For O_* constants */
 #include <sys/stat.h>        /* For mode constants */
 #include <semaphore.h>

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
 


	int
main(int argc, char **argv)
{

	 int ret; 


	ret = sem_unlink("/myposixsemaphore");

	if ( ret == -1) 
	{ 
		perror("Error deleting semaphore  object\n");
		exit(1);
	} 	       








	exit(0);
}
