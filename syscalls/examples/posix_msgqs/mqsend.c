
  #include <fcntl.h>           /* For O_* constants */
  #include <sys/stat.h>        /* For mode constants */
  #include <mqueue.h>
 
 #include <stdio.h>
 #include <stdlib.h>
#include <assert.h> 

int
main(int argc, char **argv)
{
	mqd_t	mqd;
	void	*ptr;
	int len = 100; 

	mqd = mq_open("/mysaskenposixque", O_CREAT|O_RDWR);
	if ( mqd == -1 )
	{
		printf("Error creating Q\n");
		exit(1);
	}

	ptr = calloc(len, sizeof(char));
	assert(ptr);


	int ret = mq_send(mqd, ptr, len, 10);

	if ( ret == -1) 

	{
		printf("Error sending  Q\n");
		exit(1);
	}



	exit(0);
}
