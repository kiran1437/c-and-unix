 #include <fcntl.h>           /* For O_* constants */
 #include <sys/stat.h>        /* For mode constants */
 #include <mqueue.h>

#include <stdio.h>
#include <stdlib.h>
 

struct mq_attr	attr;	/* mq_maxmsg and mq_msgsize both init to 0 */

int
main(int argc, char **argv)
{
	mqd_t	mqd;

	mqd = mq_open("/mysaskenposixque", O_CREAT|O_RDWR, S_IRWXU,NULL);

	if ( mqd == -1 ) 
	{ 
		printf("Error creating Q\n");
	       exit(1);
	} 	       

	mq_close(mqd);
	exit(0);
}
