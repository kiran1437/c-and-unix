#include <sys/ipc.h>

#include <sys/shm.h>
#include <sys/stat.h>

#include<errno.h>
extern int errno;
main ()
{

  key_t k = ftok ("shmprj", 80);

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
  if ((int) attach_addr == -1)
    {
      printf ("Errno = %d\n", errno);
      exit (1);
    }

/* Error if addr == -1 (FFFFFFFF). But FFFFFFFF is a valid address in 32 bit addr space.  On Intel platform FFFFFFFF is in the ROM area.  So the possiblity of attaching at actual address FFFFFFFF doesn't exist.  
*/

  strcpy (attach_addr, "GREAT  ENGS? Good afternoon!! Post launch!! ");


}
