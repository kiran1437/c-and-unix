#include<sys/types.h>
#include<unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



main ()
{

  int fd1[2], fd2[2];
  pid_t pid;
  char buf[4096];
  char buf3[4096];
  char pathname[128], buf2[128];
  int i, n, fd;

  if (pipe (fd1))
    perror ("fd1 pipe failed\n");
  if (pipe (fd2))
    perror ("fd2 pipe failed\n");


  if ((pid = fork ()) < 0)
    perror ("FOrek failed\n");

  if (pid > 0)
    {
      close (fd1[1]);
      close (fd2[0]);
      n = read (fd1[0], pathname, 128);
      pathname[n] = 0;
      printf ("-%s-", pathname);
      if ((fd = open (pathname, O_RDONLY)) < 0)
	perror ("open failed\n");
      while ((n = read (fd, buf, 4096)) > 0)
	write (fd2[1], buf, n);

    }
  else
    {
      close (fd1[0]);
      close (fd2[1]);
      gets (buf2);
      n = write (fd1[1], buf2, strlen (buf2));
      while ((n = read (fd2[0], buf3, 4096)) > 0)
	write (1, buf3, n);
    }


}
