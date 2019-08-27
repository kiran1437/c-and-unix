# include <sys/types.h>
# include <sys/ipc.h>
# include <sys/stat.h>
# include <sys/msg.h>

#include<errno.h>
#include<fcntl.h>
extern int errno;
main ()
{

  key_t k = ftok ("msgfile", 45);

  printf ("Key obtained is %x\n", k);
  if (k == -1)
    {
      printf ("Errno = %d\n", errno);
      exit (1);
    }
  int msgid = msgget (k, 0);

  printf ("Mesg identifier is %x\n", msgid);
  if (msgid == -1)
    {
      printf ("Errno = %d\n", errno);
      exit (1);
    }

  struct msqid_ds msgattr;

  memset (&msgattr, 0, sizeof (msgattr));
msgattr.msg_perm.uid=1001; 
msgattr.msg_perm.gid=502; 

  msgattr.msg_perm.mode = 0777;

  int ret = msgctl (msgid, IPC_SET, &msgattr);

  printf ("msgctl returned %x\n", ret);
  if (ret == -1)
    {
      printf ("Errno = %d\n", errno);
      exit (1);
    }

  memset (&msgattr, 0, sizeof (msgattr));
  ret = msgctl (msgid, IPC_STAT, &msgattr);

  printf ("msgctl returned %x\n", ret);
  if (ret == -1)
    {
      printf ("Errno = %d\n", errno);
      exit (1);
    }

  printf ("perm:%o, uid=%d, gid= %d \n",
	  msgattr.msg_perm.mode, msgattr.msg_perm.uid, msgattr.msg_perm.gid);
/*
struct msqid_ds
{
  struct ipc_perm msg_perm;      structure describing operation permission 
  __time_t msg_stime;            time of last msgsnd command 
  __time_t msg_rtime;            time of last msgrcv command 
  __time_t msg_ctime;            time of last change 
  unsigned long int __msg_cbytes;  current number of bytes on queue 
  msgqnum_t msg_qnum;            number of messages currently on queue 
  msglen_t msg_qbytes;           max number of bytes allowed on queue 
  __pid_t msg_lspid;             pid of last msgsnd() 
  __pid_t msg_lrpid;             pid of last msgrcv() 
};



struct ipc_perm
  {
    __key_t __key;                       Key.  
    __uid_t uid;                         Owner's user ID.  
    __gid_t gid;                         Owner's group ID.  
    __uid_t cuid;                        Creator's user ID.  
    __gid_t cgid;                        Creator's group ID.  
    unsigned short int mode;             Read/write permission.  
    unsigned short int __seq;            Sequence number.  
  };

                                                                                
*/



}
