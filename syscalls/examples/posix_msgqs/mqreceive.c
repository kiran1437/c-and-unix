
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
	ssize_t	n;
	unsigned int 	prio;
	void	*buff;
	struct mq_attr	attr;

	mqd = mq_open("/mysaskenposixque", O_CREAT|O_RDWR);
	if ( mqd == -1 )
	{
		printf("Error creating Q\n");
		exit(1);
	}



	mq_getattr(mqd, &attr);
	printf("max #msgs = %ld, max #bytes/msg = %ld, "
			"#currently on queue = %ld\n",
			attr.mq_maxmsg, attr.mq_msgsize, attr.mq_curmsgs);

	buff = malloc(attr.mq_msgsize);

	n = mq_receive(mqd, buff, attr.mq_msgsize, &prio);

	printf("read %ld bytes, priority = %u\n", (long) n, prio);

	exit(0);
}
