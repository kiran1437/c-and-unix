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

  struct shmid_ds shmattr;

  int ret = shmctl (shmid, IPC_STAT, &shmattr);

  printf ("shmctl returned %x\n", ret);
  if (ret == -1)
    {
      printf ("Errno = %d\n", errno);
      exit (1);
    }

  printf ("perm:%o, size=%d, # of attaches=%d\n",
	  shmattr.shm_perm.mode, shmattr.shm_segsz, shmattr.shm_nattch);

  printf ("uid=%d, gid= %d cuid=%d, cgid=%d seqnum=%d\n",
	  shmattr.shm_perm.uid, shmattr.shm_perm.gid,
	  shmattr.shm_perm.cuid, shmattr.shm_perm.cgid,
	  shmattr.shm_perm.__seq);

/*memset(&shmattr, 0, sizeof(shmattr)); */
  shmattr.shm_perm.mode = 0507;

  ret = shmctl (shmid, IPC_SET, &shmattr);

  printf ("shmctl returned %x\n", ret);
  if (ret == -1)
    {
      printf ("Errno = %d\n", errno);
      exit (1);
    }

  printf ("perm:%o, size=%d, # of attaches=%d\n",
	  shmattr.shm_perm.mode, shmattr.shm_segsz, shmattr.shm_nattch);
/* 
            struct shmid_ds {
                 struct    ipc_perm shm_perm;   operation perms 
                 int  shm_segsz;           size of segment (bytes) 
                 time_t    shm_atime;           last attach time 
                 time_t    shm_dtime;           last detach time 
                 time_t    shm_ctime;           last change time 
                 unsigned short shm_cpid;  pid of creator 
                 unsigned short shm_lpid;  pid of last operator 
                 short     shm_nattch;          no. of current attaches 
            };
                                                                                
            struct ipc_perm {
              key_t  key;
              ushort uid;    owner euid and egid 
              ushort gid;
              ushort cuid;   creator euid and egid 
              ushort cgid;
              ushort mode;   lower 9 bits of shmflg 
              ushort seq;    sequence number 
            };
*/
}
