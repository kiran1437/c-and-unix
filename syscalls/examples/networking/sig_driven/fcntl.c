#include<unistd.h>
#include<fcntl.h>

#include<sys/stat.h>
#include<sys/types.h>

#include<errno.h>
extern int errno;
main ()
{
  int ret;
  int fd = open ("/tmp/fcntl_test",
		 O_CREAT | O_WRONLY | O_APPEND,
		 S_IRWXU | S_IRWXO);


  ret = fcntl (fd, F_GETFL, 0);

  printf ("fcntl returned = %d\n", ret);
  if (ret == -1)
    {
      printf ("ret = %d, errno = %d\n", ret, errno);
      exit (1);
    }

/* Following are definitions of O_RDONLY and so on.. 
   in /usr/include/bits/fcntl.h   
#define O_ACCMODE          0003
#define O_RDONLY             00
#define O_WRONLY             01
#define O_RDWR               02

Here O_ACCMODE has the bits of ret, which represent the read, 
write modes of open. So, and with O_ACCMODE to get the open mode bits of 
ret. 
*/

  if ((ret & O_ACCMODE) == O_RDONLY)
    printf ("Readonly\n");

  if ((ret & O_ACCMODE) == O_WRONLY)
    printf ("Write only\n");

  if ((ret & O_ACCMODE) == O_RDWR)
    printf ("Read Write\n");

  if (ret & O_APPEND)
    printf ("Append \n");

  if (ret & O_NONBLOCK)
    printf ("NON BLOCK\n");

}
