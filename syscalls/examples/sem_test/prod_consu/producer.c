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
      printf (" 1Errno = %d\n", errno);
      exit (1);
    }

  int shmid = shmget (k, 0, 0);

  if (shmid == -1)
    {
      printf ("2 Errno = %d\n", errno);
      exit (1);
    }

  void *attach_addr = shmat (shmid, 0, 0);

  if ((int) attach_addr == -1)
    {
      printf ("3 Errno = %d\n", errno);
      exit (1);
    }
  struct sembuf sembuf_array[2];
  int semid = semget (ftok ("semprj", 16), 0, 0);

  // printf ("setget returned %d\n", semid); 
   if (semid == -1) { printf ("semget errno = %d\n", errno); exit (1); }

/* Error if addr == -1 (FFFFFFFF). But FFFFFFFF is a valid address 
   in 32 bit addr space.  On Intel platform FFFFFFFF is in the ROM area.
   So the possiblity of attaching at actual address FFFFFFFF doesn't exist.

*/
 int i;
  for ( i=0; i< 15; i++) 
  { 
   /* wait on s0*/
  memset (&sembuf_array, 0, sizeof (sembuf_array));
  sembuf_array[0].sem_num = 1;
  sembuf_array[0].sem_op = -1;
  sembuf_array[0].sem_flg = SEM_UNDO;
  int ret = semop (semid, sembuf_array, 1);
  //printf ("Wait semop returned %d\n", ret);
  if (ret == -1) { printf ("semop errno = %d\n", errno); exit (1); }


    sprintf(attach_addr, "helloworld %d\n", i);

   /* signal on s1*/
  memset (&sembuf_array, 0, sizeof (sembuf_array));
  sembuf_array[0].sem_num = 0;
  sembuf_array[0].sem_op = 1;
  sembuf_array[0].sem_flg = SEM_UNDO;
  ret = semop (semid, sembuf_array, 1);
  //printf ("Wait semop returned %d\n", ret);
  if (ret == -1) { printf ("semop errno = %d\n", errno); exit (1); }

  }  /* for loop */
}

