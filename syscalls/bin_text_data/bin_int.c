
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char * argv[])
{
  int i = 0x44362654;

  int fd = open ("bin_int_data", O_RDWR | O_CREAT|O_TRUNC, S_IRWXU);

  if (fd < 0)
    {
      perror ("OPEN faied\n");
      exit (1);
    }

  if (write (fd, &i, sizeof (int) ) != sizeof (int)) 
    perror (" Some thing wrong with write\n");


  close (fd);
}
