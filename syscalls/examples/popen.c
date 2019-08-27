#include<stdio.h>

/* Following for exit status determination with pclose()*/
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>



main ()
{
  int n, status;
  char buf[100];

  FILE *fp = popen ("ls -l /etc/passwd xyz", "r");
/* second arg can be r or w. Mutually exclusive*/

  while (!feof (fp))
    {
      n = fread (buf, 1, 100, fp);
      write (1, buf, n);
    }

/*  Note: Of the two arguments to ls command xyz does not exist. 
    Should note that stderr can't be captured.
    
     What if you redirect the output of the above command?
     Firstly, A shell process will be created which will execute the 
     above command(/bin/sh).  The stdout of this new process will be captured
     by duping. But when the shell implements redirection stdout is further
     redirected.  So no data will be available on fp.

*/

  status = pclose (fp);
/* This status in the sense of wait4 () system call. This needs to be 
   put through WEXITSTATUS macro to get the actual exit status*/


  printf ("The command exit status is %d.\n", WEXITSTATUS (status));
}
