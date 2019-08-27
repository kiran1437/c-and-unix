#include <sys/ipc.h>

#include <sys/shm.h>
#include <sys/stat.h>
       #include <sys/types.h>
       #include <sys/ipc.h>
       #include <sys/sem.h>
 

#include<errno.h>
extern int errno;
main ()
{

  key_t k = ftok ("shmprj", 80);
  if (k == -1)
    {
      printf ("Errno = %d\n", errno);
      exit (1);
    }

  int shmid = shmget (k, 0, 0);
  if (shmid == -1)
    {
      printf ("Errno = %d\n", errno);
      exit (1);
    }

  void *attach_addr = shmat (shmid, 0, 0);
  if ((int) attach_addr == -1)
    {
      printf ("Errno = %d\n", errno);
      exit (1);
    }


  int i;
  for ( i=0; i< 15; i++) 
  { 
    sprintf(attach_addr, "helloworld %d\n", i);
    sleep(2);
  }  /* for loop */
}

