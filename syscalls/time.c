#include <stdio.h>
#include <time.h>


int main(int argc, char * argv[])
{
  
	time_t   t;
	char buff[128];

	time(&t);

	printf("%u\n",t); 

	char * cp = ctime(&t);

	printf("---%s---\n", cp ); 

	strcpy(buff, cp); 

	 return 0;
} 
