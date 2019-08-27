#include<stdio.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int
main (int argc, char **argv)
{


  pid_t pid;
  int status;

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
      wait( &status);

      if (WIFEXITED (status))
	printf ("Child terminated Normally. Status %#x, Exit status %#x.\n", 
                 status, WEXITSTATUS (status));

      if (WIFSIGNALED (status))
	printf ("Child Terminated by signal: Status %#x, Sig no%#x.\n", 
                 status, WTERMSIG (status));
    }

  if (pid == 0)
    {
      printf ("From the CHILD: pid=%d, ppid=%d\n", getpid (), getppid ());
      exit( 20); 
      /* Lets set exit status to 20 for demo purposes. On successful 
      completion this should be set to zero, ideally.  */  
    }
  return 0;
}
