#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char * argv[])
{
  int i=123456789;

  int fd = open ("text_int_data", O_RDWR | O_CREAT|O_TRUNC, S_IRWXU);

  if (fd < 0)
    {
      perror ("OPEN faied\n");
      exit (1);
    }

  char buf[100];
  sprintf(buf, "%d", i);
  if( write(fd, buf, strlen(buf)) != strlen(buf))
       perror("Error writing\n");
  close (fd);
}
