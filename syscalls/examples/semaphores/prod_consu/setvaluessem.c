#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#include<errno.h>
#include<sys/stat.h>

extern int errno;
union semun
{
  int val;
  struct semid_ds *buf;
  ushort *array;
};


main ()
{

  unsigned short sem_values[2] = { 1, 0 };
  union semun ctlun;
  int semid = semget (ftok ("semprj", 16), 0, 0);

  printf ("setget returned %d\n", semid);
  if (semid == -1)
    {
      printf ("semget errno = %d\n", errno);
      exit (1);
    }

  ctlun.array = sem_values;

  int ret = semctl (semid, 0, SETALL, ctlun);
  printf ("setctl returned %d\n", ret);
  if (ret == -1)
    {
      printf ("semctl errno = %d\n", errno);
      exit (1);
    }

}
