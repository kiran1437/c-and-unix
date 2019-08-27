#include<stdio.h>

#include <sys/types.h>
#include <unistd.h>


int
main (int argc, char **argv)
{


  pid_t pid;

  printf ("This printf is before the call to fork().\n");

  pid = fork ();

  if (pid < 0)
    {
      perror ("fork() failed");
      exit (1);
    }

  if (pid > 0)
    {
      printf ("From the PARENT: pid=%d, ppid=%d childpid= %d\n",
	      getpid (), getppid (), pid);
    }

  if (pid == 0)
    {
      printf ("From the CHILD: pid=%d, ppid=%d\n", getpid (), getppid ());
    }
  return 0;
}
