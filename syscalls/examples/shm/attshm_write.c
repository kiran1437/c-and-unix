#include <sys/ipc.h>

#include <sys/shm.h>
#include <sys/stat.h>

#include<errno.h>
extern int errno;
main ()
{

  key_t k = ftok ("shmprj", 48);

  printf ("Key obtained is %x\n", k);
  if (k == -1)
    {
      printf ("Errno = %d\n", errno);
      exit (1);
    }

  int shmid = shmget (k, 0, 0);

  printf ("Shm identifier is %x\n", shmid);
  if (shmid == -1)
    {
      printf ("Errno = %d\n", errno);
      exit (1);
    }

  void *attach_addr = shmat (shmid, 0, 0);

  printf ("Attached at %x\n", attach_addr);
  if (attach_addr == -1)
    {
      printf ("Errno = %d\n", errno);
      exit (1);
    }

  strcpy (attach_addr, "Hello world");


}
