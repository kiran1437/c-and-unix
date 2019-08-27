#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#include<errno.h>
#include<sys/stat.h>

extern int errno;



main ()
{
  struct sembuf sembuf_array[2];
  int semid = semget (ftok ("semprj", 16), 0, 0);

  printf ("setget returned %d\n", semid);
  if (semid == -1)
    {
      printf ("semget errno = %d\n", errno);
      exit (1);
    }


  memset (&sembuf_array, 0, sizeof (sembuf_array));

/* The following fields are gaurantted in sembuf struct.

           unsigned short sem_num;   semaphore number 
           short sem_op;             semaphore operation 
           short sem_flg;            operation flags 
                                                                                

*/

  sembuf_array[0].sem_num = 0;
  sembuf_array[0].sem_op = 1;
  //sembuf_array[0].sem_flg = SEM_UNDO;
  sembuf_array[1].sem_num = 1;
  sembuf_array[1].sem_op = -1;
  sembuf_array[1].sem_flg = SEM_UNDO;

  int ret = semop (semid, sembuf_array, 2);

  printf ("Wait semop returned %d\n", ret);
  if (ret == -1)
    {
      printf ("semop errno = %d\n", errno);
      exit (1);
    }
  sleep(300);
}
