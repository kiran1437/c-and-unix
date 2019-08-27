#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



int main(int argc, char * argv[])
{
	int fd = open("asdfasdf",O_RDONLY);

	if( fd < 0) 
		perror("aSDFASDfaSDFASDfasdf");

	 return 0;
} 
