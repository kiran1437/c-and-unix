#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include<errno.h>

extern int errno;
int
main ()
{


  char buf[4096];

  int fd, n = mkfifo ("fifo1", S_IRWXU);

/* The second arg specifies only permissions. No EXCL or CREAT is required
   as mkfifo by default creates. And there is no harm in calling mkfifo
   for an existing fifo.
*/

  printf ("mkfio returned %d errno = %d\n", n, errno);

  if (fd = open ("fifo1", O_RDONLY) < 0)
    {
      printf ("FIFOserv:open returned %d, errno=%d\n", fd, errno);
      exit (1);
    }
  printf ("FIFOserv:open returned %d\n", fd);

/* Since, FIFOs have an entry in a file system, all security permissions of 
   files are effective for FIFOs.
*/

  while (n = read (fd, buf, 4096) > 0)
    printf ("FIFOserv:read from FIFO %d -%s-\n", n, buf);

  printf ("FIFOserv:read from FIFO %d errno = %d\n", n, errno);
}
