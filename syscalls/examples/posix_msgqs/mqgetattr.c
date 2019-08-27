
 #include <fcntl.h>           /* For O_* constants */
 #include <sys/stat.h>        /* For mode constants */
 #include <mqueue.h>

 #include <stdio.h>
 #include <stdlib.h>


int
main(int argc, char **argv)
{
	mqd_t	mqd;
	struct mq_attr	attr;


	mqd = mq_open("/mysaskenposixque", O_CREAT|O_RDWR);

	//mqd = mq_open("/myposixque", O_CREAT|O_RDWR, S_IRWXU,NULL);

	if ( mqd == -1 )
	{       
		        printf("Error creating Q\n");
			       exit(1);
	}


	mq_getattr(mqd, &attr);
	printf("max #msgs = %ld, max #bytes/msg = %ld, "
		   "#currently on queue = %ld\n",
		   attr.mq_maxmsg, attr.mq_msgsize, attr.mq_curmsgs);

	mq_close(mqd);
	exit(0);
}
