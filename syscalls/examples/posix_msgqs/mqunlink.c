#include <mqueue.h> 
#include <stdio.h>
 #include <stdlib.h> 
int
main(int argc, char **argv)
{
	if (argc != 2)
		printf("usage: mqunlink <name>");

	mq_unlink(argv[1]);

	exit(0);
}
