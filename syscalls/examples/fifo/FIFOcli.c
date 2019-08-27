#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include<errno.h>

extern int errno;
int
main ()
{


  char buf[4096];

  int n, fd = open ("fifo1", O_WRONLY);
  printf ("FIFOcli:open returned %d\n", fd);

  n = write (fd, "hello world", 12);

  printf ("FIFOcli:write to FIFO %d \n", n);

  sleep (20);
}
