# include <sys/types.h>
# include <sys/ipc.h>
# include <sys/stat.h>
# include <sys/msg.h>

#include<errno.h>
#include<fcntl.h>
extern int errno;
main ()
{
  int ret;
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

#include "mymsgbuf.h"
  struct mymsgbuf msgbuf;
  memset (&msgbuf, 0, sizeof (msgbuf));
  ret = msgrcv (msgid, &msgbuf, MTEXTSIZE, 1, 0);
  printf ("msgrcv returned %d\n", ret);
  if (ret == -1)
    {
      printf ("Errno = %d\n", errno);
      exit (1);
    }

  printf ("received msg of type %d\n", msgbuf.mtype);
}
