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
  int n;

  if (pipe (fd))
    perror ("pipe failed\n");

  if ((pid = fork ()) < 0)
    perror ("FOrek failed\n");

  if (pid > 0)
    {
      close (fd[1]);
      n = read (fd[0], buf, 4096);
      printf ("PARENT:read %d bytes -%s-\n", n, buf);
    }
  else
    {
      close (fd[0]);
      write (fd[1], "HELLO WORLD Ericsson", 21);
    }
}
