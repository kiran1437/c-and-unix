#include <unistd.h>
#include <linux/types.h>
#include <linux/dirent.h>
#include <linux/unistd.h>

/*struct dirent
        {
         long d_ino;                   inode number 
         off_t d_off;                  offset to next dirent 
         unsigned short d_reclen;     length of this dirent 
         char d_name [NAME_MAX+1];    file name (null-terminated) 
         }
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



main ()
{

  char dirp[4096];

  int fd1, ret;

  if ((fd1 = open ("/home/srini", O_RDONLY)) < 0)
    {
      perror ("Error opening source");
      exit (2);
    }

  ret = getdents (fd1, (struct dirent *) dirp, 4096);

  printf ("%d\n", ret);

}
