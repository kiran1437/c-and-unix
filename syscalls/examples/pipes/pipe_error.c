#include<sys/types.h>
#include<unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include<errno.h>
#include<signal.h>

extern int errno;


void
sig (int signo)
{
  printf ("received %d\n", signo);
}


main ()
{

  int fd[2];
  pid_t pid;
  char buf[4096];
  int i, n;
  if (pipe (fd))
    perror ("pipe failed\n");

/* read from a pipe that has no process open for writing returns 0.
   write to a pipe that has no process open for reading returns errno EPIPE
  and a SIGPIPE is generated as well.
*/

  if ((pid = fork ()) < 0)
    perror ("FOrek failed\n");

  if (pid > 0)
    {
      close (fd[1]);
      close (fd[0]);
    }
  else
    {
      close (fd[0]);
      signal (SIGPIPE, sig);
      sleep (2);
      if (write (fd[1], "hello world", 12) >= 0)
	printf ("CHILD: write SUCCESS\n");
      else
	printf ("CHILD: errno = %d\n", errno);
    }
}
