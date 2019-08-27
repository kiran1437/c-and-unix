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

  void *attach_addr = shmat (shmid, 0, SHM_RDONLY);

/* BY setting  the last arg to 0, default attach is to read and write. 
   In case you don't have write acces to the shm object, 
   specifying third arg 0 will fail. SO force it to be SHM_RDONLY.
*/

  if ((int) attach_addr == -1)
    {
      printf ("Errno = %d\n", errno);
      exit (1);
    }

/* Error if addr == -1 (FFFFFFFF). But FFFFFFFF is a valid address 
   in 32 bit addr space.  On Intel platform FFFFFFFF is in the ROM area.
   So the possiblity of attaching at actual address FFFFFFFF doesn't exist.

*/
  struct sembuf sembuf_array[2];
  int semid = semget (ftok ("semprj", 16), 0, 0);
  if (semid == -1) { printf ("semget errno = %d\n", errno); exit (1); }
  int i;
  

for(i=0;i<15; i++)
  { 
   /* wait on s1*/
  memset (&sembuf_array, 0, sizeof (sembuf_array));
  sembuf_array[0].sem_num = 1;
  sembuf_array[0].sem_op = -1;
  int ret = semop (semid, sembuf_array, 1);
  if (ret == -1) { printf ("semop errno = %d\n", errno); exit (1); }


  printf ("%s\n", attach_addr);
  sleep(3);

   /* signal on s0*/
  memset (&sembuf_array, 0, sizeof (sembuf_array));
  sembuf_array[0].sem_num = 0;
  sembuf_array[0].sem_op = 1;
  ret = semop (semid, sembuf_array, 1);
  if (ret == -1) { printf ("semop errno = %d\n", errno); exit (1); }

}
}

